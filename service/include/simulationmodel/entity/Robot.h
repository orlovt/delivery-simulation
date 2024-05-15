#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

#include "IEntity.h"
#include "IObserver.h"
#include "IStrategy.h"
#include "Package.h"
#include "math/vector3.h"
#include "util/json.h"
#include "vector3.h"

/**
 * @class Robot
 * @brief Represents a robot in a physical system
 *
 * Robots move using euler integration based on a specified
 * velocity and direction.
 */
class Robot : public IEntity, public IPackageObserver {
 public:
  /**
   * @brief Constructor
   * @param obj JSON object containing the robot's information
   */
  Robot(const JsonObject& obj);

  /**
   * @brief Destructor for Robot.
   */
  virtual ~Robot();

  /**
   * @brief Updates the Package
   * @param dt difference in time since last update
   */
  void update(double dt);

  /**
   * @brief Notify method overridden from IPackageObserver.
   * @param package Package to be notified about.
   * @param update PackageUpdateType to be notified about.
   */
  virtual void notifyPackage(Package* package, PackageUpdate update);

  bool requestedDelivery = true;

  /**
   * @brief provides a csv representation of the robot
   * @return std::string representing the attributes of the robot in csv
   * format
   */
  std::string tocsv() const;

 protected:
  Package* package = nullptr;

 private:
  IStrategy* movement = nullptr;
};

#endif  // ROBOT_H
