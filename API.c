#include "API.h"

int readSerial(int *read)
{
    int index= 0;
    while (Serial.available())
    {
        read[index] = Serial.read();
        index++;
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
    cmdReceived = (uint8_t) ((ST_GW_SET_CURRENT*) pFrame)->FrameHeader.Command;


    switch (cmdReceived)
    {
    case 0x01:
        channel = (uint8_t) ((ST_GW_VOLTAGE*) pFrame)->FrameHeader.Channel;
        data = (uint16_t) ((ST_GW_VOLTAGE*)pFrame)->Voltage;

        Serial.println(data);
        // updateVoltage(channel, data);
        break;
    case 0x02:

        break;    
    case 0x03:

        break;
    case 0x04:

        break;
    default:

        break;
    }
}

