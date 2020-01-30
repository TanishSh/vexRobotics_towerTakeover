/*
Made by: TanishSh 29/01/2020
*/
#ifndef GLOBALS_HPP
#define GLOBALS_HPP
#include "main.h"
//drive motors
extern pros::Motor leftFront;
extern pros::Motor leftBack;
extern pros::Motor rightFront;
extern pros::Motor rightBack;
//intake motors
extern pros::Motor leftIntake;
extern pros::Motor rightIntake;
//arm motor
extern pros::Motor arm;
//angle adjuster motor
extern pros::Motor tilter;
//controller
extern pros::Controller master;

extern pros::ADIGyro gyro;

#endif //GLOBALS_H
