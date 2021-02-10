#ifndef HEADER_API
#define HEADER_API
#include <Arduino.h>
#include "FrameStructure.h"
#include "GUI.h"

/* SLIP special character codes*/
#define END             0xC0    /* indicates end of packet */
#define ESC             0xDB    /* indicates byte stuffing */
#define ESC_END         0xDC    /* ESC ESC_END means END data byte */
#define ESC_ESC         0xDD


int readSerial(int *read);

//Removes the END and ESC characters from the packet
int unslipPacket(int *packet, int *frame);

//Make a frame ready for being sent, by adding END and ESC charaters
void slipPacket(int *frame, int *packet);

// checks the checksum and remove it 
boolean confirmCheckSum(int *frame);

// calculate the checksum by XOR the values and adds it to the frame
void addCheckSum(int *frame);

boolean funcCall(void* pFrame);

#endif