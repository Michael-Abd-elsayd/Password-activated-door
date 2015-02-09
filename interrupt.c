/*
 * CFile1.c
 *
 * Created: 11/01/2015 08:07:03 م
 *  Author: MiKeL
 */ 

#include <avr/interrupt.h>

extern void void_init_extern_intrrpt(unsigned char intrrpt_no, unsigned char trigger_type)
{
	switch(intrrpt_no)
	{
		// INT0.
		case 0:
			GICR |= 0b01000000;
			switch (trigger_type)
			{
				case 0:
					MCUCR &= 0b11111100;
					MCUCR |= 0b00000000 ;
					break;
				case 1:
					MCUCR &= 0b11111100;
					MCUCR |= 0b00000001 ;	
					break;
				case 2:
					MCUCR &= 0b11111100;
					MCUCR |= 0b00000010 ;	
					break;
				case 3:
					MCUCR &= 0b11111100;
					MCUCR |= 0b00000011 ;		
					break;
				default:
					MCUCR &= 0b11111100;
					MCUCR |= 0b00000011 ;
			}
			break;
		// INT1.
		case 1:
			GICR |= 0b10000000;
			switch (trigger_type)
			{
				case 0:
					MCUCR &= 0b11110011;
					MCUCR |= 0b00000000 ;
					break;
				case 1:
					MCUCR &= 0b11110011;
					MCUCR |= 0b00000100 ;
					break;
				case 2:
					MCUCR &= 0b11110011;
					MCUCR |= 0b00001000 ;
					break;
				case 3:
					MCUCR &= 0b11110011;
					MCUCR |= 0b00001100 ;
					break;
				default:
					MCUCR &= 0b11110011;
					MCUCR |= 0b00001100;
			}
			break;
		// INT2.
		case 2:
			GICR |= 0b00100000;
			switch (trigger_type)
			{
				case 2:
					MCUCSR &= 0b10111111;
					MCUCSR |= 0b00000000;
					break;
				case 3:
					MCUCSR &= 0b10111111;
					MCUCSR |= 0b01000000;
					break;
				default:
					MCUCSR &= 0b10111111;
					MCUCSR |= 0b10000000;
			}

			break;
		default:
			GICR |= 0b01000000;
			switch (trigger_type)
			{
				case 0:
				MCUCR &= 0b11111100;
				MCUCR |= 0b00000000 ;
				break;
				case 1:
				MCUCR &= 0b11111100;
				MCUCR |= 0b00000001 ;
				break;
				case 2:
				MCUCR &= 0b11111100;
				MCUCR |= 0b00000010 ;
				break;
				case 3:
				MCUCR &= 0b11111100;
				MCUCR |= 0b00000011 ;
				break;
				default:
				MCUCR &= 0b11111100;
				MCUCR |= 0b00000011 ;
			}
	}
}