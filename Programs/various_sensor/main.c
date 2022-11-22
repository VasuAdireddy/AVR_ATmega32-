/*
 * various_sensor.c
 *
 * Created: 11/7/2022 3:34:27 PM
 * Author : hp
 */ 
#include <stdio.h>
#include <avr/io.h>
#include <string.h>
#define F_CPU 16000000UL
#include <util/delay.h>
void cat(unsigned char a)
{
	PORTA = 0b00000011;
	_delay_ms(1);
	PORTA = 0b00000001;
	PORTC =a;
}
void data(unsigned char s[])
{
	unsigned char n = strlen(s);
	for(int i=0;i<n;i++)
	{
		cat(s[i]);
		_delay_ms(2);
	}
}
void command(unsigned char s)
{
	PORTA = 0b00000010;
	_delay_ms(1);
	PORTA = 0b00000000;
	PORTC =s;
}
int main(void)
{
    /* Replace with your application code */
	DDRC = 0xFF;
	DDRB = 0xFF;
	DDRD = 0x00;
	DDRA = 0xFF;
	unsigned char MQ2[]={"SMOKE IS HIGH"};
	unsigned char MQ3[]={"ALCOHOL IS HIGH"};
	unsigned char MQ4[]={"CNG GAS IS HIGH"};
	unsigned char MQ5[]={"NATURAL GAS HIGH"};
	unsigned char NONE[]={"ALL GAS ARE LOW"};
	unsigned char comm[] = {0x01,0x38,0x0E};
    while (1) 
    {
		for(int i=0;i<3;i++)
		{
			command(comm[i]);
		}
		if(PIND == 0x00)
		{
			PORTB = 0x00;
			command(0x80);
			data(NONE);			
		}
		else if(PIND == 0x04)
		{
			command(0x80);data(MQ4);PORTB = 0x04;
		}		
		else if(PIND == 0x08)
		{
			command(0x80);data(MQ5);PORTB = 0x08;
		}
		else if(PIND == 0x01)
		{
			command(0x80);data(MQ2);PORTB = 0x01;
		}
		else if(PIND == 0x02)
		{
			command(0x80);data(MQ3);PORTB = 0x02;
		}
		_delay_ms(200);
    }
}

