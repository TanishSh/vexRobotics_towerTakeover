
#include "auton.h"
#include "main.h"
#include "globals.hpp"

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

void forward(double distance)  {
    while (distanceCalc(distance) < distanceCalc(leftFront.get_position())) {
        leftFront.move(127);
        leftBack.move(127);
        rightFront.move(127);
        rightBack.move(127);
        pros::delay(20);
    }
}

void reverse(double distance) {
    while (distanceCalc(distance) < distanceCalc(leftFront.get_position())) {
        leftFront.move(-127);
        leftBack.move(-127);
        rightFront.move(-127);
        rightBack.move(-127);
        pros::delay(20);
    }
}

void autonTest() {
    forward(12);
    reverse(12);
    rotateCCW(90);
    rotateCW(90);
}

void blueRow() {
    forward(40);

    rotateCCW(158);
    forward(43.86);
}

double distanceCalc(double input) {
    return (input / 12.56) * 900;
}