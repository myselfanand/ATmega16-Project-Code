/*
 * DHT11_interfacing.c
 *
 * Created: 17-11-2022 11:06:55
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


int main(void)
{
   DDRA = 0xFF;
   DDRB = 0xFF;
   
   lcd_cmd(0x38); //initialize the LCD
   _delay_ms(10);
   
   lcd_cmd(0x0E); // displaying on cursor
   _delay_ms(10);
   
   lcd_cmd(0x01);  //clear screen
   _delay_ms(10);
   
   lcd_cmd(0x80); // start cursor at beginning
   _delay_ms(10);
	
	
    while (1) 
    {
			
				
    }
}

