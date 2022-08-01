/***********************************************************************************************
*	  			  SSD1289 color Graphical LCD Display Driver
* File name		: SSD1289.c
* Programmer 	: jaruwit supa
* Web           : www.circuitidea.com
* Note			: SSD1289 16 bit interface.for 8 bit use 74lv573 to latch HI byte
* Language		: avrGCC
* Hardware		: atmega16
* Date			: 01/05/2009
*************************************************************************************************
* DESCRIPTION
* ===========
* Display controller chip is ssd1289
* 16-bit data bus mode 8080
* 8-bit use 74LV573 latch Hi byte
*
* 28/11/2009     change hardware to v2.0. To support arduino I2C function.
*
* config parameter in ssd1289.h
* #define LCD_8_BIT_MODE	  // 8 bit bus data using latch. *** Need jumpper for 8 bit ***
* #define LCD_BL_HARDWARE	  // using black light internal jumper
* #define LCD_RESET_HARDWARE  // using hardware control reset pin to reset
* #define LCD_WRITE_ONLY	  // write only mode no read back
* #define Horizontal		  // Horizontal or vertical
* #define Reverse			  // reverse direction
*
************************************************************************************************/

/* _____STANDARD INCLUDES____________________________________________________ */
#include <avr/io.h>
#include <avr/pgmspace.h>

/* _____PROJECT INCLUDES_____________________________________________________ */
#include "ili9320.h"

/* _____LOCAL VARIABLES______________________________________________________ */
uint16_t _color = GREEN;

/* _____PRIVATE FUNCTIONS____________________________________________________ */

/********************************************************************************************************
* Function    : void LCD_WaitMs(unsigned int ms)
* Description : waits (pauses) for ms milliseconds (assumes internal clock at 8MHz)
* Input       : ms is wait milliseconds
* Returns     : none
* Notes		  : none
*********************************************************************************************************/
void LCD_WaitMs(unsigned int ms)
{
	int i;

	while (ms-- > 0)
	{
		// 8192 (8k) clock cycles for 1ms; each time through loop
		  // is 5 cycles (for loop control + nop)
		for (i = 0; i < 1638; ++i)
				asm volatile ("nop");
	}
}

/********************************************************************************************************
* Function    : void LCD_WrCmd(unsigned char cmd)
* Description : This function performs low level command write to LCD
* Input       : cmd - is the command written to the LCD module
* Returns     : none
* Notes		  : Hardware specific.
*********************************************************************************************************/
void LCD_WrCmd(unsigned char cmd)
{
    LCD_CLR_CS();	// clear CS pin to ENABLE LCD

	LCD_CLR_RS();
	//LCD_SET_DBH(0);
	asm volatile ("nop");
	//asm volatile ("nop");
	LCD_SET_DBH(cmd >> 8);
	//LCD_WaitMs(1);
	//LCD_SET_DBL(0);
	//asm volatile ("nop");
	asm volatile ("nop");
	LCD_SET_DBL(cmd);
	LCD_CLR_WR();
	LCD_SET_WR();

    LCD_SET_CS();	// set CS pin to DISABLE LCD
	LCD_SET_RS();	// set default data mode
	//LCD_WaitMs(1);
}

/********************************************************************************************************
* Function    : void LCD_WrDat(unsigned int val)
* Description : This function performs low level display data write to LCD
* Arguments   : val - is the data written to the LCD module
* Returns     : none
* Notes		  : Hardware specific.
********************************************************************************************************/
void LCD_WrDat(unsigned int val)
{
    LCD_CLR_CS();				// clear CS pin to ENABLE LCD

//	LCD_SET_RS();				// use default setting
//	LCD_SET_DBH(0);
//	asm volatile ("nop");
	asm volatile ("nop");
	LCD_SET_DBH(val>>8);
//	LCD_WaitMs(1);
//	LCD_SET_DBL(0);
//	asm volatile ("nop");
	asm volatile ("nop");
	LCD_SET_DBL(val);
	LCD_CLR_WR();
	LCD_SET_WR();

    LCD_SET_CS();	// set CS pin to DISABLE LCD
//	LCD_WaitMs(1);
}

inline void LCD_Write_COM_DATA(unsigned char cmd, unsigned int val) {
	LCD_WrCmd(cmd);
	LCD_WrDat(val);
}

/*********************************************************************************************************
* Function:  void LCD_SetReg(unsigned char index, unsigned int val)
* Input       : index - register number
*             : val   - value to be set
* Returns     : none
* Notes		  : Hardware specific.
**********************************************************************************************************/
void LCD_SetReg(unsigned char index, unsigned int val)
{
	LCD_WrCmd(index);
	LCD_WrDat(val);
}

/*********************************************************************************************************
* Function    : unsigned int LCD_GetReg(unsigned char index)
* Description : This function performs low level read data register from LCD
* Input:      : index - register number
* Return      : register data
* Notes		  : none
**********************************************************************************************************/
#ifndef LCD_8_BIT
unsigned int LCD_GetReg(unsigned char index)
{
	unsigned int ret;

    LCD_CLR_CS();	// clear  CS pin to ENABLE LCD

	LCD_CLR_RS();
	LCD_SET_DBH(index >> 8);
	LCD_SET_DBL(index);
	LCD_CLR_WR();
	LCD_SET_WR();

	LCD_INPUT();				// input mode
	LCD_CLR_RD();
	asm volatile ("nop");
	ret = LCD_GET_DBH();
	ret <<= 8;
	ret |= LCD_GET_DBL();
	LCD_SET_RD();
    LCD_SET_CS();	// set CS pin to DISABLE LCD

	LCD_OUTPUT();				// output data
	return ret;
}
#endif
/*********************************************************************************************************
* Function    : void LCD_InitPort(void)
* Description : This function init lcd io
* Input       : none
* Returns     : none
* Notes		  : none
**********************************************************************************************************/
void LCD_InitPort(void)
{
	LCD_MODE();		// virtual init for 8/16 bit mode. make sure set jumper for 8/16 bit mode

	// set default
	LCD_SET_CS();
	LCD_SET_RS();
	LCD_SET_WR();
	LCD_SET_RD();
	LCD_CLR_RST();

	// init direction
	LCD_DIR_CS(1);
	LCD_DIR_RS(1);
	LCD_DIR_WR(1);
	LCD_DIR_RD(1);
	LCD_DIR_RST(1);
#ifdef LCD_8_BIT_MODE
	LCD_DIR_LATCH(1);
#endif

//	LCD_SET_DBH(0xFF);
//	LCD_SET_DBL(0xFF);
	LCD_OUTPUT();

	// reset module
	LCD_WaitMs(10);
	LCD_SET_RST();
	LCD_WaitMs(50);
}

/* _____PUBLIC FUNCTIONS_____________________________________________________ */

/*********************************************************************************************************
* Function    : void LCD_Reset(void)
* Description : This function reser lcd module
* Input:      : none
* Returns      : none
* Notes		  : none
**********************************************************************************************************/
void LCD_Reset(void)
{
	LCD_InitPort();
	LCD_Write_COM_DATA(0xe5, 0x8000);
	LCD_Write_COM_DATA(0x00, 0x0001);
	LCD_Write_COM_DATA(0x01, 0x0100);
	LCD_Write_COM_DATA(0x02, 0x0700);
	LCD_Write_COM_DATA(0x03, 0x1030);
	LCD_Write_COM_DATA(0x04, 0x0000);
	LCD_Write_COM_DATA(0x08, 0x0202);
	LCD_Write_COM_DATA(0x09, 0x0000);
	LCD_Write_COM_DATA(0x0A, 0x0000);
	LCD_Write_COM_DATA(0x0C, 0x0000);
	LCD_Write_COM_DATA(0x0D, 0x0000);
	LCD_Write_COM_DATA(0x0F, 0x0000);
	//-----Power On sequence-----------------------
	LCD_Write_COM_DATA(0x10, 0x0000);
	LCD_Write_COM_DATA(0x11, 0x0007);
	LCD_Write_COM_DATA(0x12, 0x0000);
	LCD_Write_COM_DATA(0x13, 0x0000);
	LCD_WaitMs(50);
	LCD_Write_COM_DATA(0x10, 0x17B0);
	LCD_Write_COM_DATA(0x11, 0x0007);
	LCD_WaitMs(10);
	LCD_Write_COM_DATA(0x12, 0x013A);
	LCD_WaitMs(10);
	LCD_Write_COM_DATA(0x13, 0x1A00);
	LCD_Write_COM_DATA(0x29, 0x000c);
	LCD_WaitMs(10);
	//-----Gamma control-----------------------
	LCD_Write_COM_DATA(0x30, 0x0000);
	LCD_Write_COM_DATA(0x31, 0x0505);
	LCD_Write_COM_DATA(0x32, 0x0004);
	LCD_Write_COM_DATA(0x35, 0x0006);
	LCD_Write_COM_DATA(0x36, 0x0707);
	LCD_Write_COM_DATA(0x37, 0x0105);
	LCD_Write_COM_DATA(0x38, 0x0002);
	LCD_Write_COM_DATA(0x39, 0x0707);
	LCD_Write_COM_DATA(0x3C, 0x0704);
	LCD_Write_COM_DATA(0x3D, 0x0807);
	//-----Set RAM area-----------------------
	LCD_Write_COM_DATA(0x50, 0x0000);
	LCD_Write_COM_DATA(0x51, 0x00EF);
	LCD_Write_COM_DATA(0x52, 0x0000);
	LCD_Write_COM_DATA(0x53, 0x013F);
	LCD_Write_COM_DATA(0x60, 0x2700);
	LCD_Write_COM_DATA(0x61, 0x0001);
	LCD_Write_COM_DATA(0x6A, 0x0000);
	LCD_Write_COM_DATA(0x21, 0x0000);
	LCD_Write_COM_DATA(0x20, 0x0000);
	//-----Partial Display Control------------
	LCD_Write_COM_DATA(0x80, 0x0000);
	LCD_Write_COM_DATA(0x81, 0x0000);
	LCD_Write_COM_DATA(0x82, 0x0000);
	LCD_Write_COM_DATA(0x83, 0x0000);
	LCD_Write_COM_DATA(0x84, 0x0000);
	LCD_Write_COM_DATA(0x85, 0x0000);
	//-----Panel Control----------------------
	LCD_Write_COM_DATA(0x90, 0x0010);
	LCD_Write_COM_DATA(0x92, 0x0000);
	LCD_Write_COM_DATA(0x93, 0x0003);
	LCD_Write_COM_DATA(0x95, 0x0110);
	LCD_Write_COM_DATA(0x97, 0x0000);
	LCD_Write_COM_DATA(0x98, 0x0000);
	//-----Display on-----------------------
	LCD_Write_COM_DATA(0x07, 0x0173);
	LCD_WaitMs(50);
}

void LCD_Reset2()
{
	LCD_WrCmd(0x0007);
	LCD_WrDat(0x0021);

	LCD_WrCmd(0x0000);
	LCD_WrDat(0x0001);

	LCD_WrCmd(0x0007);
	LCD_WrDat(0x0023);

	LCD_WrCmd(0x0010);
	LCD_WrDat(0x0000);

	LCD_WaitMs(90);

	LCD_WrCmd(0x0007);
	LCD_WrDat(0x0033);
}

/*********************************************************************
* Function    : void LCD_SetCursor(unsigned int x, unsigned int y)
* Description : set start address of lcd ram
* Input       : x,y - pixel coordinates
* Return      : none
* Note        : set start address change
********************************************************************/
void LCD_SetCursor(unsigned int x, unsigned int y)
{
#ifdef Horizontal
	LCD_SetReg(0x4E,x); // initial settings for the GDDRAM X address in the address counter (AC).
	LCD_SetReg(0x4F,y); // initial settings for the GDDRAM Y address in the address counter (AC).
#else
	LCD_SetReg(0x4E,y); // initial settings for the GDDRAM X address in the address counter (AC).
	LCD_SetReg(0x4F,x); // initial settings for the GDDRAM Y address in the address counter (AC).
#endif
    LCD_WrCmd(0x22);
}

/*********************************************************************
* Function    : void LCD_SetArea(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
* Description : set paint area
* Input       : x1,y1,x2,y2 - pixel coordinates
* Return      : none
* Note        : Side Effects: paint area change
********************************************************************/
void LCD_SetArea(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2)
{
#ifdef Horizontal
    LCD_WrCmd(0x44); LCD_WrDat((x2 << 8) | x1);    // Source RAM address window
    LCD_WrCmd(0x45); LCD_WrDat(y1);    // Gate RAM address window
    LCD_WrCmd(0x46); LCD_WrDat(y2);    // Gate RAM address window
#else
    LCD_WrCmd(0x44); LCD_WrDat((y2 << 8) | y1);    // Source RAM address window
    LCD_WrCmd(0x45); LCD_WrDat(x1);    // Gate RAM address window
    LCD_WrCmd(0x46); LCD_WrDat(x2);    // Gate RAM address window
#endif
	LCD_WaitMs(1);
	LCD_SetCursor(x1, y1);
}

/*********************************************************************
* Function    : void LCD_PutPixel(unsigned int x, unsigned int y)
* Description : puts pixel
* Input       : x,y - pixel coordinates
* Output      : none
* Note        : none
********************************************************************/
void LCD_PutPixel(unsigned int x, unsigned int y)
{
    LCD_SetCursor(x,y);
	LCD_WrDat(_color);
}

/*********************************************************************
* Function    : void LCD_Bar(unsigned int left, unsigned int top, unsigned int right, unsigned int bottom)
* Description : draws rectangle filled with current color
* Input       : left,top - top left corner coordinates,
*             : right,bottom - bottom right corner coordinates
* Output      : none
* Note        :
*  CGRAM map
*  00000...000EF line0
*  00100...001EF line1
*  00200...002EF line2
*	....
*  13F00...13FEF line320
*  yyyxx...yyyxx
*  address x = x
*  address y = y << 8
*  new line y = y + 0x100
********************************************************************/
void LCD_Rect(unsigned int left, unsigned int top, unsigned int right, unsigned int bottom, unsigned int color)
{
	/*register*/ unsigned int x,y;

	LCD_SetArea(left, top, right, bottom);
	LCD_OPEN_WRITE();
    for(y=top; y<=bottom; y++)
	{
        for(x=left; x<=right; x++)
		{
			LCD_WrDat(color);
        }
    }
	LCD_CLOSE();
	LCD_SetArea(0, 0, GetMaxX(), GetMaxY());
}

/*********************************************************************
* Function    : void LCD_Clear(unsigned int color)
* Description : fill display with color
* Input       : color - paint color
* Output      : none
* Note        : none
********************************************************************/
void LCD_Clear(unsigned int color)
{
//	LCD_WrCmd(0x0007);LCD_WrDat(0x0221); // Display Control: display off
	LCD_Rect(0, 0, GetMaxX(), GetMaxY(), color);
//	LCD_WrCmd(0x0007);LCD_WrDat(0x0233); // Display Control: display on
}

/*********************************************************************
* Function    : void DrawSymbol(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned char t, unsigned char *pImage)
* Description : display image array to lcd
* Input       : x,y    - pixel coordinates
*             : w      - width
*             : h      - height
*             : t      - compress type(0 = none(RGB565), 1 = compress(RGB5<compress bit>55)
*			  : pImage - FLASH array of image
* Output      : none
* Note        : none
********************************************************************/
void LCD_DrawSymbol(unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned char t, const unsigned char *pImage)
{
	unsigned char colorMsb;
	unsigned char colorLsb;
	unsigned char colorDup = 0;
	unsigned int color=0;
	unsigned int x1,y1;

	// set draw area
	LCD_SetArea(x,y,x+w-1,y+h-1);
	for (y1 = 0; y1<h ; y1++)
	{
		for (x1 = 0; x1<w ; x1++)
		{
			if (!colorDup)
			{
				colorMsb = pgm_read_byte(pImage++);
				colorLsb = pgm_read_byte(pImage++);
				if (t == 0x01)
				{
					colorDup = colorLsb & 0x20;			// get duplicate flag
					colorLsb = colorLsb | 0x20;			// remove duplicate flag and add more white
				}
				if (colorDup)
					colorDup = pgm_read_byte(pImage++);	// get duplicate no
				color = ((uint16_t)colorMsb << 8) | colorLsb;		// merge color
			}
			else
			{
				colorDup--;
			}
			LCD_WrDat(color);
		}
	}
	LCD_SetArea(0, 0, GetMaxX(), GetMaxY());
}

/*********************************************************************
* Function    : void DrawImage(unsigned int x, unsigned int y, unsigned char *pImage)
* Description : display image array to lcd
* Input       : x,y    - pixel coordinates
*			  : pImage - FLASH array of image
* Output      : none
* Note        : ** modify image format here **
*   image format
*   <type 1 byte><width 2 byte><height 2 btye><image array n byte>
********************************************************************/
void LCD_DrawImage(unsigned int x, unsigned int y, const unsigned char *pImage)
{
	unsigned char t;
	unsigned int w, h;

	// get image information
	t = pgm_read_byte(pImage++);			// image type
	w = pgm_read_byte(pImage++);			// width
	w = (w << 8) | pgm_read_byte(pImage++);
	h = pgm_read_byte(pImage++);			// Height
	h = (h << 8) | pgm_read_byte(pImage++);

	LCD_DrawSymbol(x, y, w, h, t, pImage);
}

