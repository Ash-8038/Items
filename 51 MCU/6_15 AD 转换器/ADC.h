#ifndef __ADC_H__
#define __ADC_H__

#define XPT2046_XP    0X9C//8λ�ֱ���
#define XPT2046_XP1    0X94//8λ�ֱ���
#define XPT2046_YP    0XDC
#define XPT2046_VBAT  0XAC
#define XPT2046_AUX   0XEC


unsigned int XPT2046_READ(unsigned char command);


#endif