#include "API.h"

boolean readSerial(int *readS, int *pMaxRead)
{
    int16_t readData = 0;
    static int8_t readIndex;

    while (Serial.available())
    {
        readData = Serial.read();   
        
        if(readData == 16 || readIndex > 0)
        {
            
            readS[readIndex] = readData;
            
            // Serial.println(readS[readIndex]);

            if (readData == 16 && readIndex > 0)
            {
                Serial.println("Serial done");
                *pMaxRead = readIndex;
                readIndex = 0;
                return true;
            }
            readIndex++;
        }
    }
    *pMaxRead = 0;
    return false;
}

void writeSerial(int *writeS, int len)
{
    int index = 0;
    Serial.write(writeS[index]);
    while (len--)
    {
        index++;
        Serial.write(writeS[index]);
    }
}

int unslipPacket(int *packet, int *frame)
{
    int index = 0;
    int received = 0;
    int c = 0;
    int len = packet[1];

    while(true)
    {
        c = packet[index];
        switch (c)
        {
        case END:

            if(received)
                return received;
            else 
                index++;
                break;
        case ESC:
            c = packet[index+1];
            switch (c)
            {
            case ESC_END:
                c = END;
                break;
            case ESC_ESC:
                c = ESC;
                break;
            }
        default:
            if(received < len)
            {
                frame[received++] = c;   
            }
            index++;
            
        }
    }
}

void slipPacket(int *f, int *p){
    int len = f[0];
    *p = END;

    while (len--)
    {
        p++;
        switch (*f)
        {
        case END:
            *p = ESC;
            p++;
            *p = ESC_END;
            break;
        case ESC:
            *p = ESC;
            p++;
            *p = ESC_ESC;
            break;
        default:
            *p = *f;
        }
        f++;
    }
    p++;
    *p = END;
}

void addCheckSum(int *frame){
    int len = frame[0]; 
    int sum = 0;
    for (int i = 0; i < len - 1; i++)
    {
        sum ^= frame[i];
    }
    frame[len - 1] = sum;
}

boolean confirmCheckSum(int *frame)
{
    int len = frame[0];
    int sum = 0;
    for (int i = 0; i < len - 1; i++)
    {
        sum ^= frame[i];
    }

    if(sum == frame[len - 1])
    {
        return true;
    }
    return false;
}

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

        Serial.println(voltageFrame->Voltage);
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
