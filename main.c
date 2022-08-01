#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdlib.h>
#include <util/twi.h>
#include "uart.h"
#include "i2c.h"
#include "spi.h"
//#include "mcp4725.h"
#include "pcf8583.h"
#include "sd.h"
#include "fat32.h"
#include "ili9320.h"
#include "graphics.h"
#include "font.h"
#include "ft10x20.h"

//#include "color3.h"
void out_bcd_byte(uint8_t data) {
	uint8_t data2;
	data2 = data >> 4;
	data2 += 48;
	uart_send(data2);
	data2 = data & 0x0F;
	data2 += 48;
	uart_send(data2);
}

void out_hour_minute_seconds_hseconds_time(void) {
	char h, m, s, hs;
	PCF8583_ReadTime(&h, &m, &s, &hs);
	out_bcd_byte(h);
	uart_send('-');
	out_bcd_byte(m);
	uart_send('-');
	out_bcd_byte(s);
	uart_send('.');
	out_bcd_byte(hs);
	uart_send(13);
	uart_send(10);
}

/****
 * Load image from file directly into LCD screen
 */

unsigned long READ_cluster, READ_byteCounter, READ_fileSize, READ_firstSector;
unsigned int READ_k;
unsigned char READ_j, READ_error;

unsigned char readOpen(unsigned char *fileName) {
	struct dir_Structure *dir;

	READ_error = convertFileName(fileName); //convert fileName into FAT format
	if (READ_error)
		return -1;
	dir = findFiles(GET_FILE, fileName); //get the file location
	if (dir == 0) // if it's dirname
		return (-1);
	//if(flag == VERIFY) return (1);	//specified file name is already existing
	READ_cluster = (((unsigned long) dir->firstClusterHI) << 16)
			| dir->firstClusterLO;
	READ_fileSize = dir->fileSize;

	//initialize loop counters
	READ_byteCounter = 0;
	READ_j = 0;
	READ_k = 0;
	return 0;
}
unsigned char readByte(void) {
	uint8_t READ_byte;
	//read sector if k=0
	if (READ_j == 0) {
		READ_firstSector = getFirstSector(READ_cluster);
	}

	if (READ_k == 0) {
		SD_readSingleBlock(READ_firstSector + READ_j);
	}

	READ_byte = buffer[READ_k];
	if ((READ_byteCounter++) >= READ_fileSize) {
		READ_error = 0xFF;
		return 0;
	}
	//increment k
	READ_k++;

	if (READ_k >= 512) {
		READ_k = 0;
		READ_j++;
		if (READ_j >= sectorPerCluster) {
			READ_j = 0;
			READ_cluster = getSetNextCluster(READ_cluster, GET, 0);
			if (READ_cluster == 0) { //Error in getting cluster"
				READ_error = 0xFF;
				return 0;
			}
		}
	}
	return READ_byte;
}

unsigned char readImage(unsigned int x, unsigned int y, unsigned char *fileName) {
	uint8_t msb, lsb;
	uint16_t w, h;

	unsigned char colorMsb;
	unsigned char colorLsb;
//	unsigned char colorDup = 0;
	unsigned int color = 0;
	unsigned int x1, y1;
//	unsigned char t=0; //remove later

	readOpen(fileName);
	// ignore 2 bytes
	msb = readByte(); if (READ_error) return -1;
	lsb = readByte(); if (READ_error) return -1;

	msb = readByte(); if (READ_error) return -1;
	lsb = readByte(); if (READ_error) return -1;
	w = (msb << 8) | (lsb); // get image width  (MSB first)
	msb = readByte(); if (READ_error) return -1;
	lsb = readByte(); if (READ_error) return -1;
	h = (msb << 8) | (lsb); // get image width  (MSB first)

	// ignore 2 bytes
	msb = readByte(); if (READ_error) return -1;
	lsb = readByte(); if (READ_error) return -1;

	LCD_SetArea(x, y, x + w - 1, y + h - 1);

	for (y1 = 0; y1 < h; y1++) {
		for (x1 = 0; x1 < w; x1++) {
			colorMsb = readByte();
			colorLsb = readByte();
			color = ((uint16_t)colorMsb << 8) | colorLsb;		// merge color
			LCD_WrDat(color);
		}
	}
	LCD_SetArea(0, 0, GetMaxX(), GetMaxY());
	return 0;
}

/*
void writeFile2(unsigned char *fileName) {
	unsigned char j, data, error, fileCreatedFlag = 0, start = 0,
			appendFile = 0, sector;
	unsigned int i, firstClusterHigh = 0, firstClusterLow = 0, wpos;
	struct dir_Structure *dir;
	unsigned long cluster, nextCluster, prevCluster, firstSector, clusterCount,
			extraMemory;

	// # tylko sprawdŸ - czy plik istnieje
	j = readFile(VERIFY, fileName);
	wpos = 0;

	if (j == 1) {
		uart_send_string_from_FLASH(
				PSTR("  File already existing, appending data.."));
		appendFile = 1;
		cluster = appendStartCluster;
		clusterCount = 0;
		while (1) {
			nextCluster = getSetNextCluster(cluster, GET, 0);
			if (nextCluster == EOF)
				break;
			cluster = nextCluster;
			clusterCount++;
		}
		// wyznaczenie sektora do zapisu
		sector = (fileSize - (clusterCount * sectorPerCluster * bytesPerSector))
				/ bytesPerSector; //last sector number of the last cluster of the file
		start = 1;
//  appendFile();
//  return;
	} else if (j == 2)
		return; //invalid file name
	else {
		// od tego momentu jest zapis do pliku
		TX_NEWLINE;
		uart_send_string_from_FLASH(PSTR(" Creating File.."));

		cluster = getSetFreeCluster(NEXT_FREE, GET, 0);
		if (cluster > totalClusters)
			cluster = rootCluster;

		cluster = searchNextFreeCluster(cluster);
		if (cluster == 0) {
			TX_NEWLINE;
			uart_send_string_from_FLASH(PSTR(" No free cluster!"));
			return;
		}
		getSetNextCluster(cluster, SET, EOF); //last cluster of the file, marked EOF

		firstClusterHigh = (unsigned int) ((cluster & 0xffff0000) >> 16);
		firstClusterLow = (unsigned int) (cluster & 0x0000ffff);
		fileSize = 0;
	}
	// tutaj mamy wyznaczony kluster ju¿
	while (1) {
		if (start) {
			start = 0;
			startBlock = getFirstSector(cluster) + sector;
			SD_readSingleBlock(startBlock);
			i = fileSize % bytesPerSector;
			j = sector;
		} else {
			startBlock = getFirstSector(cluster);
			i = 0;
			j = 0;
		}
		TX_NEWLINE;
		uart_send_string_from_FLASH(PSTR(" Enter text (end with ~):"));
		do {
			if (wpos > 21) {
				data = 0x00;
			} else {
				//data = czas_temp[wpos];
				if (data == 0x00) {
					data = '~';
				}
			}
			wpos++;
			uart_send(data);
			buffer[i++] = data;
			fileSize++;
			if (i == 512) {
				i = 0;
				error = SD_writeSingleBlock(startBlock);
				j++;
				if (j == sectorPerCluster) {
					j = 0;
					break;
				}
				startBlock++;
			}
		} while (data != '~');

		if (data == '~') {
			fileSize--; //to remove the last entered '~' character
			i--;
			for (; i < 512; i++) //fill the rest of the buffer with 0x00
				buffer[i] = 0x00;
			error = SD_writeSingleBlock(startBlock);

			break;
		}
		prevCluster = cluster;
		cluster = searchNextFreeCluster(prevCluster); //look for a free cluster starting from the current cluster
		if (cluster == 0) {
			TX_NEWLINE;
			uart_send_string_from_FLASH(PSTR(" No free cluster!"));
			return;
		}
		getSetNextCluster(prevCluster, SET, cluster);
		getSetNextCluster(cluster, SET, EOF); //last cluster of the file, marked EOF
	}
	getSetFreeCluster(NEXT_FREE, SET, cluster); //update FSinfo next free cluster entry

	if (appendFile) //executes this loop if file is to be appended
	{
		SD_readSingleBlock(appendFileSector);
		dir = (struct dir_Structure *) &buffer[appendFileLocation];
		extraMemory = fileSize - dir->fileSize;
		dir->fileSize = fileSize;
		SD_writeSingleBlock(appendFileSector);
		freeMemoryUpdate(REMOVE, extraMemory); //updating free memory count in FSinfo sector;

		TX_NEWLINE;
		uart_send_string_from_FLASH(PSTR(" File appended!"));
		TX_NEWLINE;
		return;
	}

	//executes following portion when new file is created

	prevCluster = rootCluster; //root cluster

	while (1) {
		firstSector = getFirstSector(prevCluster);
		for (sector = 0; sector < sectorPerCluster; sector++) {
			SD_readSingleBlock(firstSector + sector);
			for (i = 0; i < bytesPerSector; i += 32) {
				dir = (struct dir_Structure *) &buffer[i];
				if (fileCreatedFlag) //to mark last directory entry with 0x00 (empty) mark
				{ //indicating end of the directory file list
					dir->name[0] = 0x00;
					return;
				}
				if ((dir->name[0] == EMPTY) || (dir->name[0] == DELETED)) //looking for an empty slot to enter file info
						{
					for (j = 0; j < 11; j++)
						dir->name[j] = fileName[j];
					dir->attrib = ATTR_ARCHIVE; //settting file attribute as 'archive'
					dir->NTreserved = 0; //always set to 0
					dir->timeTenth = 0; //always set to 0
					dir->createTime = 0x9684; //fixed time of creation
					dir->createDate = 0x3a37; //fixed date of creation
					dir->lastAccessDate = 0x3a37; //fixed date of last access
					dir->writeTime = 0x9684; //fixed time of last write
					dir->writeDate = 0x3a37; //fixed date of last write
					dir->firstClusterHI = firstClusterHigh;
					dir->firstClusterLO = firstClusterLow;
					dir->fileSize = fileSize;

					SD_writeSingleBlock(firstSector + sector);
					fileCreatedFlag = 1;

					TX_NEWLINE;
					TX_NEWLINE;
					uart_send_string_from_FLASH(PSTR(" File Created!"));

					freeMemoryUpdate(REMOVE, fileSize); //updating free memory count in FSinfo sector

				}
			}
		}

		cluster = getSetNextCluster(prevCluster, GET, 0);
		if (cluster > 0x0ffffff6) {
			if (cluster == EOF) //this situation will come when total files in root is multiple of (32*sectorPerCluster)
			{
				cluster = searchNextFreeCluster(prevCluster); //find next cluster for root directory entries
				getSetNextCluster(prevCluster, SET, cluster); //link the new cluster of root to the previous cluster
				getSetNextCluster(cluster, SET, EOF); //set the new cluster as end of the root directory
			} else {
				uart_send_string_from_FLASH(PSTR("End of Cluster Chain"));
				return;
			}
		}
		if (cluster == 0) {
			uart_send_string_from_FLASH(PSTR("Error in getting cluster"));
			return;
		}
		prevCluster = cluster;
	}
	return;
}
*/
void selftest() {
	int sd_ok = 0;

	TX_NEWLINE;
	uart_send_string_from_FLASH(PSTR("SELFTEST:SD"));
	TX_NEWLINE;
	SD_init();
	SPI_HIGH_SPEED;
	//SPI_SD;
	unsigned char error;
	error = 0;
	sd_ok = 1;
	error = getBootSectorData();
	if (error) {
		sd_ok = 0;
		uart_send_string_from_FLASH(PSTR("Brak SD z FAT32!"));
		//beep(BEEP_ALERT);
		_delay_ms(333);
	} else {
		//printf("\nOK!\n");
		memoryStatistics();
	}
	return;
}

//========================================================
//
//========================================================

int main() {
	// uint8_t u8Data = 11;
	uint16_t color[] = { 0xf800, 0x001f, 0xffe0, 0x0000, 0xffff, 0x07ff, 0xf81f,
			0x07e0 };

	unsigned int Value = 0;
	//unsigned char filename[] = "IMAGE001.BIN";

	unsigned char bb;
	cli();
	//PORTB = 0xED; //
	DDRB = 0xBF; //MISO line input, rest output

	// port a i C - wyjscia
	DDRA = 0xFF; //DB8..15
	DDRC = 0xFF; //DB0..7
	DDRD = 0xFF;

	spi_init();
	MCUCR = 0x00;
	GICR = 0x00;
	TIMSK = 0x00;
	_delay_ms(50);

	sei();
	//enable global interrupts
	uart_init();

	LCD_InitPort();
	printf(PSTR("START\n"));
	LCD_Reset2();
	LCD_BL_ON();
	//LCD_Clear(MAGENTA);

	for (uint8_t n = 0; n < 8; n++) {
		SetColor(color[n]);
		RectangleFill(0, 40 * n, GetMaxX(), 40 * (n + 1) - 1, 0);
	}

	//LcdFont(ft18x34);
	//LcdFont(ft10x20);
	LcdFont(ft10x20);
	SetFgColor(WHITE);
	PutText(0, 0, GetMaxX(), 30, "ELIUM GmbH", ALINE_CENTER);
	//SetBkColor(RED);
	PutText(0, GetMaxY() - 30, GetMaxX(), GetMaxY(), "www.elium.de", ALINE_CENTER);

	//LCD_DrawImage(56, 96, gIcon_color3);

	//DDRA |= (1 << 7); //ser port PA7 with signal diode as output
	//for (mint i = 0; i < 3; i++) //blink twice
	//{
	//   PORTA ^= _BV(PA7);
	//   _delay_ms(500);
	//}
	//PORTA ^= _BV(PA7);
	SetColor(WHITE);
	//LCD_DrawImage(0, 96, gIcon_color3);
	//CircleFill(120,160,50,0);
	selftest();
	//writeFile2(filename);
	//readOpen("file.xxx");
//	readOpen("IMAGE001.BIN");
//	while (!READ_error) {
//		bb = readByte();
//		printf("%02x,",bb);
//	}

	readImage(0, 0, "F.BIN");
	printf(PSTR("\nKoniec\n"));
	while (1) {
		//out_hour_minute_seconds_time();
		printf(".");
//out_hour_minute_seconds_hseconds_time();
		//uart_send(u8Data+48);
		_delay_ms(200);
		Value++;
		if (Value > 4095)
			Value = 0;

///////////////////////////////////////////
//		przy 11,0592 MHz I2C cos fiksuje :(
//
		//MCP4725_WriteDAC(Value);
		//PORTA ^= _BV(PA7);
		//if (u8Data>128) u8Data=32;
		//u8Data++;
	}
}
//========================================================
