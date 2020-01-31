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

//cubic function
int cubic(int move){
  if(move > 0){
    return(move*move*move/127*127);
  }
  else if (move < 0){
    return (move*move*move/127*127);
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
    power = cubic(power);
    turn = cubic(turn);
    //assigning the variables to each side of the robot
    int left = power + turn;
    int right = power - turn;
    //having a cubic cruve for the values of the variables
    cubic(left);
    cubic(right);
    //initial values for each left and right side motors of the robot
    int assignLeft = 0;
    int assignRight = 0;
    while((assignLeft > left || assignRight > right) || (assignLeft < left || assignRight < right)){
      if(left > assignLeft){
        assignLeft = assignLeft + 10;
      } else if(left < assignLeft){
        assignLeft = assignLeft - 10;
      } else if(right > assignRight){
        assignRight = assignRight + 10;
      } else if (right < assignRight){
        assignRight = assignRight - 10;
      }
      else{
        assignLeft = assignLeft;
        assignRight = assignRight;
      }
      //assigning values to the motors
      leftFront.move(assignLeft);
      leftBack.move(assignLeft);
      rightFront.move(assignRight);
      rightBack.move(assignRight);
    }
}