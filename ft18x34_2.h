/*
    created with FontEditor written by H. Reddmann
    HaReddmann at t-online dot de

    File Name           : ft18x34_2.h
    Date                : 2011-10-07
    Font size in bytes  : 0x0D5B, 3419
    Font width          : 16
    Font height         : 33
    Font first char     : 0x20
    Font last char      : 0x7E
    Font bits per pixel : 1
    Font is compressed  : false

    The font data are defined as

    struct _FONT_ {
     // common shared fields
       uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
       uint8_t    font_Width_in_Pixel_for_fixed_drawing;
       uint8_t    font_Height_in_Pixel_for_all_Characters;
       uint8_t    font_Bits_per_Pixels;
                    // if MSB are set then font is a compressed font
       uint8_t    font_First_Char;
       uint8_t    font_Last_Char;
       uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
                    // for each character the separate width in pixels,
                    // characters < 128 have an implicit virtual right empty row
                    // characters with font_Char_Widths[] == 0 are undefined

     // if compressed font then additional fields
       uint8_t    font_Byte_Padding;
                    // each Char in the table are aligned in size to this value
       uint8_t    font_RLE_Table[3];
                    // Run Length Encoding Table for compression
       uint8_t    font_Char_Size_in_Bytes[font_Last_Char - font_First_Char +1];
                    // for each char the size in (bytes / font_Byte_Padding) are stored,
                    // this get us the table to seek to the right beginning of each char
                    // in the font_data[].

     // for compressed and uncompressed fonts
       uint8_t    font_data[];
                    // bit field of all characters
    }
*/

#ifndef ft18x34_2_H
#define ft18x34_2_H

#include <inttypes.h>
#include <avr/pgmspace.h>

#define ft18x34_2_WIDTH 16
#define ft18x34_2_HEIGHT 33

unsigned char __attribute__ ((progmem)) ft18x34_2[] = {
    0x0D, 0x5B, 0x10, 0x21, 0x01, 0x20, 0x7E,
    0x0A, 0x02, 0x06, 0x0A, 0x09, 0x0E, 0x09, 0x03, 0x06, 0x06, 0x07, 0x08, 0x03, 0x07, 0x03, 0x07,
    0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x03, 0x03, 0x06, 0x07, 0x06, 0x09,
    0x0F, 0x0A, 0x0A, 0x0A, 0x0A, 0x09, 0x08, 0x0B, 0x0A, 0x02, 0x06, 0x0A, 0x08, 0x0F, 0x0C, 0x0C,
    0x0A, 0x0C, 0x0A, 0x0B, 0x0A, 0x0A, 0x0C, 0x0E, 0x0B, 0x0C, 0x0A, 0x04, 0x08, 0x04, 0x08, 0x09,
    0x05, 0x09, 0x09, 0x08, 0x09, 0x0A, 0x07, 0x0A, 0x09, 0x02, 0x03, 0x0A, 0x02, 0x0E, 0x09, 0x09,
    0x09, 0x09, 0x06, 0x09, 0x07, 0x09, 0x09, 0x0E, 0x09, 0x09, 0x08, 0x06, 0x02, 0x06, 0x0A,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x0D, 0x00, 0x80, 0xFF,
    0x1B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x60,
    0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00,
    0x88, 0x1F, 0x00, 0x00, 0xF0, 0x07, 0x00, 0x00, 0x7C, 0x02, 0x00, 0x00, 0x4C, 0x04, 0x00, 0x00,
    0x80, 0xE8, 0x01, 0x00, 0x00, 0x7F, 0x00, 0x00, 0xC0, 0x2F, 0x00, 0x00, 0xC0, 0x45, 0x00, 0x00,
    0x00, 0x88, 0x00, 0x00, 0x00, 0x38, 0x0C, 0x00, 0x00, 0xF8, 0x38, 0x00, 0x00, 0x18, 0xC3, 0x00,
    0x00, 0x30, 0x06, 0x01, 0x00, 0xF0, 0xFF, 0x0F, 0x00, 0xC0, 0x10, 0x04, 0x00, 0x80, 0x61, 0x0C,
    0x00, 0x00, 0x8E, 0x0F, 0x00, 0x00, 0x18, 0x0E, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0xF8, 0x01,
    0x00, 0x00, 0x08, 0x04, 0x01, 0x00, 0x10, 0x08, 0x03, 0x00, 0xC0, 0x8F, 0x01, 0x00, 0x00, 0x8F,
    0x01, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x60, 0x3C, 0x00, 0x00, 0x60,
    0xFC, 0x00, 0x00, 0x30, 0x04, 0x02, 0x00, 0x20, 0x08, 0x04, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00,
    0x80, 0x07, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0xBC, 0x1F, 0x00, 0x00, 0xFC, 0x43, 0x00, 0x00,
    0x18, 0x87, 0x00, 0x00, 0xB0, 0x1B, 0x01, 0x00, 0xC0, 0x63, 0x02, 0x00, 0x00, 0x80, 0x07, 0x00,
    0x00, 0x80, 0x0F, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00,
    0x00, 0x04, 0x00, 0x00, 0x00, 0xC0, 0x7F, 0x00, 0x00, 0xE0, 0xFF, 0x07, 0x00, 0xF0, 0x00, 0x1E,
    0x00, 0x70, 0x00, 0xE0, 0x00, 0x30, 0x00, 0x80, 0x03, 0x30, 0x00, 0x00, 0x0C, 0x20, 0x00, 0x00,
    0x18, 0x80, 0x01, 0x00, 0x18, 0x00, 0x06, 0x00, 0x1C, 0x00, 0x78, 0x00, 0x1F, 0x00, 0xC0, 0xFF,
    0x0F, 0x00, 0x00, 0xFE, 0x03, 0x00, 0x80, 0x0D, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x08,
    0x00, 0x00, 0x00, 0xFE, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x00, 0x00, 0x60,
    0x03, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
    0xF0, 0x1F, 0x00, 0x00, 0xE0, 0x3F, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,
    0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x00, 0x58, 0x00, 0x00, 0x00, 0x70, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x30,
    0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0xC0,
    0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x18,
    0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0xE0, 0x7F, 0x00, 0x00, 0x60,
    0x80, 0x01, 0x00, 0x60, 0x00, 0x06, 0x00, 0x40, 0x00, 0x08, 0x00, 0x80, 0x00, 0x10, 0x00, 0x00,
    0x03, 0x30, 0x00, 0x00, 0x0C, 0x30, 0x00, 0x00, 0xF0, 0x3F, 0x00, 0x00, 0xC0, 0x1F, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
    0x00, 0x03, 0x00, 0x00, 0x00, 0xFE, 0x7F, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0F, 0x00, 0x00, 0x0F, 0x1F,
    0x00, 0x00, 0x03, 0x23, 0x00, 0x00, 0x02, 0x47, 0x00, 0x00, 0x04, 0x86, 0x00, 0x00, 0x08, 0x0E,
    0x01, 0x00, 0x10, 0x0C, 0x02, 0x00, 0x60, 0x1C, 0x04, 0x00, 0x80, 0x1F, 0x08, 0x00, 0x00, 0x1E,
    0x10, 0x00, 0x00, 0x08, 0x0C, 0x00, 0x00, 0x1C, 0x38, 0x00, 0x00, 0x0C, 0xC0, 0x00, 0x00, 0x08,
    0x00, 0x01, 0x00, 0x10, 0x04, 0x02, 0x00, 0x20, 0x08, 0x04, 0x00, 0x40, 0x10, 0x08, 0x00, 0x80,
    0x51, 0x18, 0x00, 0x00, 0xBE, 0x19, 0x00, 0x00, 0x3C, 0x3E, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00,
    0x00, 0x1E, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00, 0x87, 0x00, 0x00,
    0x00, 0x03, 0x01, 0x00, 0x00, 0x03, 0x02, 0x00, 0x00, 0xFE, 0x7F, 0x00, 0x00, 0xFC, 0xFF, 0x00,
    0x00, 0x00, 0x10, 0x00, 0x00, 0x80, 0xC3, 0x00, 0x00, 0xE0, 0x87, 0x03, 0x00, 0x40, 0x04, 0x0C,
    0x00, 0x80, 0x04, 0x10, 0x00, 0x00, 0x09, 0x20, 0x00, 0x00, 0x12, 0x40, 0x00, 0x00, 0x24, 0x80,
    0x00, 0x00, 0xC8, 0xC1, 0x01, 0x00, 0x10, 0xFF, 0x01, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0xFE,
    0x01, 0x00, 0x00, 0xFE, 0x0F, 0x00, 0x00, 0x22, 0x10, 0x00, 0x00, 0x22, 0x40, 0x00, 0x00, 0x44,
    0x80, 0x00, 0x00, 0x88, 0x00, 0x01, 0x00, 0x10, 0x01, 0x02, 0x00, 0x60, 0x06, 0x06, 0x00, 0x80,
    0xF9, 0x07, 0x00, 0x00, 0xE2, 0x07, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x04, 0x80, 0x00, 0x00, 0x08, 0xF0, 0x01, 0x00, 0x10, 0xF8, 0x03, 0x00, 0x20, 0x3C, 0x00, 0x00,
    0x40, 0x1E, 0x00, 0x00, 0x80, 0x0E, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
    0x00, 0x70, 0x3C, 0x00, 0x00, 0xF0, 0xFD, 0x00, 0x00, 0x30, 0x0A, 0x01, 0x00, 0x20, 0x08, 0x04,
    0x00, 0x40, 0x10, 0x08, 0x00, 0x80, 0x20, 0x10, 0x00, 0x00, 0x41, 0x20, 0x00, 0x00, 0x46, 0x21,
    0x00, 0x00, 0xF8, 0x7E, 0x00, 0x00, 0xE0, 0x78, 0x00, 0x00, 0xC0, 0xC7, 0x00, 0x00, 0xC0, 0x9F,
    0x03, 0x00, 0xC0, 0x60, 0x0C, 0x00, 0x80, 0x80, 0x10, 0x00, 0x00, 0x01, 0x21, 0x00, 0x00, 0x02,
    0x42, 0x00, 0x00, 0x04, 0xC6, 0x00, 0x00, 0x30, 0xC6, 0x00, 0x00, 0xE0, 0xFF, 0x00, 0x00, 0x00,
    0x7F, 0x00, 0x00, 0x80, 0x01, 0x0C, 0x00, 0x00, 0x07, 0x1C, 0x00, 0x00, 0x06, 0x30, 0x00, 0x00,
    0x08, 0x60, 0x02, 0x00, 0x38, 0xC0, 0x02, 0x00, 0x20, 0x80, 0x03, 0x00, 0x00, 0x08, 0x00, 0x00,
    0x00, 0x28, 0x00, 0x00, 0x00, 0xD8, 0x00, 0x00, 0x00, 0x10, 0x01, 0x00, 0x00, 0x10, 0x04, 0x00,
    0x00, 0x30, 0x18, 0x00, 0x00, 0x80, 0x08, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x22, 0x00,
    0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 0x10, 0x01, 0x00, 0x00, 0x20, 0x02,
    0x00, 0x00, 0x30, 0x18, 0x00, 0x00, 0x40, 0x10, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x36,
    0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x1E,
    0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0xBC, 0x01, 0x00, 0x10,
    0x7C, 0x03, 0x00, 0x20, 0x0C, 0x00, 0x00, 0x80, 0x08, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00,
    0xE0, 0x03, 0x00, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0x70, 0x30, 0x00, 0x00, 0x20, 0xC0, 0x00, 0x00,
    0x20, 0x3C, 0x01, 0x00, 0x40, 0xFC, 0x04, 0x00, 0x40, 0x06, 0x09, 0x00, 0x80, 0x0C, 0x11, 0x00,
    0x00, 0x19, 0x23, 0x00, 0x00, 0xE2, 0x4F, 0x00, 0x00, 0xCC, 0xD1, 0x00, 0x00, 0x90, 0x20, 0x01,
    0x00, 0x60, 0x20, 0x00, 0x00, 0x80, 0x73, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x1E,
    0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0xF8, 0x08, 0x00, 0x00, 0x38, 0x10,
    0x00, 0x00, 0xF0, 0x20, 0x00, 0x00, 0xC0, 0x4F, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0xC0,
    0x0F, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0xFE, 0x7F, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0x08,
    0x02, 0x01, 0x00, 0x10, 0x04, 0x02, 0x00, 0x20, 0x08, 0x04, 0x00, 0x40, 0x10, 0x08, 0x00, 0x80,
    0x20, 0x10, 0x00, 0x00, 0xB7, 0x30, 0x00, 0x00, 0x7C, 0x3F, 0x00, 0x00, 0x20, 0x3C, 0x00, 0x00,
    0x80, 0x1F, 0x00, 0x00, 0xC0, 0xFF, 0x00, 0x00, 0xC0, 0x81, 0x03, 0x00, 0xC0, 0x00, 0x0C, 0x00,
    0x80, 0x00, 0x10, 0x00, 0x00, 0x01, 0x20, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x04, 0x80, 0x00,
    0x00, 0x10, 0x80, 0x00, 0x00, 0xE0, 0xE0, 0x01, 0x00, 0xE0, 0xFF, 0x07, 0x00, 0xC0, 0xFF, 0x0F,
    0x00, 0x80, 0x00, 0x10, 0x00, 0x00, 0x01, 0x20, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x04, 0x80,
    0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0xE0, 0xC0, 0x01, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0xFC,
    0x00, 0x00, 0x80, 0xFF, 0x1F, 0x00, 0x00, 0xFF, 0x3F, 0x00, 0x00, 0x82, 0x40, 0x00, 0x00, 0x04,
    0x81, 0x00, 0x00, 0x08, 0x02, 0x01, 0x00, 0x10, 0x04, 0x02, 0x00, 0x20, 0x08, 0x04, 0x00, 0x40,
    0x10, 0x08, 0x00, 0x80, 0x00, 0x10, 0x00, 0x00, 0xFF, 0x3F, 0x00, 0x00, 0xFE, 0x7F, 0x00, 0x00,
    0x04, 0x01, 0x00, 0x00, 0x08, 0x02, 0x00, 0x00, 0x10, 0x04, 0x00, 0x00, 0x20, 0x08, 0x00, 0x00,
    0x40, 0x10, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x00, 0x00, 0xF8, 0x1F, 0x00,
    0x00, 0x38, 0x70, 0x00, 0x00, 0x10, 0x80, 0x00, 0x00, 0x10, 0x00, 0x02, 0x00, 0x20, 0x00, 0x04,
    0x00, 0x40, 0x20, 0x08, 0x00, 0x80, 0x41, 0x18, 0x00, 0x00, 0x86, 0x18, 0x00, 0x00, 0x1C, 0x3F,
    0x00, 0x00, 0x20, 0xFE, 0x00, 0x00, 0xF8, 0xFF, 0x01, 0x00, 0xF0, 0xFF, 0x03, 0x00, 0x00, 0x08,
    0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xF8, 0xFF, 0x01, 0x00, 0xF0, 0xFF, 0x03, 0x00, 0xE0,
    0xFF, 0x07, 0x00, 0xC0, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00,
    0x00, 0x40, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0xF8, 0xFF, 0x00, 0x00, 0xF0, 0xFF, 0x00, 0x00,
    0xE0, 0xFF, 0x07, 0x00, 0xC0, 0xFF, 0x0F, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0xC0, 0x00, 0x00,
    0x00, 0xC0, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x60, 0x0E, 0x00, 0x00, 0x60, 0x78, 0x00,
    0x00, 0x60, 0xC0, 0x03, 0x00, 0x40, 0x00, 0x0E, 0x00, 0x80, 0xFF, 0x1F, 0x00, 0x00, 0xFF, 0x3F,
    0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0x80, 0xFF, 0x1F, 0x00, 0x00, 0xFF,
    0x3F, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x00, 0x00,
    0x3C, 0x00, 0x00, 0x00, 0xE0, 0x03, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00,
    0x80, 0x03, 0x00, 0x00, 0xE0, 0x01, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
    0xF0, 0xFF, 0x03, 0x00, 0xE0, 0xFF, 0x07, 0x00, 0xC0, 0xFF, 0x0F, 0x00, 0x80, 0xFF, 0x1F, 0x00,
    0x00, 0x03, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00,
    0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0x00, 0x1C,
    0x00, 0x00, 0xFF, 0x3F, 0x00, 0x00, 0xFE, 0x7F, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0xE0, 0x7F,
    0x00, 0x00, 0xE0, 0xC0, 0x01, 0x00, 0x40, 0x00, 0x02, 0x00, 0x40, 0x00, 0x08, 0x00, 0x80, 0x00,
    0x10, 0x00, 0x00, 0x01, 0x20, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x08, 0x40, 0x00, 0x00, 0x70,
    0xE0, 0x00, 0x00, 0xC0, 0xFF, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xC0, 0xFF, 0x0F, 0x00, 0x80,
    0xFF, 0x1F, 0x00, 0x00, 0x81, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00,
    0x08, 0x04, 0x00, 0x00, 0x10, 0x08, 0x00, 0x00, 0x60, 0x18, 0x00, 0x00, 0x80, 0x1F, 0x00, 0x00,
    0x00, 0x1E, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x00, 0x00, 0xF8, 0x1F, 0x00, 0x00, 0x38, 0x70, 0x00,
    0x00, 0x10, 0x80, 0x00, 0x00, 0x10, 0x00, 0x02, 0x00, 0x20, 0x00, 0x04, 0x00, 0x40, 0x00, 0x38,
    0x00, 0x80, 0x00, 0xD0, 0x00, 0x00, 0x03, 0x30, 0x01, 0x00, 0x1C, 0x38, 0x02, 0x00, 0xF0, 0x3F,
    0x04, 0x00, 0x80, 0x1F, 0x00, 0x00, 0xF0, 0xFF, 0x03, 0x00, 0xE0, 0xFF, 0x07, 0x00, 0x40, 0x20,
    0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0x00, 0x81, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x00, 0x04,
    0x0E, 0x00, 0x00, 0x18, 0xFE, 0x00, 0x00, 0xE0, 0x87, 0x03, 0x00, 0x80, 0x07, 0x04, 0x00, 0x00,
    0x0F, 0x03, 0x00, 0x00, 0x3F, 0x0C, 0x00, 0x00, 0x63, 0x30, 0x00, 0x00, 0xC2, 0x40, 0x00, 0x00,
    0x04, 0x83, 0x00, 0x00, 0x08, 0x06, 0x01, 0x00, 0x10, 0x0C, 0x02, 0x00, 0x60, 0x18, 0x04, 0x00,
    0x80, 0x63, 0x04, 0x00, 0x00, 0xC2, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x02, 0x00, 0x00,
    0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0x07,
    0x00, 0xC0, 0xFF, 0x0F, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xF8, 0x7F, 0x00, 0x00, 0xF0, 0xFF, 0x01, 0x00, 0x00, 0x00,
    0x06, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0xF8, 0xFF, 0x00, 0x00, 0xF0, 0xFF, 0x00, 0x00, 0x20,
    0x00, 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x00, 0x00,
    0x00, 0x1F, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0xF0, 0x00, 0x00,
    0x00, 0x7C, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x7E, 0x00, 0x00, 0x00, 0xFC, 0x07, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0xC0, 0x03,
    0x00, 0x00, 0xC0, 0x07, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x80, 0x1F, 0x00, 0x00, 0x00, 0x3F, 0x00,
    0x00, 0x00, 0xF0, 0x07, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0xF0,
    0x03, 0x00, 0xE0, 0x7F, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x80, 0x00, 0x10, 0x00, 0x00, 0x03,
    0x30, 0x00, 0x00, 0x0E, 0x38, 0x00, 0x00, 0x70, 0x1C, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00,
    0x0E, 0x00, 0x00, 0x00, 0x7E, 0x00, 0x00, 0x00, 0xC7, 0x03, 0x00, 0x80, 0x03, 0x0E, 0x00, 0x00,
    0x01, 0x38, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
    0xF0, 0x00, 0x00, 0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x00,
    0x00, 0xC0, 0x3F, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
    0x00, 0x30, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x40, 0x00, 0x0C, 0x00, 0x80, 0x00, 0x1C,
    0x00, 0x00, 0x01, 0x2E, 0x00, 0x00, 0x02, 0x4E, 0x00, 0x00, 0x04, 0x87, 0x00, 0x00, 0x88, 0x03,
    0x01, 0x00, 0x90, 0x03, 0x02, 0x00, 0xE0, 0x01, 0x04, 0x00, 0xC0, 0x01, 0x08, 0x00, 0x80, 0x00,
    0x10, 0x00, 0x00, 0xFF, 0xFF, 0x01, 0x00, 0xFE, 0xFF, 0x03, 0x00, 0x04, 0x00, 0x04, 0x00, 0x08,
    0x00, 0x08, 0x00, 0x30, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00,
    0x30, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00,
    0x00, 0x80, 0x01, 0x00, 0x10, 0x00, 0x10, 0x00, 0x20, 0x00, 0x20, 0x00, 0xC0, 0xFF, 0x7F, 0x00,
    0x80, 0xFF, 0xFF, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0x70, 0x00, 0x00,
    0x00, 0x38, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x38, 0x00,
    0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x06,
    0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x07, 0x00, 0x00, 0x38, 0x1F, 0x00, 0x00, 0x18, 0x33, 0x00, 0x00, 0x10, 0x42, 0x00, 0x00,
    0x20, 0x84, 0x00, 0x00, 0x40, 0x08, 0x01, 0x00, 0x80, 0x11, 0x01, 0x00, 0x00, 0xFE, 0x07, 0x00,
    0x00, 0xF8, 0x0F, 0x00, 0x80, 0xFF, 0x1F, 0x00, 0x00, 0xFF, 0x1F, 0x00, 0x00, 0x20, 0x20, 0x00,
    0x00, 0x20, 0x80, 0x00, 0x00, 0x40, 0x00, 0x01, 0x00, 0x80, 0x00, 0x02, 0x00, 0x00, 0x07, 0x06,
    0x00, 0x00, 0xFC, 0x07, 0x00, 0x00, 0xE0, 0x03, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x00, 0xE0, 0x3F,
    0x00, 0x00, 0xE0, 0xE0, 0x00, 0x00, 0x40, 0x00, 0x01, 0x00, 0x80, 0x00, 0x02, 0x00, 0x00, 0x01,
    0x04, 0x00, 0x00, 0x04, 0x04, 0x00, 0x00, 0x38, 0x06, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x00, 0xE0,
    0x3F, 0x00, 0x00, 0xE0, 0xE0, 0x00, 0x00, 0x40, 0x00, 0x01, 0x00, 0x80, 0x00, 0x02, 0x00, 0x00,
    0x01, 0x04, 0x00, 0x00, 0x04, 0x04, 0x00, 0x80, 0xFF, 0x1F, 0x00, 0x00, 0xFF, 0x3F, 0x00, 0x00,
    0x80, 0x0F, 0x00, 0x00, 0x80, 0x7F, 0x00, 0x00, 0x80, 0xC9, 0x00, 0x00, 0x80, 0x11, 0x03, 0x00,
    0x00, 0x21, 0x04, 0x00, 0x00, 0x42, 0x08, 0x00, 0x00, 0x84, 0x10, 0x00, 0x00, 0x10, 0x31, 0x00,
    0x00, 0xE0, 0x33, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
    0x00, 0xC0, 0xFF, 0x07, 0x00, 0xC0, 0xFF, 0x0F, 0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 0x09, 0x00,
    0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0xE7, 0x0E, 0x00, 0x00, 0xFF,
    0x13, 0x00, 0x00, 0x63, 0x24, 0x00, 0x00, 0x82, 0x48, 0x00, 0x00, 0x04, 0x91, 0x00, 0x00, 0x18,
    0x23, 0x01, 0x00, 0xF8, 0x43, 0x02, 0x00, 0x90, 0x83, 0x07, 0x00, 0x00, 0x00, 0x06, 0x00, 0xF0,
    0xFF, 0x03, 0x00, 0xE0, 0xFF, 0x07, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
    0x08, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x00,
    0x00, 0xFE, 0x03, 0x00, 0x20, 0xFF, 0x07, 0x00, 0x40, 0xFE, 0x0F, 0x00, 0x00, 0x00, 0x80, 0x00,
    0x00, 0xF9, 0xFF, 0x01, 0x00, 0xF2, 0xFF, 0x01, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0xF8, 0xFF, 0x01,
    0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0xF0, 0x01,
    0x00, 0x00, 0x30, 0x0F, 0x00, 0x00, 0x30, 0x38, 0x00, 0x00, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x00, 0xF0, 0xFF, 0x03, 0x00, 0xE0, 0xFF, 0x07, 0x00, 0x00, 0xFE, 0x0F, 0x00, 0x00, 0xFC,
    0x1F, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0xC0,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0x03, 0x00, 0x00, 0xFC, 0x07, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0xE0, 0xFF, 0x00, 0x00,
    0x00, 0xFF, 0x01, 0x00, 0x80, 0xFF, 0x03, 0x00, 0x00, 0xFF, 0x07, 0x00, 0x00, 0x0C, 0x00, 0x00,
    0x00, 0x08, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00,
    0x00, 0x80, 0xFF, 0x01, 0x00, 0x00, 0xFE, 0x03, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0xFC, 0x07,
    0x00, 0x00, 0x1C, 0x18, 0x00, 0x00, 0x08, 0x20, 0x00, 0x00, 0x10, 0x40, 0x00, 0x00, 0x20, 0x80,
    0x00, 0x00, 0xC0, 0x80, 0x01, 0x00, 0x00, 0xFF, 0x01, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0xFE,
    0x7F, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0x10, 0x18, 0x00, 0x00, 0x10, 0x40, 0x00, 0x00, 0x20,
    0x80, 0x00, 0x00, 0x40, 0x00, 0x01, 0x00, 0x80, 0x81, 0x03, 0x00, 0x00, 0xFE, 0x03, 0x00, 0x00,
    0xF0, 0x01, 0x00, 0x00, 0xE0, 0x03, 0x00, 0x00, 0xF0, 0x1F, 0x00, 0x00, 0x70, 0x70, 0x00, 0x00,
    0x20, 0x80, 0x00, 0x00, 0x40, 0x00, 0x01, 0x00, 0x80, 0x00, 0x02, 0x00, 0x00, 0x02, 0x03, 0x00,
    0x00, 0xFC, 0x7F, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0xF8, 0x3F, 0x00, 0x00, 0xF0, 0x7F, 0x00,
    0x00, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x10, 0x02, 0x00, 0x00, 0x78, 0x0C, 0x00, 0x00, 0x98, 0x31, 0x00, 0x00, 0x10, 0x43,
    0x00, 0x00, 0x20, 0x84, 0x00, 0x00, 0xC0, 0x18, 0x01, 0x00, 0x80, 0x31, 0x02, 0x00, 0x00, 0xE6,
    0x03, 0x00, 0x00, 0x90, 0x03, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0xFE,
    0x3F, 0x00, 0x00, 0xFC, 0xFF, 0x00, 0x00, 0x40, 0x00, 0x01, 0x00, 0x80, 0x00, 0x02, 0x00, 0x00,
    0x00, 0x04, 0x00, 0x00, 0xFE, 0x03, 0x00, 0x00, 0xFC, 0x0F, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00,
    0x00, 0x40, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x01, 0x00,
    0x00, 0xFF, 0x07, 0x00, 0x00, 0xFE, 0x0F, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00,
    0x00, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0xC0, 0x01, 0x00, 0x00, 0xC0, 0x03,
    0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x18, 0x00,
    0x00, 0x00, 0xF0, 0x01, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x00, 0x00, 0xC0,
    0x03, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0xC0,
    0x07, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x80,
    0x0F, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x08, 0x00, 0x00, 0x0C, 0x18, 0x00, 0x00,
    0x38, 0x1C, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00,
    0x00, 0xC3, 0x01, 0x00, 0x00, 0x01, 0x06, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x04, 0x80, 0x00,
    0x00, 0x78, 0x00, 0x01, 0x00, 0xC0, 0x07, 0x02, 0x00, 0x00, 0x7C, 0x03, 0x00, 0x00, 0xC0, 0x03,
    0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x04, 0x00,
    0x00, 0x00, 0x08, 0x30, 0x00, 0x00, 0x10, 0x70, 0x00, 0x00, 0x20, 0xB8, 0x00, 0x00, 0x40, 0x38,
    0x01, 0x00, 0x80, 0x1C, 0x02, 0x00, 0x00, 0x1F, 0x04, 0x00, 0x00, 0x0E, 0x08, 0x00, 0x00, 0x04,
    0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0xF8, 0xFB, 0x03, 0x00, 0xF8,
    0xE3, 0x0F, 0x00, 0x10, 0x00, 0x10, 0x00, 0x20, 0x00, 0x20, 0x00, 0xC0, 0xFF, 0x0F, 0x00, 0x80,
    0xFF, 0x1F, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00, 0xFC, 0xF1, 0x07, 0x00,
    0xF0, 0xF7, 0x07, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00,
    0x00, 0xC0, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x06, 0x00,
    0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0xC0, 0x00,
    0x00, 0x00, 0xC0, 0x00, 0x00
};

#endif

