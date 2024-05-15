#ifndef PORCH_PIRATE_H_
#define PORCH_PIRATE_H_

#include "IEntity.h"
#include "IPackageObserver.h"
#include "IStrategy.h"
#include "math/vector3.h"
#include "util/json.h"

class PorchPirate : public IEntity, public IPackageObserver {
 public:
  /**
   * @brief Construct a PorchPirate with initial configuration from a JSON
   * object.
   * @param obj JSON object containing the configuration for the PorchPirate.
   */
  PorchPirate(const JsonObject& obj);

  /**
   * @brief Destructor for PorchPirate.
   */
  virtual ~PorchPirate();

  /**
   * @brief Notify method overridden from IPackageObserver.
   * @param package Package to be notified about.
   * @param update PackageUpdateType to be notified about.
   */
  virtual void notifyPackage(Package* package, PackageUpdate update);

  /**
   * @brief Update method to handle PorchPirate specific behavior.
   * @param dt Time step to update the state.
   */
  void update(double dt) override;

  /**
   * @brief provides a csv representation of the porch pirate
   * @return std::string representing the attributes of the porch pirate in csv
   * format
   */
  std::string tocsv() const;

 private:
  static Vector3 caribbianPosition;
  IStrategy* movement = nullptr;
  Package* target = nullptr;
  bool targetCollected = false;
  double maxDistance = 500.0;
  int numStolen = 0;
};

#endif  // PORCH_PIRATE_H_
