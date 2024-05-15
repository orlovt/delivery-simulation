#include "PorchPirateFactory.h"

IEntity* PorchPirateFactory::createEntity(const JsonObject& entity) {
  std::string type = entity["type"];

  if (type.compare("porchpirate") == 0) {
    std::cout << "PorchPirate Created" << std::endl;

    Vector3 pos;
    pos.x = ((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400;
    pos.y = 254;
    pos.z = ((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400;

    PorchPirate* p = new PorchPirate(entity);
    p->setPosition(pos);
    return p;
  }
  return nullptr;
}
