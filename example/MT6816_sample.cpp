#include "Arduino.h"

#include "MT6816.h"

#define SCK 16
#define MISO 15
#define MOSI 14
#define MT6816_CS 13

MT6816 myMT6816(MT6816_CS);

float degree;
float deg_s;

void setup(){
    Serial.begin(11500);
    SPI.begin(SCK, MISO, MOSI);

    myMT6816.init();
}

void loop(){
    degree = myMT6816.getRotation_Deg();
    deg_s = myMT6816.RPS_Deg();

    Serial.printf("角度:%f[deg], 角速度:%f[deg/s]\n",degree,deg_s);

    delay(1000);
}