#include <reg51.h>

sbit LED = P1^0;

void delay(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void main()
{
    unsigned char count = 0;

    while(1)
    {
        LED = 0;
        delay(500);

        LED = 1;
        delay(500);

        count++;

        // Simulate software failure after 10 cycles
        if(count == 10)
        {
            while(1);    // Program hangs here
        }
    }
}