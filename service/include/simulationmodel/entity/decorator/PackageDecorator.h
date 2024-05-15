#ifndef PACKAGE_DECORATOR_H_
#define PACKAGE_DECORATOR_H_

#include "IEntityDecorator.h"
#include "Package.h"
#include "Robot.h"

class PackageDecorator : public IEntityDecorator<Package> {
 public:
  PackageDecorator(Package* p) : IEntityDecorator(p) {}
  virtual Vector3 getDestination() const { return sub->getDestination(); }
  virtual std::string getStrategyName() const { return sub->getStrategyName(); }
  virtual Robot* getOwner() const { return sub->getOwner(); }
  virtual bool requiresDelivery() const { return sub->requiresDelivery(); }
  virtual void setStrategyName(std::string strategyName_) {
    return sub->setStrategyName(strategyName_);
  }
  virtual void initDelivery(Robot* owner) { return sub->initDelivery(owner); }
};

#endif
