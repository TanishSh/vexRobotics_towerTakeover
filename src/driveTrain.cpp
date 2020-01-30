#include "main.h"
#include "globals.hpp"
#include "drive.h"

//quadratic function
int quadratic(int move){
  if(move > 0){
    return (move*move/127);
  }
  else if (move < 0){
    return -(move*move/127);
  }
  else{
    return 0;
  }
  //return (move<0? -1:1)*move*move/127;
}

void move(){
     //variables for moving forward and back, and turning
    int power = master.get_analog(ANALOG_LEFT_Y);
    int turn = master.get_analog(ANALOG_RIGHT_X);
    //assigning the variables to each side of the robot
    int left = power + turn;
    int right = power - turn;
    //having a quadratic cruve for the values of the variables
    quadratic(left);
    quadratic(right);
    //assigning values to the motors
    leftFront.move(left);
    leftBack.move(left);
    rightFront.move(right);
    rightBack.move(right);
}