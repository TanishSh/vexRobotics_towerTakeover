#include "main.h"
#include "globals.hpp"
#include "arm.h"

void armMove(){
    int move = master.get_analog(ANALOG_RIGHT_Y);
    arm.move(move);
    
}