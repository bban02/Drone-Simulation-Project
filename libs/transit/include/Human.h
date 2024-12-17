#ifndef HUMAN_H_
#define HUMAN_H_

#include "IEntity.h"
#include "IStrategy.h"

class Human : public IEntity {
 public:
  /**
   * @brief Drones are created with a name
   *
   * @param obj JSON object containing the drone's information
   */
  Human(JsonObject& obj);
  
  /**
   * @brief Destructor for the Human class.
   */
  ~Human();
 
 /**
   * @brief Updates the state of the Human entity over time.
   *
   * This function is called periodically to update the human's position or perform other
   * necessary updates.
   *
   * @param dt Time elapsed since the last update.
   */
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
