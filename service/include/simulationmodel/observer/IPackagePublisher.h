#ifndef IPACKAGE_PUBLISHER_H_
#define IPACKAGE_PUBLISHER_H_

#include <set>
#include <string>

#include "IPackageObserver.h"

/**
 * @brief The IPackagePublisher class is an interface for objects that can
 * publish events to observers. This interface defines methods for adding and
 * removing observers, as well as notifying observers of changes in the
 * published entity.
 */
class IPackagePublisher {
 public:
  /**
   * @brief Adds an observer to the list of subscribers.
   * @param po A pointer to the observer object to be added.
   */
  virtual void addPackageObserver(IPackageObserver* po);
  /**
   * @brief Removes an observer from the list of subscribers.
   * @param po A pointer to the observer object to be removed.
   */
  virtual void removePackageObserver(IPackageObserver* po);
  /**
   * @brief Notifies all observers with the message.
   *
   * @param package the package publishing for observers
   * @param update the package status update
   */
  virtual void notifyPackageObservers(Package* package, PackageUpdate update);

 private:
  std::set<IPackageObserver*> observers;
};

#endif  // IPACKAGE_PUBLISHER_H_
