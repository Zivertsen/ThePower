#include "GUI.h"


MCUFRIEND_kbv tft;

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

void actionButton(int x, uint16_t color){
    tft.fillRect(x+10,250,220,60,color);

    tft.setTextSize(4);
    if(color == RED)
    {
        tft.setCursor(x+90,265);
        tft.println("OFF");
    }
    else
    {
        tft.setCursor(x+100,265);
        tft.println("ON");
    }
}

void updateVoltage(int ch, int data){
    if(ch == 1)
    {
        tft.setTextSize(4);
        tft.setCursor(50,70);
        tft.println(data);
    }else if(ch == 2)
    {
        tft.setTextSize(4);
        tft.setCursor(290,70);
        tft.println(data);
    }
}

void updateCurrent(int ch, int data){
    if(ch == 1)
    {
        tft.setTextSize(4);
        tft.setCursor(50,140);
        tft.println(data);
    }else if(ch == 2)
    {
        tft.setTextSize(4);
        tft.setCursor(290,140);
        tft.println(data);
    }
}

void updateSetCurrent(int ch, int data){
    if(ch == 1)
    {
        tft.setTextSize(4);
        tft.setCursor(50,210);
        tft.println(data);
    }else if(ch == 2)
    {
        tft.setTextSize(4);
        tft.setCursor(290,210);
        tft.println(data);
        
    }
}
