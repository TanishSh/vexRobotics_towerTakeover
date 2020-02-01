#include "main.h"
#include "globals.hpp"
#include "intake.h"

void intakeON(int speed) {
  leftIntake.set_brake_mode(MOTOR_BRAKE_HOLD);
  rightIntake.set_brake_mode(MOTOR_BRAKE_HOLD);
  leftIntake.move(speed);
  rightIntake.move(speed);
}

void intakeOFF() {
  leftIntake.set_brake_mode(MOTOR_BRAKE_HOLD);
  rightIntake.set_brake_mode(MOTOR_BRAKE_HOLD);
  leftIntake.move(0);
  rightIntake.move(0);
}
