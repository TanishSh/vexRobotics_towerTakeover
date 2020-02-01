
#include "auton.h"
#include "main.h"
#include "globals.hpp"
#include "intake.h"
#include "tilter.h"
#include "arm.h"

/*
void rotateCW(double goal) {
    while (goal < gyro.get_value()) {
        leftFront.move(127);
        leftBack.move(127);
        rightFront.move(-127);
        rightBack.move(-127);
        pros::delay(10);
    }
}

void rotateCCW(double goal) {
    while (goal < gyro.get_value()) {
        leftFront.move(-127);
        leftBack.move(-127);
        rightFront.move(127);
        rightBack.move(127);
        pros::delay(10);
    }
}

void autonTest() {
    forward(12, 127);
    rotateCCW(90);
    rotateCW(90);
}

void blueRow() {
    //intakeON(90);
    forward(40, 88);
    pros::delay(1000);
    rotateCCW(158);
    pros::delay(1000);
    forward(43.86, 88);
    pros::delay(1000);
    intakeON(-50);
    tilter.move_relative(666, 90);
    pros::delay(2000);
    forward(-10, 50);
}

void blueTower() {
    
}

void redRow() {
    //intakeON(90);
    forward(40, 88);
    pros::delay(1000);
    rotateCW(158);
    pros::delay(1000);
    forward(43.86, 88);
    pros::delay(1000);
    //intakeON(-50);
    tilter.move_relative(666, 90);
    pros::delay(2000);
    forward(-10, 50);
}

void redTower() {

}
*/
void forward(double distance, int speed)  {
    double toMove = distanceCalc(distance);
    leftFront.move_relative(toMove, speed);
    leftBack.move_relative(toMove, speed);
    rightFront.move_relative(toMove, speed);
    rightBack.move_relative(toMove, speed);
}

void oneCube() {
    forward(11, 80);
    forward(-10, 80);
    tilterForward(90);
    pros::delay(3000);
    tilterBackward(50);
    pros::delay(2000);
    tilterOFF();
}

double distanceCalc(double input) {
    return (input / 12.56) * 900;
}

