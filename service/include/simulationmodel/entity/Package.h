#ifndef PACKAGE_H
#define PACKAGE_H

#include <vector>

#include "IEntity.h"
#include "IPackagePublisher.h"
#include "math/vector3.h"
#include "util/json.h"

class Robot;

class Package : public IEntity, public IPackagePublisher {
 public:
  /**
   * @brief Constructor
   * @param obj JSON object containing the package's information
   */
  Package(const JsonObject& obj);

  /**
   * @brief Default destructor
   */
  ~Package();

  /**
   * @brief Gets the Package's destination
   * @return The Package's destination
   */
  virtual Vector3 getDestination() const;

  /**
   * @brief Returns the name of the strategy for this package
   *
   * @returns String name of strategy
   */
  virtual std::string getStrategyName() const;

  /**
   * @brief Returns the owner of the package
   *
   * @return pointer to Robot owning the package
   */
  virtual Robot* getOwner() const;

  /**
   * @brief Returns whether or not the package needs to be delivered
   *
   * @return boolean value of the above statement
   */
  virtual bool requiresDelivery() const;

  /**
   * @brief Set the Strategy Name
   *
   * @param strategyName_ Strategy name
   */
  virtual void setStrategyName(std::string strategyName_);

  /**
   * @brief Updates the Package
   *
   * @param dt difference in time since last update
   */
  virtual void update(double dt);

  /**
   * @brief provides a csv representation of the package
   * @return std::string representing the attributes of the package in csv
   * format
   */
  std::string tocsv() const;

  /**
   * @brief Sets the attributes for delivery
   *
   * @param owner Robot for the package to be delivered to
   */
  virtual void initDelivery(Robot* owner);

  /**
   * @brief Sets delivery as complete when package is dropped off
   */
  virtual void completeDelivery();
  /**
   * @brief Sets package as received when owner collects it
   * @return true
   * @return false
   */
  virtual bool receiveDelivery();
  /**
   * @brief Sets package as stolen when a porch pirate stole it
   * @return true
   * @return false
   */
  virtual bool stealDelivery();

  /**
   * @brief Returns whether package was dropped off (delivered) at target
   * location
   * @return true
   * @return false
   */
  virtual bool isDelivered();

  /**
   * @brief Returns whether package was received by owner
   * @return true
   * @return false
   */
  virtual bool isReceived();

  /**
   * @brief Returns whether package was stolen by a porch pirate
   * @return true
   * @return false
   */
  virtual bool isStolen();

 protected:
  bool requiresDelivery_ = true;
  bool delivered_ = false;
  bool received_ = false;
  bool stolen_ = false;
  Vector3 dest;
  std::string strategyName;
  Robot* owner = nullptr;
};

#endif  // PACKAGE_H
