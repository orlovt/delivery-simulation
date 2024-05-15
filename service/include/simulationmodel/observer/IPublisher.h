#ifndef IPUBLISHER_H_
#define IPUBLISHER_H_

#include <set>
#include <string>

#include "IObserver.h"

/**
 * @brief The IPublisher class is an interface for objects that can publish
 * events to observers. This interface defines methods for adding and removing
 * observers, as well as notifying observers of changes in the published entity.
 */
class IPublisher {
 public:
  /**
   * @brief Adds an observer to the list of subscribers.
   * @param observer A pointer to the observer object to be added.
   */
  void addObserver(const IObserver* o);
  /**
   * @brief Removes an observer from the list of subscribers.
   * @param observer A pointer to the observer object to be removed.
   */
  void removeObserver(const IObserver* o);
  /**
   * @brief Notifies all observers with the message.
   * @param message The message to send to all observers.
   */
  void notifyObservers(const std::string& message) const;

 private:
  std::set<const IObserver*> observers;
};

#endif  // IPUBLISHER_H_
