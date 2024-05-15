#include "IPackagePublisher.h"

void IPackagePublisher::addPackageObserver(IPackageObserver* po) {
  observers.insert(po); }

void IPackagePublisher::removePackageObserver(IPackageObserver* po) {
  observers.erase(po); }

void IPackagePublisher::notifyPackageObservers(
  Package* p, PackageUpdate update) {
  for (auto& o : observers) o->notifyPackage(p, update);
}
