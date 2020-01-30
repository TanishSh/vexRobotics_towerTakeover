/*
Made by: TanishSh 29/01/2020
*/
#include "main.h"
#include "globals.hpp"
//motors
//drive motors
pros::Motor leftFront(1,MOTOR_GEARSET_18,false,MOTOR_ENCODER_COUNTS);
pros::Motor leftBack(19,MOTOR_GEARSET_18,false,MOTOR_ENCODER_COUNTS);
pros::Motor rightFront(11,MOTOR_GEARSET_18,true,MOTOR_ENCODER_COUNTS);
pros::Motor rightBack(20,MOTOR_GEARSET_18,true,MOTOR_ENCODER_COUNTS);
// intake motors
pros::Motor leftIntake(5,MOTOR_GEARSET_18, true,MOTOR_ENCODER_COUNTS);
pros::Motor rightIntake(8,MOTOR_GEARSET_18, false,MOTOR_ENCODER_COUNTS);
// arm motor
pros::Motor arm(1, MOTOR_GEARSET_18, false, MOTOR_ENCODER_COUNTS);
// angleAdjuster motor
pros::Motor tilter(6,MOTOR_GEARSET_36, false,MOTOR_ENCODER_COUNTS);
//controller
pros::Controller master(CONTROLLER_MASTER);
pros::ADIGyro gyro(11);
