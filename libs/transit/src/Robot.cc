#include "Robot.h"

Robot::Robot() {}

Robot::Robot(JsonObject& obj) : IEntity(obj) {}

void Robot::update(double dt) {}

void Robot::receive(Package* p) { package = p; }

Package* Robot::getPackage() { return package; }