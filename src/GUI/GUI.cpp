#include "GUI.h"
#include "../API/API.h"

MCUFRIEND_kbv tft;

enum actionbuttonstate{
    Enable = 1,
    Disable = 0
};

actionbuttonstate ch1State = Disable;
actionbuttonstate ch2State = Disable;

// Pin touchscreen 
const int XP=6,XM=A2,YP=A1,YM=7; //ID=0x9341
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
TSPoint tp;

//--------------------- Function declaration -------------

void screenClear(int x, int y);

// ------------------ Function bodies ------------------------

void readTouch()
{
    tp = ts.getPoint();
       
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    if(tp.y > 220 && tp.y < 310)
    {
        if(tp.x > 197 && tp.x < 540)
        {
            if(ch1State == Enable){
                ch1State = Disable;
                Serial.println(ch1State);
                actionButton(0, GREEN);
            }
            else
            {
                ch1State = Enable;
                Serial.println(ch1State);
                actionButton(0, RED);
            }
        }
      
        if(tp.x > 570 && tp.x < 930)
        {
            if(ch2State == Enable){
                ch2State = Disable;
                Serial.println(ch2State);
                actionButton(SCREENSIZEX/2, GREEN);
            }
            else
            {
                ch2State = Enable;
                Serial.println(ch2State);
                actionButton(SCREENSIZEX/2, RED);
            }
        }
    delay(500);
    }

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
    tft.println("A");

    tft.setCursor(50,210);
    tft.println("00.0");

    tft.setCursor(170,210);
    tft.println("A");

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
    tft.println("A");

    tft.setCursor(290,210);
    tft.println("00.0");

    tft.setCursor(410,210);
    tft.println("A");

}

void actionButton(int x, uint16_t color){
    uint8_t pFrame[3];
    uint8_t data = 0;
    uint8_t channel = 0;
    tft.fillRect(x+10,250,220,60,color);

    tft.setTextSize(4);
    if(color == RED)
    {
        tft.setCursor(x+90,265);
        tft.println("OFF");
        data = 0;
    }
    else
    {
        tft.setCursor(x+100,265);
        tft.println("ON");
        data = 1;
    }

    if (x > 0 )
    {
        channel = 0x02;
    }
    else
    {
        channel = 0x01;
    }

    buildandSendFrame(0x04,channel, data);
}

void updateVoltage(int ch, int data){
    if(ch == 1)
    {
        screenClear(50, 70);
        tft.setTextSize(4);
        tft.setCursor(50,70);
        tft.println(data);
    }else if(ch == 2)
    {
        screenClear(290, 70);
        tft.setTextSize(4);
        tft.setCursor(290,70);
        tft.println(data);
    }
}

void updateCurrent(int ch, int data){
    if(ch == 1)
    {
        screenClear(50, 140);
        tft.setTextSize(4);
        tft.setCursor(50,140);
        tft.println(data);
    }else if(ch == 2)
    {
        screenClear(290, 140);
        tft.setTextSize(4);
        tft.setCursor(290,140);
        tft.println(data);
    }
}

void updateSetCurrent(int ch, int data){
    if(ch == 1)
    {
        screenClear(50, 210);
        tft.setTextSize(4);
        tft.setCursor(50,210);
        tft.println(data);
    }else if(ch == 2)
    {
        screenClear(290, 210);
        tft.setTextSize(4);
        tft.setCursor(290,210);
        tft.println(data);
        
    }
}

void screenClear(int x, int y)
{
    tft.fillRect(x,y,90,28, WHITE);
}
