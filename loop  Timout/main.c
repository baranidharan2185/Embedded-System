#include <reg51.h>

#define TIMEOUT_LIMIT 1000

void delay()
{
    unsigned int i,j;
    for(i=0;i<100;i++)
        for(j=0;j<1275;j++);
}

void main()
{
    unsigned int timeout;

    while(1)
    {
        // Success case
        P1 = 0x00;
        delay();

        // Failure case
        timeout = 0;

        while(timeout < TIMEOUT_LIMIT)
        {
            timeout++;
        }

        P1 = 0xFF;
        delay();
    }
}