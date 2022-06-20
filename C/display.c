/******
Demo for ssd1306 i2c driver for  Raspberry Pi 
******/
#include <unistd.h>
#include "ssd1306_i2c.h"

unsigned char i2c[20]  = "/dev/i2c-1";
unsigned int wait_usec = 150 * 1000;  // .15 seconds

/*
 entrypoint for binary `display`
 */
int main(void) 
{
    int ret;

    ret = setup(i2c, wait_usec); if (ret > 0) {
        goto exit;
    }

    char IPSource[20] = FirstGetIpAddress();

    unsigned char symbol = 0;
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

    exit:
        return ret;
}
