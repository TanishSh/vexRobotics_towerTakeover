#include "main.h"
#include "globals.hpp"
#include "arm.h"

void armSetup(){
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}
void armUp(int speed){
    armSetup();
    arm.move(speed);
}
void armDown(int speed){
    armSetup();
    arm.move(-speed);
}
void armOFF(){
    armSetup();
    arm.move(0);
}
void armMove(){
    if(master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R1)){
        armUp(65);
    } else if(master.get_digital(pros::controller_digital_e_t::E_CONTROLLER_DIGITAL_R2)){
        armDown(65);
    }
    else{
        armOFF();
    }
}