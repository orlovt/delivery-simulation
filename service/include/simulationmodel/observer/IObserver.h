#ifndef IOBSERVER_H_
#define IOBSERVER_H_

#include <string>

/**
 * @brief The IObserver class is an interface for observers.
 * This class defines the interface that observers must implement in order to
 * receive notifications.
 */
class IObserver {
 public:
  /**
   * @brief Notifies the observer with a message.
   * @param message The message to be notified.
   */
  virtual void notify(const std::string &message) const = 0;
};

#endif  // IOBSERVER_H_
