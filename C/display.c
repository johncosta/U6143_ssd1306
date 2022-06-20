/******
Demo for ssd1306 i2c driver for  Raspberry Pi 
******/
#include <stdio.h>
#include <unistd.h>
#include "ssd1306_i2c.h"

/*
 entrypoint for binary `display`
 */
int main(void) 
{
    unsigned char symbol = 0;

    setup();

    FirstGetIpAddress();                        //Get IP address
    while(1)
    {
        LCD_Display(symbol);
        sleep(1);
        sleep(1);
        sleep(1);
        symbol++;
        if(symbol==3)
        {
          symbol=0;
        }
    }
    return 0;
}
