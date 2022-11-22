/*
 * Stepper_Motor.c
 *
 * Created: 11/2/2022 10:54:09 AM
 * Author : hp
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRD = 0xFF;
    while (1) 
    {
		unsigned char arr[]= {0x09,0x08,0x0C,0x04,0x06,0x02,0x03,0x01};
		//clockwise
		for(int i=0;i<8;i++)
		{
			PORTD = arr[i];
			_delay_ms(1000);
		}
		
		//anti-clockwise
		for(int i=7;i>=0;i--)
		{
			PORTD = arr[i];
			_delay_ms(1000);
		}
    }
}

