#ifndef PORCH_PIRATE_FACTORY_H_
#define PORCH_PIRATE_FACTORY_H_

#include <vector>
#include "PorchPirate.h"
#include "IEntityFactory.h"

/**
 *@brief PorchPirate Factory to produce PorchPirate class.
 **/
class PorchPirateFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for PorchPirateFactory class.
   **/
  virtual ~PorchPirateFactory() {}

  /**
   * @brief Creates a PorchPirate entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new PorchPirate.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* createEntity(const JsonObject& entity);
};

#endif  // PORCH_PIRATE_FACTORY_H_
