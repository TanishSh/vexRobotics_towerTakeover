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
  if(move > 0){
    return int(move*move*move/127*127);
  }
  else if (move < 0){
    return int(move*move*move/127*127);
  }
  else{
    return 0;
  }
}
void move(){
    int initial = 0;
     //variables for moving forward and back, and turning
    int power = master.get_analog(pros::controller_analog_e_t::E_CONTROLLER_ANALOG_LEFT_Y);
    int turn = master.get_analog(pros::controller_analog_e_t::E_CONTROLLER_ANALOG_RIGHT_X);
    if(power > assignPower){
      assignPower = assignPower + 10;
    } else if(power < assignPower){
      assignPower = assignPower - 10;
    } else if(turn > assignTurn){
      assignTurn = assignTurn + 10;
    } else if (turn < assignTurn){
      assignTurn = assignTurn - 10;
    }
    else{
      assignPower = assignPower;
      assignTurn = assignTurn;
    }
    power = cubic(assignPower);
    turn = cubic(assignTurn);
    std::cout << turn;
    //assigning the variables to each side of the robot
    int left = assignPower + assignTurn;
    int right = assignPower - assignTurn;
    //having a cubic cruve for the values of the variables
    //cubic(left);
    //cubic(right);
    //initial values for each left and right side motors of the robot
    //assigning values to the motors
    leftFront.move(left);
    leftBack.move(left);
    rightFront.move(right);
    rightBack.move(left);
  }