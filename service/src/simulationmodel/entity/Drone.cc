#define _USE_MATH_DEFINES
#include "Drone.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "BfsStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "JumpDecorator.h"
#include "Package.h"
#include "SimulationModel.h"
#include "SpinDecorator.h"

Drone::Drone(const JsonObject& obj) : IEntity(obj) {
  available = true;
  CompositeLogger::getInstance()->log(LogLevel::INFO, *this);
}

Drone::~Drone() {
  if (toPackage) delete toPackage;
  if (toFinalDestination) delete toFinalDestination;
  CompositeLogger::getInstance()->log(LogLevel::INFO, *this);
}

void Drone::getNextDelivery() {
  if (model && model->scheduledDeliveries.size() > 0) {
    package = model->scheduledDeliveries.front();
    model->scheduledDeliveries.pop_front();

    if (package) {
      std::string message = getName() + " heading to: " + package->getName();
      notifyObservers(message);
      available = false;
      pickedUp = false;

      Vector3 packagePosition = package->getPosition();
      Vector3 finalDestination = package->getDestination();

      toPackage = new BeelineStrategy(position, packagePosition);

      std::string strat = package->getStrategyName();
      if (strat == "astar") {
        toFinalDestination = new JumpDecorator(new AstarStrategy(
            packagePosition, finalDestination, model->getGraph()));
      } else if (strat == "dfs") {
        toFinalDestination =
            new SpinDecorator(new JumpDecorator(new DfsStrategy(
                packagePosition, finalDestination, model->getGraph())));
      } else if (strat == "bfs") {
        toFinalDestination =
            new SpinDecorator(new SpinDecorator(new BfsStrategy(
                packagePosition, finalDestination, model->getGraph())));
      } else if (strat == "dijkstra") {
        toFinalDestination =
            new JumpDecorator(new SpinDecorator(new DijkstraStrategy(
                packagePosition, finalDestination, model->getGraph())));
      } else {
        toFinalDestination =
            new BeelineStrategy(packagePosition, finalDestination);
      }
    }
  }
}

void Drone::update(double dt) {
  if (available) getNextDelivery();

  if (toPackage) {
    toPackage->move(this, dt);

    if (toPackage->isCompleted()) {
      std::string message = getName() + " picked up: " + package->getName();
      notifyObservers(message);
      CompositeLogger::getInstance()->log(LogLevel::INFO, *this);
      delete toPackage;
      toPackage = nullptr;
      pickedUp = true;
    }
  } else if (toFinalDestination) {
    toFinalDestination->move(this, dt);

    if (package && pickedUp) {
      package->setPosition(position);
      package->setDirection(direction);
    }

    if (toFinalDestination->isCompleted()) {
      std::string message = getName() + " dropped off: " + package->getName();
      notifyObservers(message);
      CompositeLogger::getInstance()->log(LogLevel::INFO, *this);
      delete toFinalDestination;
      toFinalDestination = nullptr;
      package->completeDelivery();
      package = nullptr;
      available = true;
      pickedUp = false;
    }
  }
}

std::string Drone::tocsv() const {
  std::ostringstream stream;
  stream << getId() << ',' << position.x << ',' << position.y << ','
         << position.z << ',' << direction.x << ',' << direction.y << ','
         << direction.z << ',' << getSpeed() << ','
         << (available ? "True" : "False") << ','
         << (pickedUp ? "True" : "False") << ','
         << (package ? package->getStrategyName() : "N/A") << ","
         << (package ? std::to_string(package->getId()) : "0");

  return stream.str();
}
