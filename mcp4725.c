#include "mcp4725.h"
#include <avr\delay.h>
void MCP4725_WriteDAC(unsigned int Value)
{
	unsigned int temp;
	temp = Value >> 8; // i tak tylko 4 m³odsze bity (max wartosæ 4095-12bitów)
	i2c_start(MCP4725_ID, MCP4725_ADDR,I2C_WRITE);
	i2c_write((char)temp);	// 4 najstarsze bity Wartoci (przesuniête do bitów 0..3)
	i2c_write((char)Value);	// 8 najm³odszych bitów wartosci.
	i2c_write(0);
	i2c_stop();
}

/*
' ZAPIS mcp4725 (dac 12 BIT).... dziala!!!
Sub Writedac(byval Value As Integer)
Dim I1 As Integer
Dim B1 As Byte , B2 As Byte , B3 As Byte

   I1 = Value
   Shift I1 , Right , 9
   B1 = I1
   B2 = Value
   B3 = 0
   I2cstart
   I2cwbyte &HC0
   I2cwbyte B1
   I2cwbyte B2
   I2cwbyte B3
   I2cstop
   Waitms 10
End Sub
*/
