/*
 * micro controller name: ATmega32
 * two device seven segment
*/


#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "avr/macro.h"




int main()
{
    byte i, j;
    byte ss[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x47, 0x7F, 0x6F};

    SET_BYTE(DDRA, 0xFF);
    SET_BIT(DDRB, 0);
    SET_BIT(DDRB, 1);
    SET_BIT(PORTB, 0);
    SET_BIT(PORTB, 1);

    while(1)
    {
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                CLR_BIT(PORTB, 0);
                SET_BYTE(PORTA, ss[j]);
                _delay_ms(10);
                SET_BIT(PORTB, 0);
                CLR_BIT(PORTB, 1);
                SET_BYTE(PORTA, ss[i]);
                _delay_ms(10);
                SET_BIT(PORTB, 1);

            }
        }
    }
}
