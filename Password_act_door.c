/*
 * Project : 
 *			Password_act_door.c
 *
 *  Created: 22/01/2015
 *  Author: Michael
 */ 

#include <avr/io.h>
#include <string.h>
#include "LCD.h"
#include "keypad.h"


// Global Area
unsigned char password[20] = "123";
unsigned char key_in[20];
unsigned char *chrc, cntr=0;		// Counter used in loop (INT0).
void string_in(unsigned char *chrc);

// MAIN FUNCTION
int main(void)
{
	DDRD = 0xFF;
	DDRB = 0xFF;
	
	// Initialize LCD, KEYPAD.
	void_LCD_init();
	void_keypad_init();
		
	// Print Welcoming Message and wait for the Password.
	void_LCD_clear();
	void_LCD_print("Enter Password  please ...");

	// Check if password has been entered completely.
	while(1)
	{
		*chrc = u_char_keypad_read();
		string_in(chrc);
		
		if(cntr == 100)
		{
			// Check password.
			if(!strcmp(key_in,password))
			{	
				PORTD = 0x80;	// GREEN LED ON.
				void_LCD_clear();
				void_LCD_print("Welcome Home");
			}		
			else						
			{
				PORTD = 0x01;	// RED LED ON.
				void_LCD_clear();
				void_LCD_print("Wrong Entery");
			}

			key_in[0] = '\0';
			cntr = 0;
		}
		
	}	
}

void string_in(unsigned char *chrc)
{
	// Check if 'F' is received.	
	if(*chrc == 'F')
	{
		cntr = 100;	// Clearing counter for the next password entering.
	}	
	else
	{
		key_in[cntr++] = *chrc;
	}
		
	// Check if the password Max. limit is reached.
	if(cntr == 20)
	{
		cntr = 100;
	}
}
