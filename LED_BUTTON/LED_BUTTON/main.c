/*
 * LED_BUTTON.c
 *
 * Created: 07-10-2022 17:17:20
 * Author : JCBRO_1
 */ 
#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	unsigned char a = 0;
	DDRC = 0x00;
	DDRD = 0x08;
	
    while (1) 
	{
	a = PINC & 0x20;
	
	if(a == 0x20)
	{
		
	PORTD = 0x08;
	_delay_ms(1000);
	
	PORTD = 0x00;
	_delay_ms(1000);
	
    }
	
	else 
	{
		PORTD = 0x00;
		_delay_ms(1000);
	}
	}
}

