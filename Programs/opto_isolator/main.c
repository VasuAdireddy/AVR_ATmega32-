/*
 * opto_isolator.c
 *
 * Created: 11/1/2022 1:29:12 PM
 * Author : hp
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRD =0xFF;
    while (1) 
    {
		PORTD = 0x01;
		_delay_ms(100);
		PORTD = 0x00;
		_delay_ms(100);
    }
}

