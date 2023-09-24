/*
 * micro controller name: ATmega32
 * open led with loop decimal number
*/

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "avr/macro.h"




int main()
{
    SET_BYTE(DDRA, 0xFF);
    CLR_BYTE(PORTA);
    byte i;

    while(1)
    {
        for (i = 0x01; i <= 0xFF; i++)
        {
            SET_BYTE(PORTA, i);
            _delay_ms(1000);
        }
    }
}
