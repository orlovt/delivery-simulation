#ifndef I_STRATEGY_H_
#define I_STRATEGY_H_

#include "IEntity.h"

/**
 * @brief Strategy interface
 *
 */
class IStrategy {
 public:
  virtual ~IStrategy() {}
  /**
   * @brief Move toward next position
   * @param entity Entity to move
   * @param dt Delta Time
   */
  virtual void move(IEntity* entity, double dt) = 0;

  /**
   * @brief Check if the trip is completed
   * @return True if complete, false if not complete
   */
  virtual bool isCompleted() = 0;
};

#endif
