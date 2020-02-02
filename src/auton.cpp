
#include "auton.h"
#include "main.h"
#include "globals.hpp"
#include "intake.h"
#include "tilter.h"
#include "arm.h"

void forward(double distance, int speed)  {
    double toMove = distanceCalc(distance);
    leftFront.move_absolute(toMove, speed);
    leftBack.move_absolute(toMove, speed);
    rightFront.move_absolute(toMove, speed);
    rightBack.move_absolute(toMove, speed);
}

void oneCube() {
    forward(-20, 80);
    forward(10, 80);
    pros::delay(1500);
    tilterForward(90);
    pros::delay(3000);
    tilterBackward(70);
    pros::delay(2000);
    tilterOFF();
    forward(-20,90);
}

double distanceCalc(double input) {
    return (input / 12.5664) * 900;
}

