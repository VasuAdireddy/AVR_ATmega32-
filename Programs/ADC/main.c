/*
 * ADC.c
 *
 * Created: 11/2/2022 9:50:12 AM
 * Author : hp
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00;
	DDRD = 0Xff;
	ADCSRA = 0x87;
	ADMUX = 0xE0;
	while(1)
	{
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF)) == 0);
		if(ADCH > 0x0F)
			PORTD = 0x01;
		else
			PORTD = 0x00;
	}
	return 0;
}

