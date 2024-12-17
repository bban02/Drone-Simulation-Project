#include "RobotDecorator.h"

#include <iostream>

#include "IEntity.h"

RobotDecorator::RobotDecorator(Robot* robot)
    : Robot(*(new JsonObject(robot->getDetails().getObject()))) {
  this->robot = robot;
  wallet = new Wallet();
}

RobotDecorator::~RobotDecorator() {}

void RobotDecorator::update(double dt) {}

void RobotDecorator::decision(Package* p) {
  int cost = 10;  // arbitrary cost of premium
  int amount = wallet->getTotal();
  bool error;
  int decision = rand() % 2;
  std::cout << "speedy: " << decision << std::endl;
  if (decision == 0) {
    // chose not to use premium
  } else {
    if (amount - cost > 0) {
      p->speedyDelivery = true;
      error = wallet->reduceTotal(cost);
    } else {
      // does nothing since cost failed
    }
  }
}