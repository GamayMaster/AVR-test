/*
 * micro controller name: ATmega32
 * read puls from button and open led pin by pin
*/


#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

#include "avr/macro.h"




int main()
{
    SET_BYTE(DDRA, 0xFF);
    SET_BYTE(DDRB, 0x00);
    CLR_BYTE(PORTA);
    byte i;

    while(1)
    {
        for (i = 0; i < 8; i++)
        {
            while (1)
            {
                _delay_ms(20);
                if (READ_BIT(PINB, 0) == 1)
                {
                    _delay_ms(20);
                    CLR_BIT(PORTA, i-1);
                    break;
                }
            }
            SET_BIT(PORTA, i);
        }
    }
}
