
#include <Arduino.h>
#include <MCUFRIEND_kbv.h>
#include <string.h>
#include "API.h"
#include "GUI.h"

MCUFRIEND_kbv tft;

actionButtonState ch1State = Enable;
actionButtonState ch2State = Enable;

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GRAY    0x18C3 

int i = 0;

void setup()
{   
    uint8_t frame[] = {6,1,1,192,34,0};
    int packet[10];

    Serial.begin(9600);
    Serial.println("Start up");


    mainLayout();

    // actionButton(0, RED);

    funcCall(frame);
    
}

void loop()
{

    // tp = ts.getPoint();

    // pinMode(XM, OUTPUT);
    // pinMode(YP, OUTPUT);

    int read = Serial.read();
    if(read != -1) Serial.println(read);


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

void mainLayout(){

    tft.begin(tft.readID());
    tft.setRotation(1);
    tft.fillScreen(0xFFFF);
    tft.setTextColor(BLACK);

    tft.drawLine(240,0,240,320, BLACK);

    tft.setTextSize(2);
    tft.setCursor(60,10);
    tft.println("CHANNEL 1");
    tft.setCursor(300,10);
    tft.println("CHANNEL 2");

    //channal 1
    tft.setTextSize(1);
    tft.setCursor(30,50);
    tft.println("Voltage:");

    tft.setCursor(30, 120);
    tft.println("Current:");

    tft.setCursor(30,190);
    tft.println("Set Current:");

    tft.setTextSize(4);
    tft.setCursor(50,70);
    tft.println("00.0");

    tft.setCursor(170,70);
    tft.println("V");

    tft.setCursor(50,140);
    tft.println("00.0");

    tft.setCursor(170,140);
    tft.println("C");

    tft.setCursor(50,210);
    tft.println("00.0");

    tft.setCursor(170,210);
    tft.println("SC");

    //channel 2
        tft.setTextSize(1);
    tft.setCursor(270,50);
    tft.println("Voltage:");

    tft.setCursor(270, 120);
    tft.println("Current:");

    tft.setCursor(270,190);
    tft.println("Set Current:");

    tft.setTextSize(4);
    tft.setCursor(290,70);
    tft.println("00.0");

    tft.setCursor(410,70);
    tft.println("V");

    tft.setCursor(290,140);
    tft.println("00.0");

    tft.setCursor(410,140);
    tft.println("C");

    tft.setCursor(290,210);
    tft.println("00.0");

    tft.setCursor(410,210);
    tft.println("SC");

}

