/*
Made by: TanishSh 29/01/2020
*/
#include "main.h"
#include "globals.hpp"
#include "tilter.h"
void angleAdjuster(){
    tilter.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    if(master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L1)){
        tilter.move(90);
    }else if(master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_L2)){
        tilter.move(-90);
    }
    else{
        tilter.move(0);
    }
}