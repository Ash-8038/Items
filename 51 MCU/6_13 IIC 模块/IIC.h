#ifndef __IIC_H_
#define __IIC_H_
void IIC_STAR();
void IIC_STOP();
void IIC_SEND_BYTE(unsigned char DATA);
unsigned char IIC_RESIVE_BYTE();
void IIC_SEND_ACK(unsigned char ACK);	
unsigned char IIC_RESIVE_ASK();	

#endif
