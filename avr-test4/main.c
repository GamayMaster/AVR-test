/*
 * micro controller name: ATmega32
 * seven segment
*/


#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "avr/macro.h"




int main()
{
    byte i = 0;
    byte ss[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x47, 0x7F, 0x6F};
    SET_BYTE(DDRA, 0xFF);

    while(1)
    {
        SET_BYTE(PORTA, ss[i]);
        _delay_ms(1000);
        if (i == 9)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }
}
