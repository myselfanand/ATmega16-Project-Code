/*
 * LED_2.c
 *
 * Created: 08-10-2022 12:18:03
 * Author : JCBRO_1
 */ 

#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	unsigned char a = 0;
	unsigned char b = 0;
	
	DDRA = 0x00;
	DDRB = 0xFF;
	DDRC = 0x00;
	
    while (1) 
	{		
	a = PINA & 0x20;
	b = PINC & 0x08;
	
	if(a == 0x00 && b == 0x00)
	{
		//ON/off 
		
		PORTB = 0xFF;
		_delay_ms(500);
		
		PORTB = 0x00;
		_delay_ms(500);				
	}
	
	else if(a == 0x00 && b == 0x08)
	{
		//alternate blink
		
		PORTB = 0xAA;
		_delay_ms(500);
		
		PORTB = 0x55;
		_delay_ms(500);
	}
	
	else if(a == 0x20 && b == 0x00)
	{
		//half on off
		
	     PORTB = 0xF0;
		 _delay_ms(500);
		 
		 PORTB = 0x0F;
		 _delay_ms(500);		
	}
	
	else if (a == 0x20 && b == 0x08)
	{
		// ON/OFF in pair	
			
		PORTB = 0xCC;
		_delay_ms(500);
		
		PORTB = 0x33;
		_delay_ms(500);
	}	
	
	else {
			PORTB = 0x00;
			_delay_ms(500);
	}
	
}
	}



