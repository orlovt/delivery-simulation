#define _USE_MATH_DEFINES
#include "Robot.h"

#include <cmath>
#include <limits>
#include <sstream>
#include "AstarStrategy.h"
#include "SimulationModel.h"


Robot::Robot(const JsonObject& obj) : IEntity(obj) {}

Robot::~Robot() {
    if (movement) delete movement;
}

void Robot::update(double dt) {
  if (package) {
    if (!movement) {
      movement = new AstarStrategy(position,
        package->getDestination(), model->getGraph());
    } else if (!movement->isCompleted()) {
      movement->move(this, dt);
    } else {
      // Attempt to receive package
      std::stringstream ss;
      if (package->receiveDelivery()) {
        ss << name << " received " << package->getName() << "!";
      } else if (package->isStolen()) {
        ss << name << " cannot find "
          << package->getName() << "! It was stolen.";
      }
      notifyObservers(ss.str());
      package = nullptr;
    }
  }
}

void Robot::notifyPackage(Package* p, PackageUpdate u) {
  if (u == PackageUpdate::DELIVERED) {
    package = p;
  }
}

std::string Robot::tocsv() const {
  std::ostringstream stream;
  stream << getId() << ',' << position.x << ',' << position.y << ','
         << position.z << ',' << direction.x << ',' << direction.y << ','
         << direction.z << ',' << getSpeed();
  return stream.str();
}
