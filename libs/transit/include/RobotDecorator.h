#ifndef ROBOTDECORATOR_H_
#define ROBOTDECORATOR_H_

#include "IEntity.h"  //could be Ientity?
#include "Package.h"
#include "Robot.h"
#include "Wallet.h"

/**
 * @class RobotDecorator
 * @brief Represents a decorator for the Robot class.
 *
 * RobotDecorator extends the functionality of the Robot class
 * by adding features like a Wallet and additional decision-making logic.
 */
class RobotDecorator : public Robot {
 protected:
  Robot* robot = nullptr;
  Wallet* wallet = nullptr;

 public:
  /**
   * @brief Constructor for RobotDecorator.
   * @param robot Pointer to the base Robot object.
   */
  RobotDecorator(Robot* robot);

  /**
   * @brief Destructor for RobotDecorator.
   */
  ~RobotDecorator();

  /**
   * @brief Updates the RobotDecorator.
   * @param dt Difference in time since the last update.
   */
  void update(double dt);

  /**
   * @brief Additional decision-making logic for the robot.
   * @param p Pointer to the Package for decision-making.
   */
  void decision(Package* p);
};

#endif  // RobotDecorator