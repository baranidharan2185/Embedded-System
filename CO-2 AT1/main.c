#include <REGX51.H>

#define SET_TEMP 30

sbit HEATER = P1^0;

unsigned char temperature = 25;

//----------------------------
// Delay Function
//----------------------------
void delay()
{
    unsigned int i,j;

    for(i=0;i<200;i++)
    {
        for(j=0;j<1275;j++);
    }
}

//----------------------------
// Read Temperature
//----------------------------
unsigned char ReadTemperature()
{
    return temperature;
}

//----------------------------
// Heater Control
//----------------------------
void HeaterControl(unsigned char temp)
{
    if(temp < SET_TEMP)
    {
        HEATER = 1;
    }
    else
    {
        HEATER = 0;
    }
}

//----------------------------
// Timer0 Initialization
//----------------------------
void Timer0_Init()
{
    TMOD = 0x01;
    TH0 = 0xFC;
    TL0 = 0x18;
    TR0 = 1;
}

//----------------------------
// Main Program
//----------------------------
void main()
{
    unsigned char temp;

    Timer0_Init();

    while(1)
    {
        temp = ReadTemperature();

        HeaterControl(temp);

        delay();

        temperature++;

        if(temperature > 35)
        {
            temperature = 25;
        }
    }
}