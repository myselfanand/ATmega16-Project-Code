/*
 * STRING_LCD.c
 *
 * Created: 10-10-2022 12:14:32
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
	
	PORTB = data;
	
	PORTA = 0x05;
	_delay_ms(10);
	
	PORTA = 0X01;
	_delay_ms(10);
}

void lcd_str(unsigned char *p)
{
	while(*p!='\0')
	{
		lcd_data(*p);
		p= p+1;
	}
}

int main(void)
{
    /* Replace with your application code */
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
	
	char a[] ="hii! how r u";
	lcd_str(a);
	
	lcd_cmd(0xC0); // start cursor at beginning
	_delay_ms(10);
	
	char b[] = "i am fine!";
	lcd_str(b);
	
}

