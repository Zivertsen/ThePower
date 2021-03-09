#include <Arduino.h>
#include <stdint.h>


#include "src/API/API.h"
#include "src/GUI/GUI.h"

int i = 52177;

uint8_t pReadSerial[30];

void setup()
{   
    // uint8_t frame[] = {6,1,1,192,34,0};
    // int packet[10];


    Serial.begin(9600);
    Serial.println("Start up");

    mainLayout();

    actionButton(0, RED);
    actionButton(SCREENSIZEX/2, RED);

    
}

void loop()
{
    readTouch();    
}


