#include "GeneralFunc.h"



boolean funcCall(void* pFrame)
{
    uint8_t cmdReceived = 0;
    uint8_t channel = 0;
    int16_t data = 0;
    cmdReceived = (uint8_t) ((ST_GW_NO_DATA*) pFrame)->FrameHeader.Command;

    switch (cmdReceived)
    {
    case 0x01:
        ST_GW_VOLTAGE *voltageFrame;
        voltageFrame = ((ST_GW_VOLTAGE*) pFrame);
        updateVoltage(voltageFrame->FrameHeader.Channel, voltageFrame->Voltage);
        break;
    case 0x02:
        ST_GW_CURRENT *currentFrame;
        currentFrame = ((ST_GW_CURRENT*) pFrame);
        updateCurrent(currentFrame->FrameHeader.Channel, currentFrame->Current);
        break;    
    case 0x03:
        ST_GW_SET_CURRENT *currentSetFrame;
        currentSetFrame = ((ST_GW_SET_CURRENT*) pFrame);
        updateSetCurrent(currentFrame->FrameHeader.Channel, currentFrame->Current);
        break;
    default:
        return false;
        break;
    }
    return true;
}