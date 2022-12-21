#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRD = 0xFF;
	DDRB = 0xFF;
	
	
	int a[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
		
	while(1)
	{					
		for(int i = 0; i < 10; i++)
		{
			PORTD = a[i];
			PORTB = 0x01;
			_delay_ms(1000);
		}	
			
	}
    
}

