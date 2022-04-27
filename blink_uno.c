#include <avr/io.h>
#include <util/delay.h>


// This program blinks the builtin LED of the arduino Uno
// Change in the Makefile the variables file_name (to match this file)
// and the baud_rate (use 57600 for nano and 115200 for uno)
// Author: M. Chiappalone
// Date: April 2022

int main(void) {
	
	// set PORTB5 as an output
	// DDRB is Port B Data Direction Register. Output is enabled with a 1
	DDRB |= (1 << DDB5);

	// forever
	while(1)
	{

		// set PORTB5 high
		// PORTB is Port B data Register
		PORTB |= (1 << PORTB5);

		// wait
		_delay_ms(1000);

		// unset PORTB5
		PORTB &= ~(1 << PORTB5);

		// Wait again
		_delay_ms(1000);

	}
}
