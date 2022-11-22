/*
 * Servo_Motor.c
 *
 * Created: 11/2/2022 9:32:38 AM
 * Author : hp
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRC = 0x01;
	PORTC = 0x00;
    while (1) 
    {
		//Rotate motor 0 degree
		PORTC = 0x01;
		_delay_ms(1);
		PORTC = 0x00;
		_delay_ms(2000);
		
		//Rotate motor 90 degree
		PORTC = 0x01;
		_delay_ms(1.5);
		PORTC = 0x00;
		_delay_ms(2000);
		
		//Rotate motor 180 degree
		PORTC = 0x01;
		_delay_ms(2);
		PORTC = 0x00;
		_delay_ms(2000);
		
		//Rotate motor 90 degree
		PORTC = 0x01;
		_delay_ms(1.5);
		PORTC = 0x00;
		_delay_ms(2000);
    }
}

