#include <Arduino.h>
#include <stdint.h>


#include "src/API/API.h"
#include "src/GUI/GUI.h"

int pReadSerial[4];

int readIndex = 0;

void setup()
{   
    // uint8_t frame[] = {6,1,1,192,34,0};
    // int packet[10];


    Serial.begin(9600);
    Serial.println("Start up");

    mainLayout();

    actionButton(0, RED);
    // actionButton(SCREENSIZEX/2, RED);

    // funcCall(frame);
    
}

void loop()
{
    readTouch();
    delay(500);
  
}


