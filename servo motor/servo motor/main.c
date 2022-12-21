/*
 * servo motor.c
 *
 * Created: 16-11-2022 17:15:25
 * Author : JCBRO_1
 */ 

#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xFF;
	
    /* Replace with your application code */
    while (1) 
    {
		
		PORTC = 0x01;
		_delay_ms(1000);	
		PORTC = 0x00;
		_delay_ms(2000);
		
		
		
		PORTC = 0x01;
		_delay_ms(1500);
		PORTC = 0x00;
		_delay_ms(2000);
		
		
		PORTC = 0x01;
		_delay_ms(2000);
		PORTC = 0x00;
		_delay_ms(2000);
		
		
    }
}

