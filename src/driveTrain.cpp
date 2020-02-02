#include "main.h"
#include "globals.hpp"
#include "drive.h"

int assignPower = 0;
int assignTurn = 0;

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

//cubic function
int cubic(int move){
  return int(move*move*move/127*127);
}

int slewRateForward(int value, int initial){
    if(value > initial){
      return initial = initial + 19;
    }else if (value < initial){
      return initial = initial - 19;
    }
    else{
      return initial = initial;
    }
}

int slewRateTurn(int value, int initial){
   if(value > initial){
      return initial = initial + 5;
    }else if (value < initial){
      return initial = initial - 5;
    }
    else{
      return initial = initial;
    }
}
void move(){
     //variables for moving forward and back, and turning
    int power = master.get_analog(pros::controller_analog_e_t::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = master.get_analog(pros::controller_analog_e_t::E_CONTROLLER_ANALOG_RIGHT_X);
    assignPower = slewRateForward(power, assignPower);
    assignTurn = slewRateTurn(turn, assignTurn);
    //assigning the variables to each side of the robot
    int left = power + turn;
    int right = power - turn;
    //having a cubic cruve for the values of the variables
    //resulting in less initial speed but more control
    left = cubic(left);
    right = cubic(right);
    //initial values for each left and right side motors of the robot
    //assigning values to the motors
    leftFront.move(left);
    leftBack.move(left);
    rightFront.move(right);
    rightBack.move(right);
    //debug
    pros::lcd::print(2, "assign power: %d", assignPower);
    pros::lcd::print(3, "assign turn: %d", assignTurn);
    pros::lcd::print(4, "left side motors val: %d", left);
    pros::lcd::print(5, "right side motors val: %d", right);
  }