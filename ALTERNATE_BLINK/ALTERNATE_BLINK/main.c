/*
 * ALTERNATE_BLINK.c
 *
 * Created: 08-10-2022 10:40:45
 * Author : JCBRO_1
 */ 
#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	unsigned char a = 0;
	DDRA = 0x00;
	DDRB = 0xFF;
	 
    while (1) 
    {
		a  = PINA & 0x20;
		if(a == 0x20)
		{
		PORTB = 0xF0;
		_delay_ms(500);
		
		PORTB = 0x0F;
		_delay_ms(500);
    }
	
	else {
		
		PORTB = 0x55;
		_delay_ms(500);
		
		PORTB = 0xAA;
		_delay_ms(500);
	}
		
	}
}

