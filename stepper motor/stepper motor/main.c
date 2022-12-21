/*
 * stepper motor.c
 *
 * Created: 17-10-2022 17:30:21
 * Author : JCBRO_1
 */ 

#define F_CPU 12000000
#include <avr/io.h>
#include <util/delay.h>


// void singlephase_clockwise()
// {
// 	//CW(clockwise) - phase excitation
// 	
// 	PORTC=0x08;
// 	_delay_ms(4000);
// 	PORTC=0x04;
// 	_delay_ms(4000);
// 	PORTC=0x02;
// 	_delay_ms(4000);
// 	PORTC=0x01;
// 	_delay_ms(4000);
// }



// 	void singlephase_anti_clockwise()
// 	{
// 		//ACW(anti-clockwise) - phase excitation
// 		
// 		PORTC=0x01;
// 		_delay_ms(5000);
// 		
// 		PORTC=0x02;
// 		_delay_ms(5000);
// 		
// 		PORTC=0x04;
// 		_delay_ms(5000);
// 		
// 		PORTC=0x08;
// 		_delay_ms(5000);
// 	}
	

void two_phase_clockwise()
{
	//CW-2 phase excitation
	
	PORTC=0x09;      //port c work as clockwise two phase
	PORTB=0x09;     //port b work as clockwise single phase 
	_delay_ms(4000);
	
	PORTC=0x0c;
	PORTB=0x0c;
	_delay_ms(4000);
	
	PORTC=0x06;
	PORTB=0x06;
	_delay_ms(4000);
	
	PORTC=0x03;
	PORTB=0x03;
	_delay_ms(4000);
}


// void two_phase_anti_clockwise()
// {
// 	//ACW-2 phase excitation
// 	
// 	PORTC=0x09;
// 	_delay_ms(4000);
// 	PORTC=0x03;
// 	_delay_ms(4000);
// 	PORTC=0x06;
// 	_delay_ms(4000);
// 	PORTC=0x0C;
// 	_delay_ms(4000);
// }


int main(void)
{
	DDRC = 0xff;
	DDRB = 0xff;
	
	while (1)
	{
		//singlephase_clockwise();
		//singlephase_anti_clockwise();
		two_phase_clockwise();
		//two_phase_anti_clockwise();
	}
}