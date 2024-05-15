#ifndef HUMAN_H_
#define HUMAN_H_

#include "IEntity.h"
#include "IStrategy.h"

class Human : public IEntity {
 public:
  /**
   * @brief Drones are created with a name
   * @param obj JSON object containing the drone's information
   */
  Human(const JsonObject& obj);

  /**
   * @brief Default destructor
   */
  ~Human();

  /**
   * @brief Updates the human's position
   * @param dt Delta time
   */
  void update(double dt);

  /**
   * @brief provides a csv representation of the human
   * @return std::string representing the attributes of the human in csv format
   */
  std::string tocsv() const;

 private:
  static Vector3 kellerPosition;
  IStrategy* movement = nullptr;
  bool atKeller = false;
};

#endif
