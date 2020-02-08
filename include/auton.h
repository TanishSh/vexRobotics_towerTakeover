
#include "main.h"
#include "tilter.h"
#include "globals.hpp"

#ifndef VEXROBOT_AUTON_H
#define VEXROBOT_AUTON_H

void resetDriveEncoders();
void move(double distance, int speed);
void oneCube();
double distanceCalc(double input);
void rotateCW(double goal);
void rotateCCW(double goal);

#endif //VEXROBOT_AUTON_H
