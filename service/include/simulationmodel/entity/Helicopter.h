#ifndef Helicopter_H_
#define Helicopter_H_

#include "IEntity.h"
#include "IStrategy.h"

class Helicopter : public IEntity {
 public:
  /**
   * @brief Helicopter are created with a name
   * @param obj JSON object containing the drone's information
   */
  Helicopter(const JsonObject& obj);

  /**
   * @brief Default destructor
   */
  ~Helicopter();

  /**
   * @brief Updates the helicopter's position
   * @param dt Delta time
   */
  void update(double dt);

  /**
   * @brief provides a csv representation of the helicopter
   * @return std::string representing the attributes of the helicopter in csv
   * format
   */
  std::string tocsv() const;

 private:
  IStrategy* movement = nullptr;
  double distanceTraveled = 0;
  unsigned int mileCounter = 0;
  Vector3 lastPosition;
};

#endif
