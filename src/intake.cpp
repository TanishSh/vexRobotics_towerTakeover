#include "main.h"
#include "globals.hpp"
#include "intake.h"

void intakeON() {
  leftIntake.set_brake_mode(MOTOR_BRAKE_HOLD);
  rightIntake.set_brake_mode(MOTOR_BRAKE_HOLD);
  leftIntake.move(-127);
  rightIntake.move(-127);
}

void intakeOFF() {
  leftIntake.set_brake_mode(MOTOR_BRAKE_HOLD);
  rightIntake.set_brake_mode(MOTOR_BRAKE_HOLD);
  leftIntake.move(0);
  rightIntake.move(0);
}
