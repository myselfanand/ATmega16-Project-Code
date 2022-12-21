/*
 * KEYPAD_INTERFACE.c
 *
 * Created: 14-10-2022 11:01:21
 * Author : JCBRO_1
 */ 

#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA = 0xFF;   //led
	DDRC = 0xFF;  // keypad output(123)
	DDRD = 0x00;  // keypad input(A,B,C,D)
	DDRB = 0xFF;
   
    while (1) 
    {
		PORTC = 0x04;
		
		if(PIND & 0x01)
		{
			PORTA = 0x01;	
		}
		
		else if(PIND & 0x02)
		{
			PORTA = 0x08;			
		}
		
		else if(PIND & 0x04)
		{			
			PORTA = 0x40;
		}
		
		else if(PIND & 0x08) 
		{
			PORTA ='*';
		}
		else
		{
			
		}
		
		                                       PORTC = 0x02;
											   
											   if(PIND & 0x01)
											   {
												 PORTA = 0x02;												 
											   }
											   
											   else if(PIND & 0x02)
											   {
												 PORTA = 0x10;
											   }
											   
											   else if(PIND & 0x04)
											   {
												   PORTA = 0x80;
											   }
											   
											   else if(PIND & 0x08)
											   {
												   PORTA = 0x00;
											   }
											   else
											   {
												   
											   }
		PORTC = 0x01;
		
		if(PIND & 0x01)
		{
			PORTA = 0x04;
		}
		
		else if(PIND & 0x02)
		{
			PORTA = 0x20;
		}
		
		else if(PIND & 0x04)
		{
			PORTB = 0xC0;
		}
		
		else if(PIND & 0x08)
		{
			PORTA = '#';
		}
		else
		{
			PORTB = 0x00;
		}
    }
}

