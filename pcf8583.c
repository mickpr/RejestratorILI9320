/*
 * pcf8583.c
 *
 *  Created on: 06-09-2011
 *      Author: admin
 */
#include "pcf8583.h"

void PCF8583_ReadTime(	char *h,
						char *m,
						char *s,
						char *hs)
{

	i2c_start(PCF8583_ID, PCF8583_ADDR,I2C_WRITE);
	i2c_write(0);
	i2c_start(PCF8583_ID, PCF8583_ADDR,I2C_READ);
	i2c_read(hs, ACK); // control byte
	i2c_read(hs, ACK); // hundred of seconds
	i2c_read(s, ACK); // seconds
	i2c_read(m, ACK); // minutes
	i2c_read(h, NACK); // hours
	i2c_stop();
}

void PCF8583_SetTime(	char *h,
						char *m,
						char *s,
						char *hs)
{
	i2c_start(PCF8583_ID, PCF8583_ADDR,I2C_WRITE);
	i2c_write(0);
	i2c_write(*hs);
	i2c_write(*s);
	i2c_write(*m);
	i2c_write(*h);
	i2c_stop();

}

//------------------------------------------------
// Convert Binary Coded Decimal (BCD) to Decimal
char bcd2dec(char num)
{
  return ((num/16 * 10) + (num % 16));
}
// Convert Decimal to Binary Coded Decimal (BCD)
char dec2bcd(char num)
{
  return ((num/10 * 16) + (num % 10));
}
