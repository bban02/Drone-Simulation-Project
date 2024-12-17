#ifndef Helicopter_H_
#define Helicopter_H_

#include "IEntity.h"
#include "IStrategy.h"

class Package;

class Helicopter : public IEntity {
 public:
  /**
   * @brief Helicopter are created with a name
   * @param obj JSON object containing the drone's information
   */
  Helicopter(JsonObject& obj);

  ~Helicopter();

  void getNextDeliveryHeli();

  void update(double dt);

 private:
  IStrategy* toPackageHeli = nullptr;
  IStrategy* toFinalDestHeli = nullptr;
  Package* package = nullptr;
  bool available = false;
  bool pickedUp = false;
};

#endif
