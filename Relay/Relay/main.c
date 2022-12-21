/*
 * Relay.c
 *
 * Created: 17-10-2022 11:42:23
 * Author : JCBRO_1
 */ 

#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRC = 0xFF;
	DDRA = 0xFF;
    /* Replace with your application code */
	
	void LAMP_1()
	{
		PORTA = 0x01;
		PORTC = 0x80;
		_delay_ms(500);
		
		PORTA = 0x00;
		PORTC = 0x00;
		_delay_ms(500);
	}
	
	
    while (1) 
    {
	 LAMP_1();	
    }
}

