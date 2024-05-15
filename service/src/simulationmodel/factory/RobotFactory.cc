#include "RobotFactory.h"
#include <random>
#include <cmath>
#include <limits>

IEntity* RobotFactory::createEntity(const JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("robot") == 0) {
    std::cout << "Robot Created" << std::endl;
    Vector3 dest;
    dest.x = ((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400;
    dest.y = 254;
    dest.z = ((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400;
    Robot *rob = new Robot(entity);
    rob -> setPosition(dest);
    return rob;
  }
  return nullptr;
}
