#ifndef RC_H_
#define RC_H_

#define TRANS_PIN PB2

#define SPEED 130
#define START 20
#define _SHORT 2
#define _LONG 11
#define END 150

void send();
void sendStart();
void sendUniqueId(char* c, char l);
void sendPulseAll();
void sendPulseSingle();
void sendUnitCode(char* c, char l);
void sendEnd();
void sendPulseOff();
void sendPulseOn();
void sendPulse0();

#endif /* RC_H_ */
