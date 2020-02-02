#ifndef DRIVE_H
#define DRIVE_H

int quadratic(int move);
int cubic(int move);
int slewRateForward(int value, int initial);
int slewRateTurn(int value, int initial);

void move();

#endif