
#include "main.h"
#include "globals.hpp"
#include "intake.h"

/*
//previous tilter code commented if we need to reference to use it in the future
void intakeMove(int power) {
  leftIntake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  rightIntake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  leftIntake.move(-power);
  rightIntake.move(-power);
}

void setIntake(){
  int intakePower = 100 * (master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R1) - master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R2));
  intakeMove(intakePower);
} */

void intakeSetup(){
    leftIntake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    rightIntake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
void intakeIntake(int speed){
    intakeSetup();
    leftIntake.move(speed);
    rightIntake.move(speed);
}
void intakeOutake(int speed){
  intakeSetup();
  leftIntake.move(-speed);
  rightIntake.move(-speed);
}
void intakeOFF(){
  leftIntake.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  rightIntake.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
  leftIntake.move_velocity(0);
  rightIntake.move_velocity(0);
}
void intakeMove(){
  if (master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_B)){
    intakeIntake(127);
  } else if (master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_X)){
    intakeOutake(127);
  }
  else{
    intakeOFF();
  }
}