#include <Arduino.h>

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

    // // actionButton(0, RED);

    // funcCall(frame);
    
}

void loop()
{
    // tp = ts.getPoint();

    // pinMode(XM, OUTPUT);
    // pinMode(YP, OUTPUT);

        
    if(readSerial(pReadSerial, &readIndex))
    {
        Serial.println("Print Serial");
        for (int i = 0; i <= readIndex; i++)
        {
            Serial.print(pReadSerial[i]);
        }
        memset(pReadSerial, 0, sizeof(pReadSerial));
        Serial.println("");
        readIndex = 0;
    }

    // if(tp.x > 197 && tp.x < 540 && tp.y > 220 && tp.y < 310)
    // {
    //     if(ch1State == Enable){
    //         ch1State = Disable;
    //         Serial.println(ch1State);
    //         actionButton(0, GREEN);
    //     }
    //     else
    //     {
    //         ch1State = Enable;
    //          Serial.println(ch1State);
    //         actionButton(0, RED);
    //     }
    //     delay(500);   
    // }
    

}


