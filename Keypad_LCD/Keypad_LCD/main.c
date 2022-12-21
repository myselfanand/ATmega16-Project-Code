/*
 * Keypad_LCD.c
 *
 * Created: 15-10-2022 11:57:39
 * Author : JCBRO_1
 */ 

#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>


	
void lcd_cmd(unsigned char cmd)
{

		PORTB = cmd;
		
		PORTA = 0x04;
		_delay_ms(10);
		
		PORTA = 0x00;
		_delay_ms(10);
}

void lcd_data(unsigned char data)
{
   
   //lcd_cmd(0x01);  // clear screen
  // _delay_ms(10);

	PORTB = data;
	
	PORTA = 0x05;
	_delay_ms(10);
	
	PORTA = 0X01;
	_delay_ms(10);
}

	
	void column_1()
	{
		PORTC = 0x04;
		
		if(PIND & 0x01)
		{
			PORTA = 0x01;
			lcd_data('A');
			_delay_ms(10);			
			
		}
		
		else if(PIND & 0x02)
		{
			PORTA = 0x08;			
			lcd_data('D');
			_delay_ms(10);
		}
		
		else if(PIND & 0x04)
		{
			PORTA = 0x40;			
			lcd_data('G');
			_delay_ms(10);
		}
		
		else if(PIND & 0x08)
		{
			PORTA ='*';
			lcd_data('J');
			_delay_ms(10);
			
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
			lcd_data('B');
			_delay_ms(10);
			
		}
		
		else if(PIND & 0x02)
		{
			PORTA = 0x10;
			lcd_data('E');
			_delay_ms(10);
			
		}
		
		else if(PIND & 0x04)
		{
			PORTA = 0x80;
			lcd_data('H');
			_delay_ms(10);
			
		}
		
		else if(PIND & 0x08)
		{
			PORTA = 0x00;
			lcd_data('K');
			_delay_ms(10);
			
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
			lcd_data('C');
			_delay_ms(10);
			
		}
		
		else if(PIND & 0x02)
		{
			PORTA = 0x20;
			lcd_data('F');
			_delay_ms(10);
			
		}
		
		else if(PIND & 0x04)
		{
			PORTB = 0xC0;
			lcd_data('I');
			_delay_ms(10);
			
		}
		
		else if(PIND & 0x08)
		{
			PORTA = '#';
			lcd_data('L');
			_delay_ms(10);
		}
		else
		{
			
		}
	}
	
	int main(void)
	{
		DDRA = 0xFF;   //led
		DDRC = 0xFF;  // keypad output(123)
		DDRD = 0x00;  // keypad input(A,B,C,D)
		DDRB = 0xFF;
		
		
		lcd_cmd(0x38); //initialize the LCD
		_delay_ms(10);
		
		lcd_cmd(0x0E); // displaying on cursor
		_delay_ms(10);
		
		lcd_cmd(0x01);  // clear screen
		_delay_ms(10);
		
		lcd_cmd(0x80); // start cursor at beginning
		_delay_ms(10);
		
		//lcd_data('A');
		//_delay_ms(10);
		
	while (1)
	{
		column_1();
		column_2();
		column_3();
		_delay_ms(200);
		
	}
}
