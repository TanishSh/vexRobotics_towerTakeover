#include "main.h"
#include "globals.hpp"
//motors
//drive motors
pros::Motor leftFront(3,MOTOR_GEARSET_18,false,MOTOR_ENCODER_COUNTS);
pros::Motor leftBack(11,MOTOR_GEARSET_18,false,MOTOR_ENCODER_COUNTS);
pros::Motor rightFront(12,MOTOR_GEARSET_18,true,MOTOR_ENCODER_COUNTS);
pros::Motor rightBack(2,MOTOR_GEARSET_18,true,MOTOR_ENCODER_COUNTS);
// intake motors
pros::Motor leftIntake(7,MOTOR_GEARSET_18, true,MOTOR_ENCODER_COUNTS);
pros::Motor rightIntake(8,MOTOR_GEARSET_18, false,MOTOR_ENCODER_COUNTS);
// arm motor
pros::Motor arm(5, MOTOR_GEARSET_36, false, MOTOR_ENCODER_COUNTS);
// angleAdjuster motor
pros::Motor tilter(4,MOTOR_GEARSET_36, false,MOTOR_ENCODER_COUNTS);
//controller
pros::Controller master(CONTROLLER_MASTER);
pros::ADIGyro gyro(1);
