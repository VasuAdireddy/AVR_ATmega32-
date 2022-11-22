/*
 * Relay.c
 *
 * Created: 10/26/2022 9:34:37 AM
 * Author : hp
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRD = 0xFF;
	DDRC = 0x00;
	//here i am using PORTC.0 as a switch to check normally closed and normally open relays in Proteus
    while (1) 
    {
		if(PINC == 0x01)
		{
			PORTD = 0x01;
		}
		else
		{
			PORTD = 0x00;
		}
    }
	/*
	Code without using a pins as switch
	DDRD = 0b00000001;
	while(1)
	{
		PORTD |= 0x01;
		_delay_ms(100);
		PORTD &= 0b11111110;
		_delay_ms(100);
	}
	*/
	
}

