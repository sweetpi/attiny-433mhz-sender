#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>

#include "rc.h"

#define INPUT_PIN0 PB0
#define INPUT_PIN1 PB1

#define SWITCH_ID "100010100111100010011010"

volatile char state;

int main(void) {

	// Configure TRANS_PIN as output
	DDRB |= (1 << TRANS_PIN);
	// Set INPUT_PIN as Input
	DDRB &= ~(1 << INPUT_PIN0 | 1 << INPUT_PIN1);

	// init interrupt
	// interrupt: PCINT10 
	PCMSK |= (1<<PCINT1 | 1<<PCINT0);

	// turn on interrupts!
	GIMSK  |= (1<<PCIE);
	sei();

	PORTB &= ~(1 << TRANS_PIN);

	while (1) {
		// in den Schlafmodus wechseln
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_mode();  
    // debounce:
		_delay_ms(200);		
		// send(id, oneOrAll, onOrOff, unit): 
		send(SWITCH_ID, 1, state, "1");
	}
}

ISR (PCINT0_vect)
{
	if( !(PINB & (1 << INPUT_PIN0)) ) {
		state = 1;
	} else if ( !(PINB & (1 << INPUT_PIN1)) ) {
		state = 0;
	}
}

