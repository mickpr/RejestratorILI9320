/*
 * pcf8583.h
 *
 *  Created on: 06-09-2011
 *      Author: admin
 */

#ifndef PCF8583_H_
#define PCF8583_H_

#include "i2c.h"

#define PCF8583_ID 0xA0
#define PCF8583_ADDR 0x00

void PCF8583_ReadTime(	char *h,char *m, char *s,char *hs);
void PCF8583_SetTime(	char *h,char *m, char *s,char *hs);

char bcd2dec(char num);
char dec2bcd(char num);

#endif /* PCF8583_H_ */
