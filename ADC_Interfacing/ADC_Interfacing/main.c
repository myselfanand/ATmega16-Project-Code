/*
 * 
 *
 * Created: 11-11-2022 12:10:34
 * Author : JCBRO_1
 */ 

#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>


void lcd_cmd(unsigned char cmd)
{

	PORTB = cmd;
	
	PORTC = 0x04;
	_delay_ms(10);
	
	PORTC = 0x00;
	_delay_ms(10);	
}

void lcd_data(unsigned char data)
{
	
	PORTB = data;
	
	PORTC = 0x05;
	_delay_ms(10);
	
	PORTC = 0X01;
	_delay_ms(10);
}


//to initialize the ADC
void adc_init()
{
	DDRA = 0x00; //make ADC port as input
	ADMUX = 0x40; // Vref=AVCC; select channel 0
	ADCSRA = 0xc3; // enable ADC & start 1st dummy conversion; set ADC module prescalar; to 8 critical for accurate adc result
}



unsigned int adc_read(unsigned char ch)
{
	unsigned int low, high, adc_val;
	ADMUX |= ch;
	ADCSRA |= (1<<ADSC);
	while (!(ADCSRA & 0x10));
	ADCSRA |= 0x10;
	
	low = ADCL;
	high = ((unsigned int)(ADCH << 8));
	adc_val = low | high;
	return(adc_val);
}


void lcd_str(unsigned char *p)
{
		while(*p!='\0')
		{
			lcd_data(*p);
			p= p+1;
		}
	
}

/*void send_adc_lcd(unsigned int data)
{
	unsigned char ascii_val[4] = "0000";
	unsigned char i = 3;
	while(data > 0)
	{
		ascii_val[i] = 48 + data % 10;
	    data = data/10;
		i--;
	}
	lcd_str(ascii_val);
}
*/

void send_vtg_lcd(unsigned int data)
{
	unsigned char i =3, ascii_val[4] = "0000";
	float vin;
	
	vin = (data*5.0)/1023;
	data = (unsigned int)(vin*1000);
	
	while(data > 0)
	{
		ascii_val[i] = 48 + data % 10;
		data = data/10;
		i--;
	}
	
	// send ascii value to lcd
	lcd_data(ascii_val[0]);
	lcd_data('.');
	lcd_data(ascii_val[1]);
	lcd_data(ascii_val[2]);
	lcd_data(ascii_val[3]);
}


int main(void)
{
    /* Replace with your application code */
	
	DDRC = 0xFF;
	DDRB = 0xFF;
	
	unsigned int adc_val = 0;
	adc_init();
	
	lcd_cmd(0x38); //initialize the LCD
	_delay_ms(10);
	
	lcd_cmd(0x0E); // displaying on cursor
	_delay_ms(10);
	
	lcd_cmd(0x01);  //clear screen
	_delay_ms(10);
	
	lcd_cmd(0x80); // start cursor at beginning	
	lcd_str("ADC Read Program");
	
    lcd_cmd(0xC0); // start cursor at 2nd line
	lcd_str("ADC Value: ");	
		
	lcd_cmd(0xCA);
	
	while (1)
	{
		adc_val = adc_read(0); 
		send_vtg_lcd(adc_val);
		lcd_cmd(0xCA);
		_delay_ms(1000);
	}
}



