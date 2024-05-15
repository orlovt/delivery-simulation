#include "Package.h"

#include "CompositeLogger.h"
#include "Robot.h"

Package::Package(const JsonObject& obj) : IEntity(obj) {
  this->details = obj;
  JsonArray des(details["dest"]);
  dest = {des[0], des[1], des[2]};

  CompositeLogger::getInstance()->log(LogLevel::INFO, *this);
}

Package::~Package() {
  CompositeLogger::getInstance()->log(LogLevel::INFO, *this);
}

Vector3 Package::getDestination() const { return dest; }

std::string Package::getStrategyName() const { return strategyName; }

Robot* Package::getOwner() const { return owner; }

bool Package::requiresDelivery() const { return requiresDelivery_; }

void Package::setStrategyName(std::string strategyName_) {
  strategyName = strategyName_;
}

void Package::update(double dt) {}

void Package::initDelivery(Robot* owner) {
  this->owner = owner;
  owner->requestedDelivery = false;
  requiresDelivery_ = false;
}

void Package::completeDelivery() {
  delivered_ = true;
  notifyPackageObservers(this, PackageUpdate::DELIVERED);
  CompositeLogger::getInstance()->log(LogLevel::INFO, *this);
}

bool Package::receiveDelivery() {
  if (delivered_ && !(received_ || stolen_)) {
    received_ = true;
    CompositeLogger::getInstance()->log(LogLevel::INFO, *this);
    return true;
  }
  CompositeLogger::getInstance()->log(LogLevel::INFO, *this);
  return false;
}

std::string Package::tocsv() const {
  std::ostringstream stream;
  stream << getId() << ',' << position.x << ',' << position.y << ','
         << position.z << ',' << direction.x << ',' << direction.y << ','
         << direction.z << ',' << getSpeed() << ',' << getDestination().x << ','
         << getDestination().y << ',' << getDestination().z << ','
         << (requiresDelivery_ ? "True" : "False") << ',' << strategyName
         << ", " << (delivered_ ? "True" : "False") << ','
         << (received_ ? "True" : "False") << ','
         << (stolen_ ? "True" : "False");
  return stream.str();
}

bool Package::stealDelivery() {
  if (delivered_ && !(received_ || stolen_)) {
    stolen_ = true;
    return true;
    CompositeLogger::getInstance()->log(LogLevel::INFO, *this);
  }
  return false;
}

bool Package::isDelivered() { return delivered_; }

bool Package::isReceived() { return received_; }

bool Package::isStolen() { return stolen_; }
