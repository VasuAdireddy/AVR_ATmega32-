/*
 * LDR.c
 *
 * Created: 11/2/2022 10:21:07 AM
 * Author : hp
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
    DDRA = 0x00;
    DDRD = 0xff;
    DDRB = 0Xff;
    ADCSRA = 0x87;
    ADMUX = 0xE0;
    while(1)
    {
	    ADCSRA |= (1<<ADSC);
	    while(!(ADCSRA & (1<<ADIF)));
	    if(ADCH > 16)
			PORTD = 0x00;
		else
			PORTD = 0x01;
    }
}

