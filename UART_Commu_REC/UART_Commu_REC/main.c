/*
 * UART_Commu_REC.c
 *
 * Created: 21-11-2022 11:47:32
 * Author : JCBRO_1
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>


void uart_init()
{
UCSRA = 0x00;  //control register initialization
UCSRB = 0x18;  // enable transmitter & receiver
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

unsigned char uart_receive()
{
	unsigned char d;
	while((UCSRA & 0x80)==0x00)
	{
		;
	}
	d = UDR;
	return (d);
}

void data2()
{
	unsigned char j = 0, b[] = {"Embedded Garage Tutorials!\r"};
		
	 while(b[j] != '\0')
	 {
		 uart_transmit(b[j]);
		 j++;
	 }
}

int main(void)
{
    /* Replace with your application code */
		
    unsigned char i = 0, a[] = {"Hello Everyone Welcome to: \r"};
    unsigned char d;

	
	
	uart_init();  //initialize UART
	
	while(a[i] != '\0')
    {
	    uart_transmit(a[i]);
	    i++;
    }
	
	while(1)
	{
		d = uart_receive();
		     
		if(d == 'A')
		{				
        data2();
		}				
	}

}

