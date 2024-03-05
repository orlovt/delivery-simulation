#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

#ifndef HELICOPTER_H
#define HELICOPTER_H

class Helicopter : public IEntity {
 public:
   /**
   * @brief Constructor
   * @param obj JSON object containing the Helicopter's information
   */
  Helicopter(const JsonObject& details);

  /**
   * @brief Updates the Helicopter's position
   * @param dt Delta time
   */
  void update(double dt);

  /**
   * @brief Removing the copy constructor operator
   * so that drones cannot be copied.
   */
  Helicopter(const Helicopter& drone) = delete;

  /**
   * @brief Removing the assignment operator
   * so that drones cannot be copied.
   */
  Helicopter& operator=(const Helicopter& drone) = delete;

 private:
  Vector3 destination;
  void generateNewDestination();
};

#endif
