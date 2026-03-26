#include "Arduino.h"

#include "rorycon.h"

rorycon myrorycon;

float degree;

void setup(){
    Serial.begin(11500);
    myrorycon.setup(11,12,360);
}

void loop(){
    degree = myrorycon.deg();

    Serial.printf("degree:%f[deg]\n",degree);

    delay(1000);
}