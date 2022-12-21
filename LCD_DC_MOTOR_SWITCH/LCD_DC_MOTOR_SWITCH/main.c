/*
 * LCD_DC_MOTOR_SWITCH.c
 *
 * Created: 11-10-2022 16:40:15
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

void motor_fwd()
{
	PORTC = 0x05;	
	
   lcd_cmd(0x01);  //clear screen
   _delay_ms(10);		
	
	int i = 0;
	  char a[] = "FORWARD";
	  
	  while(a[i] != '\0')
	  {
		  lcd_data(a[i]);
		  i++;
		  _delay_ms(10);
	  }
	  _delay_ms(3000);
}

void motor_bwd()
{
	PORTC = 0x0A;
	
	lcd_cmd(0x01);  //clear screen
	_delay_ms(10);
	
	int i = 0;
	char a[] = "BACKWARD";
	
	while(a[i] != '\0')
	{
		lcd_data(a[i]);
		i++;
		_delay_ms(10);
	}
	_delay_ms(3000);
}

void motor_right()
{
	PORTC = 0x01;
	
	lcd_cmd(0x01);  //clear screen
	_delay_ms(10);
	
	int i = 0;
	char a[] = "RIGHT";
	
	while(a[i] != '\0')
	{
		lcd_data(a[i]);
		i++;
		_delay_ms(10);
	}
	_delay_ms(3000);	
}

void motor_left()
{
	PORTC = 0x08;
	
   lcd_cmd(0x01);  //clear screen
   _delay_ms(10);
		
	int i = 0;
	char a[] = "LEFT";
	
	while(a[i] != '\0')
	{
		lcd_data(a[i]);
		i++;
		_delay_ms(10);
	}
	_delay_ms(3000);
	
}


int main(void)
{
	/* Replace with your application code */
	DDRA = 0xFF;
	DDRB = 0xFF;	
	DDRC = 0xFF;
	DDRD = 0x00;
	
	unsigned char a = 0;
	unsigned char b = 0;
	
	
	lcd_cmd(0x38); //initialize the LCD
	_delay_ms(10);
	
	lcd_cmd(0x0E); // displaying on cursor
	_delay_ms(10);
	
	lcd_cmd(0x01);  //clear screen
	_delay_ms(10);
	
	lcd_cmd(0x80); // start cursor at beginning
	_delay_ms(10);
	
	while(1)
	{	
		a = PIND & 0x10;
		b = PIND & 0x20;
		
	if(a == 0x00 && b == 0x00)	
	{
	 motor_fwd();
	}
	
	else if(a==0x00 && b == 0x20)
	{
		 motor_bwd();
	}
	
	else if(a == 0x10 && b == 0x00)
	{
		motor_left();
	}
	
	else if(a == 0x10 && b == 0x20)		
	{ 
	    motor_right();
	}
	 
	 else 
	 {
		 
	 }
  }
  
}


