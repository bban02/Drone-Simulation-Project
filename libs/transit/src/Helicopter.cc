#define _USE_MATH_DEFINES
#include "Helicopter.h"

#include <cmath>
#include <limits>

#include "BeelineStrategy.h"

#include "Package.h"
#include "SimulationModel.h"

Helicopter::Helicopter(JsonObject& obj) : IEntity(obj) {
  available = true;
}

Helicopter::~Helicopter() {
  if (toPackageHeli) delete toPackageHeli;
  if (toFinalDestHeli) delete toFinalDestHeli;
}


void Helicopter::getNextDeliveryHeli() {
  if (model && model->scheduledDeliveries.size() > 0) {
    package = model->scheduledDeliveries.front();
    if(package->speedyDelivery) {
      // check new variable to see if drone or helicopter
      model->scheduledDeliveries.pop_front();
    }
    else {
      package = nullptr;
    }
  }
  if (package) {
    available = false;
    pickedUp = false;

    Vector3 packagePosition = package->getPosition();
    Vector3 finalDestHeli = package->getDestination();

    toPackageHeli = new BeelineStrategy(position, packagePosition);

    toFinalDestHeli = new BeelineStrategy(packagePosition, finalDestHeli);
  }
}
 

void Helicopter::update(double dt) {
    if (available) {
      getNextDeliveryHeli();
    }

    if (toPackageHeli) {
      toPackageHeli->move(this, dt);

      if (toPackageHeli->isCompleted()) {
        delete toPackageHeli;
        toPackageHeli = nullptr;
        pickedUp = true;
      }
    } 
    else if (toFinalDestHeli) {
      toFinalDestHeli->move(this, dt);

      if (package && pickedUp) {
        package->setPosition(position);
        package->setDirection(direction);
      }

      if (toFinalDestHeli->isCompleted()) {
        delete toFinalDestHeli;
        toFinalDestHeli = nullptr;
        package->handOff();
        package = nullptr;
        available = true;
        pickedUp = false;
      }
    }
  }
