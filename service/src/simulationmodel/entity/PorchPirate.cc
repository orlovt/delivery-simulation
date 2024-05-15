#define _USE_MATH_DEFINES
#include "PorchPirate.h"

#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include "AstarStrategy.h"
#include "SimulationModel.h"


Vector3 PorchPirate::caribbianPosition(-535, 255, 255);

PorchPirate::PorchPirate(const JsonObject& obj) : IEntity(obj) {}

PorchPirate::~PorchPirate() {
    if (movement) delete movement;
}

void PorchPirate::notifyPackage(Package *package, PackageUpdate packageUpdate) {
  if (packageUpdate == PackageUpdate::DELIVERED) {
    if (!target && (package->getPosition().dist(position) <= maxDistance)) {
      // Set target package
      target = package;
      // Stop any movement
      if (movement) delete movement;
      movement = nullptr;
    }
  }
}

void PorchPirate::update(double dt) {
  if (target && !targetCollected) {
    // Walk to target package
    if (!movement) {
      movement = new AstarStrategy(position,
        target->getDestination(), model->getGraph());
    } else if (!movement->isCompleted()) {
      movement->move(this, dt);
    } else {
      // Attempt to steal
      if (target->stealDelivery()) {
        targetCollected = true;
        std::stringstream ss;
        ss << name << " is stealing " << target->getName() << "!";
        notifyObservers(ss.str());
      } else {
        target = nullptr;
      }
      delete movement;
      movement = nullptr;
    }
  } else if (targetCollected) {
    // Bring target package to caribbean
    if (!movement) {
      movement = new AstarStrategy(position, caribbianPosition,
        model->getGraph());
    } else if (!movement->isCompleted()) {
      movement->move(this, dt);
      target->setPosition(position);
    } else {
      // Drop off stolen package
      target = nullptr;
      targetCollected = false;
      delete movement;
      movement = nullptr;
      // Notify packages stolen
      numStolen++;
      std::stringstream ss;
      ss << name << " has now stolen " << numStolen << " package(s)";
      notifyObservers(ss.str());
    }
  } else {
    if (movement && !movement->isCompleted()) {
      movement->move(this, dt);
    } else {
      if (movement) delete movement;
      movement = nullptr;
      Vector3 pos;
      pos.x = ((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400;
      pos.y = 254;
      pos.z = ((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400;
      movement = new AstarStrategy(position, pos, model->getGraph());
    }
  }
}

std::string PorchPirate::tocsv() const {
  std::ostringstream stream;
  stream << getId() << ',' << position.x << ',' << position.y << ','
         << position.z << ',' << direction.x << ',' << direction.y << ','
         << direction.z << ',' << getSpeed();
  return stream.str();
}
