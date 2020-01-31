#include "main.h"
#include "globals.hpp"
#include "arm.h"

void armMove(){
    arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    int move = master.get_analog(pros::controller_analog_e_t::E_CONTROLLER_ANALOG_RIGHT_Y);
    arm.move(move);
}