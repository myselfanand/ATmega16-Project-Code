/*
 * UART_COMMUNICATION.c
 *
 * Created: 18-11-2022 11:30:02
 * Author : JCBRO_1
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>


void uart_init()
{
UCSRA = 0x00;  //control register initialization
UCSRB = 0x18;  // enable trasmitter & receiver
UCSRC = 0x86;  // async, no parity, 1 stop bit, 8 data bits
UBRRH = 0x00;  // baud rate initialization
UBRRL = 0x33; // 9600 baud rate	
}


void uart_transmit(unsigned char data)
{
	while((UCSRA & 0x20)==0x00) // wait for UDRE flag
	{
		;
	}
	UDR = data; //load data to UDR for transmission
}

void data_uart()
{
	unsigned char i = 0, a[] = {"Welcome to Embedded Garage Tutorials!\r"};
	while(a[i] != '\0')
	{
		uart_transmit(a[i]);
		i++;	
	}
	_delay_ms(1000);
}
int main(void)
{
    /* Replace with your application code */
	
	uart_init();
	while(1)
	{
		data_uart();
	}
	

}

