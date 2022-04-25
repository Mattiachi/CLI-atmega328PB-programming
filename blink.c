#include <avr/io.h>
#include <util/delay.h>


// This program blinks a led wired at the pin D2 of an arduino nano
// Use 57600 as baud rate to flash from CLI
// Author: M. Chiappalone
// Date: April 2022

int main(void) {
	
	// set PORTB5 as an output
	// DDRD is Port D Data Direction Register. Output is enabled with a 1
	DDRD = DDRD | (1 << DDD2);

	// forever
	while(1)
	{

		// set PORTD5 high
		// PORTD is Port D data Register
		PORTD = PORTD | (1 << PORTD2);

		// wait
		_delay_ms(1000);

		// unset PORTB5
		PORTD = PORTD & ~(1 << PORTD2);

		// Wait again
		_delay_ms(1000);

	}
}
