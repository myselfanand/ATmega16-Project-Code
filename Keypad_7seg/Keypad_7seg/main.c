/*
 * Keypad_7seg.c
 *
 * Created: 14-10-2022 16:46:52
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
	
	void column_1()
	{
		PORTC = 0x04;
		
		if(PIND & 0x01)
		{
			PORTA = 0x01;
			PORTB = 0x06;
			
		}
		
		else if(PIND & 0x02)
		{
			PORTA = 0x08;
			PORTB = 0x66;
			
		}
		
		else if(PIND & 0x04)
		{
			PORTA = 0x40;
			PORTB = 0x07;
			
		}
		
		else if(PIND & 0x08)
		{
			PORTA ='*';
			PORTB = 0x77;
			
		}
		else
		{
			
		}
		
	}
	
	void column_2()
	{
		PORTC = 0x02;
		
		if(PIND & 0x01)
		{
			PORTA = 0x02;
			PORTB = 0x5B;
			
		}
		
		else if(PIND & 0x02)
		{
			PORTA = 0x10;
			PORTB = 0x6D;
			
		}
		
		else if(PIND & 0x04)
		{
			PORTA = 0x80;
			PORTB = 0x7F;
			
		}
		
		else if(PIND & 0x08)
		{
			PORTA = 0x00;
			PORTB = 0x3F;
			
		}
		else
		{
			
		}
	}
	
	void column_3()
	{
		
		PORTC = 0x01;
		
		if(PIND & 0x01)
		{
			PORTA = 0x04;
			PORTB = 0x4F;
			
		}
		
		else if(PIND & 0x02)
		{
			PORTA = 0x20;
			PORTB = 0x7D;
			
		}
		
		else if(PIND & 0x04)
		{
			PORTB = 0xC0;
			PORTB = 0x6F;
			
		}
		
		else if(PIND & 0x08)
		{
			PORTA = '#';
			PORTB = 0x39;
		}
		else
		{
			//PORTB = 0x00;
		}
	}
	
	while (1)
	{
		column_1();
		column_2();
		column_3();
		
	}
}
