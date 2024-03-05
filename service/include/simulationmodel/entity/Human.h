#include "IEntity.h"
#include "math/vector3.h"
#include "util/json.h"

#ifndef HUMAN_H
#define HUMAN_H

class Human : public IEntity {
 public:
   /**
   * @brief Constructor
   * @param obj JSON object containing the Human's information
   */
  Human(const JsonObject& details);

  /**
   * @brief Updates the Human's position
   * @param dt Delta time
   */
  void update(double dt);

  /**
   * @brief Removing the copy constructor operator
   * so that drones cannot be copied.
   */
  Human(const Human& drone) = delete;

  /**
   * @brief Removing the assignment operator
   * so that drones cannot be copied.
   */
  Human& operator=(const Human& drone) = delete;

 private:
    bool b_targetDestination = false;
};

#endif  // HUMAN_H
