/*
 * temp_appliance.c
 *
 * Created: 11/1/2022 11:03:57 PM
 * Author : hp
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
void data(unsigned char s)
{
	PORTD |= 0b00000011;
	PORTC = s;
	PORTD &= 0b11111101;
	_delay_ms(1);

}
void command(unsigned char s)
{
	PORTD |= 0b00000010;
	PORTC = s;
	PORTD &= 0b11111100;
	_delay_ms(1);
}
void display(unsigned char arr[])
{
	unsigned char n = strlen(arr);
	for(int i=0;i<n;i++)
	{
		data(arr[i]);
		_delay_ms(2);
	}
}
int main(void)
{
    DDRC = 0xFF;
	DDRD = 0b11110011;
	DDRB = 0x00;
	DDRA = 0x00;
	unsigned char AC[] = "AC IS TURNED ON";
	unsigned char FAN[] = "FAN IS ON";
	unsigned char COOL[] = "COOLER IS ON";
	unsigned char HEAT[] = "HEATER IS ON";
	unsigned char GAS[] = "LPG IS LEAKING";
	unsigned char NONE[] = "TEMP IS FINE";
	unsigned char FUN[] = "SAVING POWER";
	unsigned char BREACH[] = "BREACH DETECTED";
	unsigned com[] = {0x38,0x0E,0x01,0x80};
	ADCSRA = 0x87;
	ADMUX = 0xE0;
    while (1) 
    {
		for(int i=0;i<4;i++)
		{
			command(com[i]);
			_delay_ms(2);
		}
		
		ADCSRA |= (1<<ADSC);
		while((ADCSRA & (1<<ADIF)) == 0);
		int a = (int)ADCH;
		if(a > 35)
		{
			PORTD = 0b00010000;
			display(AC);
		}
		else if(a>25 && a<=35)
		{
			PORTD = 0b00100000;
			display(COOL);
		}
		else if(a>=20 && a<=25)
		{
			PORTD = 0b01000000;
			display(FAN);
		}
		else if(a<=15)
		{
			PORTD = 0b10000000;
			display(HEAT);
		}
		else
		{
			PORTD = 0x00;
			display(NONE);
			command(0xC0);
			display(FUN);
		}
		
		if(PINB == 0x01)
		{
			command(0xC0);
			display(GAS);
		}
		else if(PINB == 0x02)
		{
			command(0xC0);
			display(BREACH);
		}
		else if(PINB == 0x03)
		{
			command(0xC0);
			display(GAS);
			command(0x90);
			display(BREACH);
		}
		_delay_ms(1500);
    }
}

