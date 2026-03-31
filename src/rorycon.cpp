#include "Arduino.h"
#include "rorycon.h"

void rorycon::setup(int pinA, int pinB, int reso, int unit = 0){
    pinA_num = pinA;
    pinB_num = pinB;
    count_max = reso*4;

    pinMode(pinA_num, INPUT);
    pinMode(pinB_num, INPUT);

    
}

double rorycon::rad(){

}

double rorycon::deg(){

}

double rorycon::rps_rad(){

}

double rorycon::rps_deg(){

}