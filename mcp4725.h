/*
 * mcp4725.h
 *
 *  Created on: 06-09-2011
 *      Author: admin
 */

#ifndef MCP4725_H_
#define MCP4725_H_

#define MCP4725_ID 0xC0
#define MCP4725_ADDR 0x00

#include "i2c.h"
void MCP4725_WriteDAC(unsigned int Value);

#endif /* MCP4725_H_ */
