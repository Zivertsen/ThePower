#ifndef HEADER_GUI
#define HEADER_GUI

#include <Arduino.h>
#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>


#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GRAY    0x18C3

#define SCREENSIZEX 480 
#define SCREENSIZEY 320

const int XP=6,XM=A2,YP=A1,YM=7; //ID=0x9341






//Draw the main layout 
void mainLayout();

//Draw the button
void actionButton(int x, uint16_t color);

void updateVoltage(int ch, int data);

void updateCurrent(int ch, int data);

void updateSetCurrent(int ch, int data);

void readTouch();

void channelOneButton();

void channelTwoButton();


#endif
