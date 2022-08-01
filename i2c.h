/*
 * i2c.h
 *
 *  Created on: 06-09-2011
 *      Author: admin
 */

#ifndef I2C_H_
#define I2C_H_

/*
 * I2C.C
 *
 *  Created on: 06-09-2011
 *      Author: admin
 */

#include <compat/twi.h>

#define MAX_TRIES 50
#define I2C_START 0
#define I2C_DATA 1
#define I2C_DATA_ACK 2
#define I2C_STOP 3
#define ACK 1
#define NACK 0
#define I2C_READ 1
#define I2C_WRITE 0

unsigned char i2c_transmit(unsigned char type);
char i2c_start(unsigned int dev_id, unsigned int dev_addr, unsigned char rw_type);
void i2c_stop(void);
char i2c_write(char data);
char i2c_read(char *data,char ack_type);


#endif /* I2C_H_ */
