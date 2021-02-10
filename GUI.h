#ifndef HEADER_GUI
#define HEADER_GUI

#include <Arduino.h>

//Pin touchscreen 
// const int XP=6,XM=A2,YP=A1,YM=7; //ID=0x9341
// TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
// TSPoint tp;


// MCUFRIEND_kbv tft;

enum actionButtonState{
    Enable = 1,
    Disable = 0,
};


//Draw the main layout 
void mainLayout();

//Draw the button
void actionButton(int x, uint16_t color);

void updateVoltage(int ch, int data);

void updateCurrent(int ch, int data);

void updateSetCurrent(int ch, int data);

#endif