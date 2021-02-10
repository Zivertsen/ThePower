typedef struct 
{
    uint8_t Length;
    uint8_t Command;
    uint8_t Channel;
}ST_GW_FRAME_HEADER;


typedef struct 
{
    ST_GW_FRAME_HEADER FrameHeader;
    uint16_t Voltage;
}ST_GW_VOLTAGE;

typedef struct 
{    
    ST_GW_FRAME_HEADER FrameHeader;
    uint16_t Current;
}ST_GW_CURRENT;


typedef struct 
{    
    ST_GW_FRAME_HEADER FrameHeader;
    uint16_t SetCurrent;
}ST_GW_SET_CURRENT;

