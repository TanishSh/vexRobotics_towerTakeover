#include "main.h"
#include "globals.hpp"
#include "tilter.h"

void tilterSetup(){
    tilter.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
void tilterForward(int speed){
    tilterSetup();
    tilter.move_velocity(speed);
}
void tilterBackward(int speed){
    tilterSetup();
    tilter.move_velocity(-speed);
}
void tilterOFF(){
    tilterSetup();
    tilter.move(0);
}
void tilterMove(){
    if(master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L1)){
        tilterForward(25);
    }else if(master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L2)){
        tilterBackward(25);
    }
    else{
        tilterOFF();
    }
}
