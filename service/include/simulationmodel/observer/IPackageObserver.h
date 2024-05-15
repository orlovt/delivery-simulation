#ifndef IPACKAGE_OBSERVER_H_
#define IPACKAGE_OBSERVER_H_

class Package;

/**
 * @brief enum class representing package status updates
 */
enum PackageUpdate { DELIVERED, RECEIVED };

/**
 * @brief The IPackageObserver class is an interface for package observers.
 * This class defines the interface that observers must implement in order to
 * receive notifications.
 */
class IPackageObserver {
 public:
  /**
   * @brief Notifies the observer with a message.
   * @param message The message to be notified.
   */
  virtual void notifyPackage(Package* p, PackageUpdate update) = 0;
};

#endif  // IPACKAGE_OBSERVER_H_
