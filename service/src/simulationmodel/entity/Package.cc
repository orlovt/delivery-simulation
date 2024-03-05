#include "Package.h"

#include "Robot.h"

Package::Package(const JsonObject &obj) : IEntity(obj) {}

Vector3 Package::getDestination() const {
  return destination;
}

std::string Package::getStrategyName() const {
  return strategyName;
}

void Package::setStrategyName(std::string strategyName_) {
  strategyName = strategyName_;
}

void Package::update(double dt) {}

void Package::initDelivery(Robot* owner) {
  this->owner = owner;
  owner->requestedDelivery = false;
  requiresDelivery = false;
  destination = owner->getPosition();
}

void Package::handOff() {
  if (owner) {
    owner->receive(this);
  }
}
