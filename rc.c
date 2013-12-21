/*
 * rc.cpp
 *
 */

#include "rc.h"
#include <avr/io.h>
#include <util/delay.h>

void send(char* id, int single, int state, char* unit){
	for(char i=0;i<3;i++) {
		sendStart();
		sendUniqueId(id,24);

		if(single) {
			sendPulseSingle();
		} else {
			sendPulseAll();
		}

		if(state) {
			sendPulseOn();
		} else {
			sendPulseOff();
		}

		sendUnitCode(unit, 1);
		sendEnd();
	}
}

void digitalWrite(char val){
	if(val){
		PORTB |= (1 << TRANS_PIN);
	}else{
		PORTB &= ~(1 << TRANS_PIN);
	}
}

void sendStart() {
	digitalWrite(1);
	_delay_us((SPEED*_SHORT));
	digitalWrite(0);
	_delay_us((SPEED*START));
}

void sendPulse0() {
	digitalWrite(1);
	_delay_us((SPEED*_SHORT));
	digitalWrite(0);
	_delay_us((SPEED*_SHORT));
}

void sendPulse1() {
	digitalWrite(1);
	_delay_us((SPEED*_SHORT));
	digitalWrite(0);
	_delay_us((SPEED*_LONG));
}

void sendPulseHigh() {
	sendPulse0();
	sendPulse1();
}

void sendPulseLow() {
	sendPulse1();
	sendPulse0();
}

void sendPulseOn() {
	sendPulseLow();
}

void sendPulseDim() {
	sendPulse0();
	sendPulse0();
}

void sendPulseOff() {
	sendPulseHigh();
}

void sendPulseAll() {
	sendPulseLow();
}

void sendPulseSingle() {
	sendPulseHigh();
}

void sendUniqueId(char* c, char l) {
	int x = 0;
	for(x=0;x<(26-l);x++) {
		sendPulseHigh();
	}
	for(x=0;x<l;x++) {
		if(c[x] == '1')
			sendPulseLow();
		else
			sendPulseHigh();
	}
}

void sendUnitCode(char* c, char l) {
	int x = 0;
	for(x=0;x<(4-l);x++) {
		sendPulseHigh();
	}
	for(x=0;x<l;x++) {
		if(c[x] == '1')
			sendPulseLow();
		else
			sendPulseHigh();
	}
}



void sendEnd() {
	digitalWrite(1);
	_delay_us((SPEED*_SHORT));
	digitalWrite(0);
	_delay_us((SPEED*END));
}
