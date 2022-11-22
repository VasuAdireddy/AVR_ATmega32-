/*
 * Motor.c
 *
 * Created: 10/26/2022 10:43:14 AM
 * Author : hp
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00;
	DDRD = 0xFF;
    while (1) 
    {
		if(PINA == 0x00)
			PORTD = 0b00100010;
		else if(PINA == 0x01)
			PORTD = 0b00100001;
		else if(PINA == 0x02)
			PORTD = 0b00010010;
		else if(PINA == 0x03)
			PORTD = 0b00010001;
    }
}

