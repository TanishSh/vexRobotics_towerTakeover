
#include "auton.h"
#include "main.h"
#include "globals.hpp"
#include "intake.h"
#include "tilter.h"
#include "arm.h"

void resetDriveEncoders(){
    leftFront.tare_position();
    leftBack.tare_position();
    rightFront.tare_position();
    rightBack.tare_position();
}
void move(double distance, int speed)  {
    double toMove = distanceCalc(distance);
    pros::lcd::print(6, "no. of encoder ticks to move: ", toMove);
    pros::lcd::print(7, "distance in inches: ", distance);
    leftFront.move_absolute(toMove, speed);
    leftBack.move_absolute(toMove, speed);
    rightFront.move_absolute(toMove, speed);
    rightBack.move_absolute(toMove, speed);
}

void oneCube() {
    resetDriveEncoders();
    move(11, 80);
    pros::delay(1500);
    move(-30,90);
    pros::delay(1500);
    tilter.move_absolute(2700, 60);
    pros::delay(1500);
    tilter.move_absolute(2700, 60);  
}

void blueFourCube() {
    resetDriveEncoders();
    intakeIntake(200);
    move(102, 80);
    pros::delay(500);
}

void rotateCW(double goal) {
    while (goal < gyro.get_value()) {
        leftFront.move(127);
        leftBack.move(127);
        rightFront.move(-127);
        rightBack.move(-127);
    }
}

void rotateCCW(double goal) {
    while (goal < gyro.get_value()) {
        leftFront.move(-127);
        leftBack.move(-127);
        rightFront.move(127);
        rightBack.move(127);
    }
}

double distanceCalc(double input) {
    return (input / 12.5664) * 900;
}

/*
void translate(int units, int voltage){
    resetDriveEncoders();
    while(leftFront.get_position() < units){
        setDrive(voltage, voltage);
        pros::delay(10);
    }
}
*/


