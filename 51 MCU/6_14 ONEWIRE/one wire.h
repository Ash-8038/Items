#ifndef ONE_WIRE_H
#define ONE_WIRE_H


unsigned char ONE_WIRE_INIT();
void ONE_WIRE_SEND(unsigned char BIT);
unsigned char ONE_WIRE_RECIVE();
void ONE_WIRE_SEND_BYTE(unsigned char DATA);
unsigned char ONE_WIRE_RECIVE_BYTE();


#endif