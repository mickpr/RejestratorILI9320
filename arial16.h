/*
 created with FontEditor
 written by H. Reddmann
 HaReddmann at t-online dot de
 File Name           : arial16.h
 Date                : 07.10.2008
 Font size in bytes  : 0x0F6C
 Font width          : 16
 Font height         : 18
 Font bits per pixel : 1
 Font first char     : 0x1F
 Font last char      : 0xFF
 Font used chars     : 223

 The font data are defined as

 struct _FONT_ {
   uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
   uint8_t    font_Width_in_Pixel_for_fixed_drawing;
   uint8_t    font_Height_in_Pixel_for_all_characters;
   uint8_t    font_Bits_per_Pixels;
   unit8_t    font_First_Char;
   uint8_t    font_Last_Char;
   uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
                // for each character the separate width in pixels,
                // characters < 128 have an implicit virtual right empty row
   unit8_t    font_data[];
                // bit field of all characters
*/

//#include "../typedefinitions.h"
#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef arial16_H
#define arial16_H

#define arial16_WIDTH 16
#define arial16_HEIGHT 18

unsigned char __attribute__ ((progmem)) arial16[] = {
    0x0F, 0x6C, 0x10, 0x12, 0x01, 0x1F, 0xFF,
    0x08, 0x01, 0x01, 0x04, 0x09, 0x07, 0x0C, 0x09, 0x01, 0x03, 0x03, 0x05, 0x07, 0x01, 0x04, 0x01,
    0x04, 0x07, 0x04, 0x07, 0x07, 0x08, 0x07, 0x07, 0x07, 0x07, 0x07, 0x01, 0x01, 0x07, 0x07, 0x07,
    0x07, 0x0F, 0x09, 0x09, 0x0A, 0x0A, 0x09, 0x08, 0x0A, 0x09, 0x01, 0x06, 0x09, 0x07, 0x0B, 0x09,
    0x0A, 0x09, 0x0A, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0F, 0x0B, 0x09, 0x09, 0x03, 0x04, 0x03, 0x07,
    0x09, 0x02, 0x07, 0x07, 0x06, 0x07, 0x07, 0x04, 0x07, 0x06, 0x01, 0x02, 0x07, 0x01, 0x0B, 0x06,
    0x07, 0x07, 0x07, 0x04, 0x06, 0x04, 0x06, 0x07, 0x0B, 0x07, 0x07, 0x07, 0x05, 0x01, 0x05, 0x08,
    0x00, 0x08, 0x0A, 0x02, 0x09, 0x03, 0x0D, 0x08, 0x08, 0x05, 0x11, 0x0A, 0x04, 0x10, 0x0A, 0x09,
    0x0A, 0x0A, 0x02, 0x02, 0x03, 0x04, 0x05, 0x09, 0x10, 0x04, 0x0F, 0x07, 0x04, 0x0E, 0x0A, 0x07,
    0x09, 0x00, 0x03, 0x08, 0x08, 0x07, 0x09, 0x02, 0x08, 0x03, 0x0C, 0x05, 0x07, 0x08, 0x04, 0x0C,
    0x09, 0x05, 0x08, 0x05, 0x05, 0x04, 0x08, 0x09, 0x02, 0x04, 0x04, 0x05, 0x08, 0x0D, 0x0D, 0x0D,
    0x09, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0F, 0x0B, 0x0A, 0x0A, 0x0A, 0x0A, 0x02, 0x03, 0x04,
    0x03, 0x0B, 0x0A, 0x0B, 0x0B, 0x0B, 0x0B, 0x0B, 0x08, 0x0B, 0x0A, 0x0A, 0x0A, 0x0A, 0x09, 0x0A,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0E, 0x07, 0x08, 0x08, 0x08, 0x08, 0x02, 0x03, 0x04,
    0x03, 0x08, 0x07, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x07, 0x07, 0x07, 0x07, 0x07, 0x08,
    0x07,

    0xE0, 0x7F, 0x80, 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x01, 0x02, 0x04,
    0xF8, 0x1F, 0x00, 0x00, 0xE0, 0x7F, 0x81, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x01, 0x00,
    0x88, 0x00, 0x20, 0x1E, 0xC0, 0x0F, 0xE0, 0x22, 0x00, 0x88, 0x00, 0x20, 0x1E, 0xC0, 0x0F, 0xE0,
    0x22, 0x00, 0x88, 0x00, 0x38, 0x04, 0x10, 0x21, 0x20, 0x04, 0xC1, 0xFF, 0x0F, 0x82, 0x10, 0x08,
    0x22, 0xC0, 0x70, 0x00, 0x0F, 0x00, 0x42, 0x00, 0x08, 0x01, 0x20, 0x84, 0x01, 0x8F, 0x01, 0x80,
    0x01, 0xC0, 0x01, 0xC0, 0xF0, 0x80, 0x20, 0x04, 0x80, 0x10, 0x00, 0x42, 0x00, 0xF0, 0x00, 0xC0,
    0x01, 0x9C, 0x08, 0x88, 0x41, 0x20, 0x0C, 0x81, 0x48, 0x04, 0x1C, 0x0A, 0x00, 0x10, 0x00, 0xA0,
    0x00, 0x40, 0x04, 0x1E, 0x00, 0x80, 0x3F, 0xC0, 0x01, 0x87, 0x00, 0x20, 0x02, 0x80, 0x70, 0xC0,
    0x01, 0xFE, 0x00, 0x01, 0x00, 0x34, 0x00, 0x38, 0x00, 0x40, 0x03, 0x00, 0x01, 0x00, 0x80, 0x00,
    0x00, 0x02, 0x00, 0x08, 0x00, 0xFC, 0x01, 0x80, 0x00, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00, 0x1C,
    0x00, 0x02, 0x00, 0x08, 0x00, 0x20, 0x00, 0x80, 0x00, 0x00, 0x10, 0x00, 0x60, 0x00, 0x78, 0x00,
    0x1E, 0x00, 0x06, 0x00, 0xE0, 0x1F, 0x40, 0x80, 0x80, 0x00, 0x04, 0x02, 0x10, 0x08, 0x40, 0x40,
    0x80, 0x00, 0xFE, 0x01, 0x10, 0x00, 0x20, 0x00, 0x40, 0x00, 0x80, 0xFF, 0x07, 0x08, 0x10, 0x10,
    0x60, 0x20, 0x40, 0x81, 0x80, 0x04, 0x02, 0x11, 0x18, 0x43, 0x80, 0x03, 0x01, 0x02, 0x03, 0x04,
    0x08, 0x08, 0x41, 0x20, 0x04, 0x81, 0x18, 0x04, 0xBC, 0x08, 0x00, 0x1C, 0x00, 0x30, 0x00, 0xA0,
    0x00, 0x40, 0x02, 0xC0, 0x08, 0x80, 0x20, 0x00, 0x81, 0x00, 0xFE, 0x1F, 0x00, 0x08, 0x00, 0x47,
    0x80, 0x0B, 0x02, 0x22, 0x10, 0x88, 0x40, 0x20, 0x02, 0x81, 0x10, 0x02, 0x82, 0x07, 0xE0, 0x1F,
    0x40, 0x84, 0x80, 0x08, 0x04, 0x22, 0x10, 0x88, 0x40, 0x40, 0x84, 0x00, 0xE2, 0x01, 0x02, 0x00,
    0x08, 0x00, 0x20, 0xC0, 0x81, 0xF0, 0x00, 0x32, 0x00, 0x38, 0x00, 0x20, 0x00, 0x00, 0xC6, 0x01,
    0xA4, 0x08, 0x08, 0x41, 0x20, 0x04, 0x81, 0x10, 0x04, 0xA4, 0x08, 0x60, 0x1C, 0x80, 0x47, 0x00,
    0x21, 0x02, 0x02, 0x11, 0x08, 0x44, 0x20, 0x10, 0x01, 0x21, 0x02, 0xF8, 0x07, 0x40, 0x40, 0x00,
    0x01, 0x07, 0x20, 0x00, 0x40, 0x01, 0x00, 0x05, 0x00, 0x22, 0x00, 0x88, 0x00, 0x20, 0x02, 0x40,
    0x10, 0x00, 0x22, 0x00, 0x88, 0x00, 0x20, 0x02, 0x80, 0x08, 0x00, 0x22, 0x00, 0x88, 0x00, 0x20,
    0x02, 0x40, 0x10, 0x00, 0x22, 0x00, 0x88, 0x00, 0x20, 0x02, 0x00, 0x05, 0x00, 0x14, 0x00, 0x20,
    0x00, 0x18, 0x00, 0x10, 0x00, 0x20, 0x00, 0x80, 0xC0, 0x05, 0x82, 0x00, 0x10, 0x01, 0x80, 0x03,
    0x00, 0xF0, 0x03, 0x30, 0x10, 0x20, 0x80, 0x40, 0x78, 0x04, 0x11, 0x12, 0x22, 0x90, 0x48, 0x40,
    0x22, 0x01, 0x89, 0x04, 0x22, 0x22, 0x9F, 0xC8, 0x43, 0x42, 0x00, 0x09, 0x01, 0x12, 0x18, 0x44,
    0x80, 0x8F, 0x00, 0x80, 0x01, 0xC0, 0x01, 0xE0, 0x01, 0x70, 0x04, 0x20, 0x10, 0x00, 0x47, 0x00,
    0xE0, 0x01, 0x00, 0x1C, 0x00, 0x80, 0x81, 0xFF, 0x07, 0x42, 0x10, 0x08, 0x41, 0x20, 0x04, 0x81,
    0x10, 0x04, 0x42, 0x10, 0x08, 0x41, 0x60, 0x8A, 0x00, 0xC6, 0x01, 0xF0, 0x03, 0x20, 0x10, 0x40,
    0x80, 0x80, 0x00, 0x04, 0x02, 0x10, 0x08, 0x40, 0x20, 0x00, 0x81, 0x00, 0x04, 0x04, 0x08, 0x20,
    0x10, 0xE0, 0xFF, 0x81, 0x00, 0x04, 0x02, 0x10, 0x08, 0x40, 0x20, 0x00, 0x81, 0x00, 0x04, 0x02,
    0x10, 0x10, 0x20, 0x80, 0x40, 0x00, 0xFC, 0x00, 0xFE, 0x1F, 0x08, 0x41, 0x20, 0x04, 0x81, 0x10,
    0x04, 0x42, 0x10, 0x08, 0x41, 0x20, 0x04, 0x81, 0x10, 0x04, 0x02, 0x10, 0xF8, 0x7F, 0x20, 0x08,
    0x80, 0x20, 0x00, 0x82, 0x00, 0x08, 0x02, 0x20, 0x08, 0x80, 0x20, 0x00, 0x02, 0x00, 0xC0, 0x0F,
    0x80, 0x40, 0x00, 0x01, 0x02, 0x02, 0x10, 0x08, 0x40, 0x20, 0x08, 0x81, 0x20, 0x04, 0x84, 0x08,
    0x20, 0x12, 0x00, 0x38, 0x80, 0xFF, 0x07, 0x40, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00,
    0x40, 0x00, 0x00, 0x01, 0x00, 0x04, 0x80, 0xFF, 0x07, 0xFE, 0x1F, 0x00, 0x38, 0x00, 0x00, 0x01,
    0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0xE0, 0xFF, 0x80, 0xFF, 0x07, 0x00, 0x01, 0x00, 0x02, 0x00,
    0x04, 0x00, 0x38, 0x00, 0x10, 0x01, 0x20, 0x18, 0x40, 0x80, 0x80, 0x00, 0x04, 0xFE, 0x1F, 0x00,
    0x40, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00, 0x81, 0xFF, 0x07, 0x0C,
    0x00, 0xC0, 0x00, 0x00, 0x0C, 0x00, 0xC0, 0x01, 0x00, 0x18, 0x00, 0x1C, 0x00, 0x0C, 0x00, 0x0C,
    0x00, 0x0C, 0x00, 0xF8, 0x7F, 0xE0, 0xFF, 0x01, 0x01, 0x00, 0x18, 0x00, 0x80, 0x00, 0x00, 0x0C,
    0x00, 0x40, 0x00, 0x00, 0x06, 0x00, 0x20, 0xE0, 0xFF, 0x01, 0xFC, 0x00, 0x08, 0x04, 0x10, 0x20,
    0x20, 0x00, 0x81, 0x00, 0x04, 0x02, 0x10, 0x08, 0x40, 0x40, 0x80, 0x00, 0x02, 0x01, 0xF0, 0x03,
    0xF8, 0x7F, 0x20, 0x08, 0x80, 0x20, 0x00, 0x82, 0x00, 0x08, 0x02, 0x20, 0x08, 0x80, 0x20, 0x00,
    0x44, 0x00, 0xE0, 0x00, 0x00, 0x3F, 0x00, 0x02, 0x01, 0x04, 0x08, 0x08, 0x40, 0x20, 0x00, 0x81,
    0x00, 0x05, 0x02, 0x14, 0x10, 0x20, 0x80, 0xC0, 0x01, 0xFC, 0x05, 0xFE, 0x1F, 0x08, 0x02, 0x20,
    0x08, 0x80, 0x20, 0x00, 0x82, 0x00, 0x08, 0x06, 0x20, 0x68, 0x00, 0x11, 0x02, 0x38, 0x10, 0x60,
    0x10, 0x40, 0x82, 0x80, 0x10, 0x04, 0x42, 0x10, 0x08, 0x41, 0x20, 0x08, 0x81, 0x20, 0x04, 0x84,
    0x08, 0x20, 0x1C, 0x20, 0x00, 0x80, 0x00, 0x00, 0x02, 0x00, 0x08, 0x00, 0xE0, 0xFF, 0x81, 0x00,
    0x00, 0x02, 0x00, 0x08, 0x00, 0x20, 0x00, 0x80, 0xFF, 0x01, 0x00, 0x08, 0x00, 0x40, 0x00, 0x00,
    0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00, 0x80, 0x80, 0xFF, 0x01, 0x06, 0x00, 0xE0, 0x00,
    0x00, 0x1C, 0x00, 0x80, 0x01, 0x00, 0x18, 0x00, 0x18, 0x00, 0x1C, 0x00, 0x0E, 0x00, 0x06, 0x00,
    0x18, 0x00, 0x80, 0x07, 0x00, 0xE0, 0x01, 0x00, 0x18, 0x00, 0x1C, 0x00, 0x0E, 0x00, 0x07, 0x00,
    0x02, 0x00, 0x70, 0x00, 0x00, 0x0E, 0x00, 0xC0, 0x01, 0x00, 0x18, 0x00, 0x1E, 0x80, 0x07, 0x80,
    0x01, 0x00, 0x00, 0x10, 0x08, 0x20, 0x40, 0x40, 0x00, 0xC6, 0x00, 0xA0, 0x00, 0x00, 0x01, 0x00,
    0x0A, 0x00, 0xC6, 0x00, 0x04, 0x04, 0x08, 0x20, 0x00, 0x00, 0x81, 0x00, 0x00, 0x0C, 0x00, 0x40,
    0x00, 0x00, 0x06, 0x00, 0xE0, 0x07, 0x60, 0x00, 0x40, 0x00, 0xC0, 0x00, 0x80, 0x00, 0x00, 0x00,
    0x10, 0x08, 0x60, 0x20, 0x60, 0x81, 0x40, 0x04, 0xC2, 0x10, 0x88, 0x40, 0xA0, 0x01, 0x81, 0x01,
    0x04, 0x02, 0x10, 0xF8, 0xFF, 0x23, 0x00, 0x88, 0x00, 0x20, 0x06, 0x00, 0xE0, 0x01, 0x00, 0x78,
    0x00, 0x00, 0x06, 0x02, 0x80, 0x08, 0x00, 0xE2, 0xFF, 0x0F, 0x10, 0x00, 0x30, 0x00, 0x30, 0x00,
    0x20, 0x00, 0x00, 0x03, 0x00, 0x30, 0x00, 0x00, 0x01, 0x00, 0x00, 0x08, 0x00, 0x20, 0x00, 0x80,
    0x00, 0x00, 0x02, 0x00, 0x08, 0x00, 0x20, 0x00, 0x80, 0x00, 0x00, 0x02, 0x00, 0x88, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x39, 0x00, 0x12, 0x01, 0x44, 0x04, 0x10, 0x11, 0x40, 0x42, 0x00, 0x89, 0x00,
    0xF8, 0x07, 0xFE, 0x1F, 0x80, 0x20, 0x00, 0x01, 0x01, 0x04, 0x04, 0x10, 0x10, 0x80, 0x20, 0x00,
    0x7C, 0x00, 0xF0, 0x01, 0x20, 0x08, 0x40, 0x40, 0x00, 0x01, 0x01, 0x04, 0x04, 0x20, 0x08, 0x00,
    0x1F, 0x00, 0x82, 0x00, 0x04, 0x04, 0x10, 0x10, 0x40, 0x40, 0x00, 0x82, 0x80, 0xFF, 0x07, 0xC0,
    0x07, 0x80, 0x24, 0x00, 0x11, 0x01, 0x44, 0x04, 0x10, 0x11, 0x80, 0x24, 0x00, 0x5C, 0x00, 0x04,
    0x00, 0xFC, 0x1F, 0x48, 0x00, 0x20, 0x01, 0x00, 0xF0, 0x11, 0x20, 0x88, 0x40, 0x40, 0x02, 0x01,
    0x09, 0x04, 0x24, 0x20, 0x48, 0xC0, 0xFF, 0xE0, 0xFF, 0x01, 0x08, 0x00, 0x10, 0x00, 0x40, 0x00,
    0x00, 0x01, 0x00, 0xF8, 0x07, 0xF2, 0x1F, 0x00, 0x00, 0x22, 0xFF, 0x87, 0xFF, 0x07, 0x00, 0x02,
    0x00, 0x04, 0x00, 0x18, 0x00, 0x90, 0x01, 0x20, 0x08, 0x40, 0x40, 0xE0, 0xFF, 0x01, 0xFC, 0x07,
    0x20, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0xE0, 0x1F, 0x80, 0x00, 0x00, 0x01, 0x00,
    0x04, 0x00, 0x10, 0x00, 0x80, 0x7F, 0x00, 0xFF, 0x01, 0x08, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00,
    0x01, 0x00, 0xF8, 0x07, 0xC0, 0x07, 0x80, 0x20, 0x00, 0x01, 0x01, 0x04, 0x04, 0x10, 0x10, 0x80,
    0x20, 0x00, 0x7C, 0x00, 0xFC, 0x3F, 0x20, 0x08, 0x40, 0x40, 0x00, 0x01, 0x01, 0x04, 0x04, 0x20,
    0x08, 0x00, 0x1F, 0x00, 0x7C, 0x00, 0x08, 0x02, 0x10, 0x10, 0x40, 0x40, 0x00, 0x01, 0x01, 0x08,
    0x02, 0xF0, 0xFF, 0xC0, 0x7F, 0x00, 0x02, 0x00, 0x04, 0x00, 0x10, 0x00, 0x80, 0x23, 0x00, 0x11,
    0x01, 0x44, 0x04, 0x10, 0x11, 0x40, 0x44, 0x00, 0xE2, 0x00, 0x04, 0x00, 0xFC, 0x1F, 0x40, 0x40,
    0x00, 0x01, 0x01, 0xFC, 0x03, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x02, 0xF0, 0x1F,
    0xC0, 0x00, 0x00, 0x0C, 0x00, 0xC0, 0x01, 0x00, 0x18, 0x00, 0x1C, 0x00, 0x0C, 0x00, 0x0C, 0x00,
    0x30, 0x00, 0x00, 0x1F, 0x00, 0x80, 0x01, 0xC0, 0x01, 0xC0, 0x00, 0xC0, 0x00, 0x00, 0x0C, 0x00,
    0xC0, 0x01, 0x00, 0x18, 0x00, 0x1F, 0x00, 0x03, 0x00, 0x04, 0x04, 0x20, 0x08, 0x00, 0x1B, 0x00,
    0x10, 0x00, 0xB0, 0x01, 0x20, 0x08, 0x40, 0x40, 0x00, 0x07, 0x00, 0x60, 0x20, 0x00, 0x8E, 0x00,
    0xC0, 0x01, 0xE0, 0x00, 0x70, 0x00, 0x30, 0x00, 0x40, 0x40, 0x00, 0x81, 0x01, 0x84, 0x05, 0x10,
    0x11, 0x40, 0x43, 0x00, 0x03, 0x01, 0x04, 0x04, 0x00, 0x01, 0x00, 0x04, 0xC0, 0xEF, 0x87, 0x00,
    0x20, 0x02, 0x80, 0xF8, 0xFF, 0x23, 0x00, 0x88, 0x00, 0x20, 0xFC, 0x7E, 0x00, 0x04, 0x00, 0x10,
    0x00, 0x20, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x20, 0x00, 0x80, 0x00, 0x00, 0x02,
    0x00, 0x04, 0x00, 0x50, 0x00, 0xF0, 0x07, 0x20, 0x25, 0x40, 0x14, 0x81, 0x50, 0x04, 0x42, 0x11,
    0x08, 0x45, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x7F, 0x80, 0x00, 0x01, 0x02, 0x04,
    0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x01, 0x02, 0x04, 0xF8, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x07,
    0x00, 0x20, 0x00, 0x80, 0x00, 0x00, 0x02, 0x01, 0x0F, 0xF4, 0x03, 0x3C, 0x00, 0x48, 0x00, 0x20,
    0x01, 0x80, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x04,
    0x00, 0xFE, 0xFF, 0x40, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x40, 0x40, 0x00, 0x01,
    0x01, 0x04, 0x04, 0xFE, 0xFF, 0x40, 0x40, 0x00, 0x01, 0x01, 0x04, 0x04, 0x00, 0x00, 0x10, 0x00,
    0x20, 0x00, 0x80, 0x00, 0x00, 0x04, 0x00, 0xF0, 0x00, 0x20, 0x04, 0x80, 0x10, 0x00, 0x42, 0x1C,
    0xF0, 0x0C, 0x00, 0x0C, 0x00, 0xCE, 0x03, 0x86, 0x10, 0x00, 0x42, 0x00, 0x08, 0x01, 0xC0, 0x03,
    0x00, 0x00, 0x00, 0x3C, 0x00, 0x08, 0x01, 0x20, 0x04, 0x80, 0x10, 0x00, 0x3C, 0x00, 0x00, 0x00,
    0x06, 0x01, 0x24, 0x08, 0x08, 0x41, 0x24, 0x04, 0xA1, 0x10, 0x84, 0x82, 0x10, 0x09, 0x42, 0x40,
    0x88, 0x00, 0xC2, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x6C, 0x00, 0x08, 0x02, 0x00, 0x00, 0xC0,
    0x0F, 0x80, 0x40, 0x00, 0x01, 0x02, 0x02, 0x10, 0x08, 0x40, 0x20, 0x00, 0x81, 0x00, 0x04, 0x04,
    0x08, 0x20, 0x10, 0xE0, 0xFF, 0x81, 0x10, 0x04, 0x42, 0x10, 0x08, 0x41, 0x20, 0x04, 0x81, 0x10,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00,
    0x01, 0x02, 0x04, 0x08, 0x10, 0xE0, 0x7F, 0x00, 0x00, 0x81, 0x00, 0x06, 0x02, 0x16, 0x09, 0x44,
    0x28, 0x0C, 0xA1, 0x08, 0x44, 0x1A, 0x10, 0x18, 0x40, 0x20, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
    0xE0, 0x7F, 0x80, 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x01, 0x02, 0x04,
    0xF8, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x07, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x01,
    0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0xFF, 0x01, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0xE0,
    0x00, 0x80, 0x03, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0x00, 0x38,
    0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0xE0, 0x01, 0x80, 0x07, 0x00, 0x0C, 0x00, 0x40, 0x00, 0x00,
    0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40,
    0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10,
    0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x04,
    0x00, 0x10, 0x00, 0x40, 0x00, 0x04, 0x00, 0x08, 0x00, 0x40, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x20, 0x00, 0x80, 0x00, 0x00, 0x7E, 0x00, 0x08, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x7E, 0x00, 0x18, 0x00, 0x80, 0x03, 0x00, 0x10, 0x00, 0x38, 0x00, 0x18, 0x00, 0xE0, 0x07, 0x00,
    0x00, 0x00, 0xE0, 0x08, 0x48, 0x44, 0x40, 0x11, 0x01, 0x45, 0x04, 0x12, 0x11, 0x80, 0x38, 0x00,
    0x00, 0x00, 0x08, 0x02, 0xC0, 0x06, 0x00, 0x04, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x20, 0x08, 0x40,
    0x40, 0x00, 0x01, 0x01, 0x04, 0x04, 0x20, 0x08, 0x00, 0x3F, 0x00, 0x92, 0x00, 0x44, 0x04, 0x10,
    0x11, 0x40, 0x44, 0x00, 0x92, 0x00, 0x70, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0x01, 0x02,
    0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0xE0, 0x7F, 0x00, 0x01,
    0x01, 0x04, 0x06, 0x12, 0x16, 0x50, 0x44, 0x40, 0x0D, 0x81, 0x0C, 0x04, 0x10, 0x10, 0x08, 0x00,
    0xC0, 0x00, 0x00, 0x04, 0x80, 0x60, 0x00, 0x00, 0x7E, 0x08, 0x06, 0x00, 0x04, 0x00, 0x0C, 0x00,
    0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0, 0xFF, 0x00, 0x00, 0x00, 0x7C, 0x00, 0x08, 0x32,
    0x10, 0x3C, 0x40, 0x4E, 0x00, 0x07, 0x81, 0x0B, 0x02, 0x40, 0x04, 0x00, 0x41, 0xC0, 0xC7, 0x80,
    0xF1, 0x02, 0x42, 0x08, 0x08, 0x21, 0x20, 0x00, 0x01, 0x01, 0x04, 0x08, 0x08, 0x00, 0x00, 0x00,
    0x2D, 0x00, 0x48, 0x00, 0x10, 0x02, 0x40, 0x08, 0x00, 0x12, 0x00, 0xB4, 0x00, 0x82, 0x02, 0x10,
    0x0A, 0x80, 0x29, 0x00, 0xB8, 0x00, 0x80, 0x1F, 0x80, 0x0B, 0x80, 0x29, 0x00, 0xA1, 0x00, 0x82,
    0x02, 0x00, 0x00, 0xE0, 0xC7, 0x0F, 0x60, 0x08, 0x5C, 0x42, 0xC8, 0x10, 0x22, 0x42, 0x88, 0x10,
    0x22, 0x42, 0x98, 0x30, 0xD2, 0x01, 0x30, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x3F,
    0x00, 0x02, 0x01, 0x04, 0x08, 0xC8, 0x47, 0xA0, 0x20, 0x81, 0x82, 0x04, 0x0A, 0x12, 0x28, 0x48,
    0x20, 0x11, 0x01, 0x01, 0x02, 0x08, 0x04, 0xC0, 0x0F, 0x40, 0x03, 0x80, 0x14, 0x00, 0x4A, 0x00,
    0x28, 0x01, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1B, 0x00, 0x82, 0x00, 0x40, 0x00,
    0xC0, 0x06, 0x80, 0x20, 0x00, 0x00, 0x00, 0x08, 0x00, 0x20, 0x00, 0x80, 0x00, 0x00, 0x02, 0x00,
    0x08, 0x00, 0x20, 0x00, 0x80, 0x0F, 0x00, 0x20, 0x00, 0x80, 0x00, 0x00, 0x02, 0x00, 0x08, 0x00,
    0x3F, 0x00, 0x02, 0x01, 0x04, 0x08, 0xE8, 0x4F, 0xA0, 0x04, 0x81, 0x12, 0x04, 0xCA, 0x10, 0x28,
    0x45, 0x20, 0x23, 0x01, 0x01, 0x02, 0x08, 0x04, 0xC0, 0x0F, 0x10, 0x00, 0x40, 0x00, 0x00, 0x01,
    0x00, 0x04, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x0C, 0x00, 0x48, 0x00, 0x20, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x41, 0x00, 0x04,
    0x01, 0x10, 0x04, 0xF8, 0x13, 0x00, 0x41, 0x00, 0x04, 0x01, 0x10, 0x04, 0x44, 0x00, 0x88, 0x01,
    0x20, 0x05, 0x80, 0x14, 0x00, 0x4C, 0x00, 0x90, 0x00, 0x20, 0x04, 0x80, 0x10, 0x00, 0x4A, 0x00,
    0xD8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x3F,
    0x00, 0x08, 0x00, 0x40, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x08, 0xC0, 0x7F, 0xC0, 0x03, 0x80,
    0x0F, 0x00, 0x7E, 0x00, 0xF8, 0x01, 0xE0, 0xFF, 0x8F, 0x00, 0x00, 0x02, 0x00, 0xF8, 0xFF, 0x23,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x28, 0x00, 0xC0, 0x00,
    0x00, 0x40, 0x00, 0x80, 0x00, 0x00, 0x7E, 0x00, 0xF0, 0x00, 0x20, 0x04, 0x80, 0x10, 0x00, 0x42,
    0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x08, 0x00, 0x1B, 0x00, 0x10, 0x00, 0x08,
    0x02, 0xC0, 0x06, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x10, 0xF8, 0x21, 0x00, 0x40,
    0x00, 0xC0, 0x00, 0x80, 0x00, 0x80, 0x01, 0x00, 0xC1, 0x00, 0x83, 0x02, 0x02, 0x09, 0x00, 0x7E,
    0x00, 0x80, 0x00, 0x00, 0x00, 0x04, 0x00, 0x08, 0x40, 0xE0, 0xC7, 0x00, 0x80, 0x00, 0x00, 0x01,
    0x00, 0x03, 0x00, 0x02, 0x00, 0x46, 0x04, 0x84, 0x18, 0x08, 0x52, 0x00, 0x48, 0x01, 0xC0, 0x04,
    0x24, 0x00, 0x08, 0x01, 0x20, 0x04, 0x81, 0x12, 0x02, 0x36, 0x06, 0x00, 0x04, 0x00, 0x0C, 0x00,
    0x08, 0x00, 0x10, 0x0C, 0x30, 0x28, 0x20, 0x90, 0x00, 0xE0, 0x07, 0x00, 0x08, 0x00, 0x00, 0x00,
    0x80, 0x03, 0x00, 0x11, 0x00, 0x82, 0x40, 0x07, 0x02, 0x00, 0x08, 0x00, 0x20, 0x00, 0x40, 0x00,
    0xC0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x07, 0x80, 0x07, 0xC4, 0x11, 0xA0, 0x40, 0x00, 0x1C,
    0x01, 0x80, 0x07, 0x00, 0x70, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x60, 0x00, 0x70, 0x00, 0x78,
    0x00, 0x1C, 0x01, 0x0A, 0x04, 0xC4, 0x11, 0x00, 0x78, 0x00, 0x00, 0x07, 0x00, 0x60, 0x00, 0x00,
    0x00, 0x00, 0x06, 0x00, 0x07, 0x80, 0x07, 0xC8, 0x11, 0x90, 0x40, 0x40, 0x1C, 0x01, 0x82, 0x07,
    0x00, 0x70, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x60, 0x00, 0x70, 0x00, 0x78, 0x80, 0x1C, 0x01,
    0x09, 0x04, 0xC8, 0x11, 0x10, 0x78, 0x00, 0x00, 0x07, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x06,
    0x00, 0x07, 0x80, 0x07, 0xC8, 0x11, 0x80, 0x40, 0x80, 0x1C, 0x01, 0x80, 0x07, 0x00, 0x70, 0x00,
    0x00, 0x06, 0x00, 0x00, 0x00, 0x60, 0x00, 0x70, 0x00, 0x78, 0x80, 0x1F, 0x01, 0x0A, 0x04, 0xF8,
    0x11, 0x00, 0x78, 0x00, 0x00, 0x07, 0x00, 0x60, 0x00, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80,
    0x05, 0x80, 0x11, 0x80, 0x41, 0x00, 0x02, 0x01, 0x08, 0x04, 0xE0, 0xFF, 0x81, 0x10, 0x04, 0x42,
    0x10, 0x08, 0x41, 0x20, 0x04, 0x81, 0x10, 0x04, 0x42, 0x10, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x02,
    0x01, 0x04, 0x08, 0x08, 0x40, 0x20, 0x00, 0x89, 0x00, 0x2C, 0x02, 0xD0, 0x08, 0x40, 0x40, 0x80,
    0x00, 0x02, 0x01, 0x00, 0x00, 0xF8, 0x7F, 0x20, 0x04, 0x81, 0x10, 0x04, 0x42, 0x10, 0x09, 0x41,
    0x28, 0x04, 0x81, 0x10, 0x04, 0x42, 0x10, 0x08, 0x40, 0x00, 0x00, 0x80, 0xFF, 0x07, 0x42, 0x10,
    0x08, 0x41, 0x20, 0x04, 0xA1, 0x10, 0x44, 0x42, 0x10, 0x08, 0x41, 0x20, 0x04, 0x81, 0x00, 0x04,
    0x00, 0x00, 0xF8, 0x7F, 0x20, 0x04, 0x81, 0x10, 0x84, 0x42, 0x10, 0x09, 0x41, 0x24, 0x04, 0xA1,
    0x10, 0x04, 0x42, 0x10, 0x08, 0x40, 0x00, 0x00, 0x80, 0xFF, 0x07, 0x42, 0x10, 0x08, 0x41, 0x28,
    0x04, 0x81, 0x10, 0x84, 0x42, 0x10, 0x08, 0x41, 0x20, 0x04, 0x81, 0x00, 0x44, 0x00, 0x00, 0xFA,
    0x7F, 0x00, 0x00, 0xA0, 0xFF, 0x47, 0x00, 0x00, 0x02, 0x00, 0xE4, 0xFF, 0x11, 0x00, 0x80, 0x00,
    0x00, 0x02, 0x00, 0xE0, 0xFF, 0x21, 0x00, 0x00, 0x80, 0x00, 0xF8, 0x7F, 0x20, 0x08, 0x81, 0x20,
    0x04, 0x82, 0x10, 0x08, 0x42, 0x20, 0x00, 0x81, 0x00, 0x04, 0x04, 0x08, 0x20, 0x10, 0x00, 0x3F,
    0x00, 0x00, 0x00, 0xFE, 0x1F, 0x10, 0x00, 0x80, 0x01, 0x20, 0x08, 0x40, 0xC0, 0x00, 0x02, 0x04,
    0x04, 0x60, 0x00, 0x00, 0x02, 0xFE, 0x1F, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x02, 0x01, 0x04, 0x08,
    0x08, 0x40, 0x24, 0x00, 0xA1, 0x00, 0x04, 0x02, 0x10, 0x10, 0x20, 0x80, 0x40, 0x00, 0xFC, 0x00,
    0x00, 0x00, 0xC0, 0x0F, 0x80, 0x40, 0x00, 0x01, 0x02, 0x02, 0x10, 0x0A, 0x40, 0x24, 0x00, 0x81,
    0x00, 0x04, 0x04, 0x08, 0x20, 0x10, 0x00, 0x3F, 0x00, 0x00, 0x00, 0xF0, 0x03, 0x20, 0x10, 0x40,
    0x80, 0xA0, 0x00, 0x44, 0x02, 0x10, 0x09, 0x40, 0x28, 0x00, 0x01, 0x01, 0x02, 0x08, 0x04, 0xC0,
    0x0F, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x08, 0x04, 0x10, 0x20, 0x28, 0x00, 0x91, 0x00, 0x84, 0x02,
    0x10, 0x09, 0x40, 0x40, 0x80, 0x00, 0x02, 0x01, 0xF0, 0x03, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x02,
    0x01, 0x04, 0x08, 0x08, 0x40, 0x28, 0x00, 0x81, 0x00, 0x84, 0x02, 0x10, 0x10, 0x20, 0x80, 0x40,
    0x00, 0xFC, 0x00, 0x00, 0x00, 0x40, 0x10, 0x00, 0x22, 0x00, 0x50, 0x00, 0xC0, 0x01, 0x00, 0x05,
    0x00, 0x22, 0x00, 0x04, 0x01, 0x00, 0x00, 0xC0, 0x4F, 0x80, 0xC0, 0x00, 0x01, 0x03, 0x02, 0x13,
    0x08, 0x42, 0x20, 0x04, 0x81, 0x0C, 0x04, 0x0C, 0x08, 0x30, 0x10, 0x20, 0x3F, 0x00, 0x00, 0x00,
    0xFE, 0x07, 0x00, 0x20, 0x00, 0x00, 0x11, 0x00, 0x84, 0x00, 0x10, 0x00, 0x40, 0x00, 0x00, 0x01,
    0x00, 0x02, 0xFE, 0x07, 0x00, 0x00, 0xE0, 0x7F, 0x00, 0x00, 0x02, 0x00, 0x10, 0x00, 0x40, 0x08,
    0x00, 0x11, 0x00, 0x04, 0x00, 0x10, 0x00, 0x20, 0xE0, 0x7F, 0x00, 0x00, 0x00, 0xFE, 0x07, 0x00,
    0x20, 0x00, 0x00, 0x21, 0x00, 0x44, 0x00, 0x10, 0x01, 0x40, 0x08, 0x00, 0x01, 0x00, 0x02, 0xFE,
    0x07, 0x00, 0x00, 0xE0, 0x7F, 0x00, 0x00, 0x02, 0x00, 0x10, 0x02, 0x40, 0x00, 0x00, 0x21, 0x00,
    0x04, 0x00, 0x10, 0x00, 0x20, 0xE0, 0x7F, 0x80, 0x00, 0x00, 0x0C, 0x00, 0x40, 0x00, 0x00, 0x06,
    0x20, 0xE0, 0x47, 0x60, 0x00, 0x40, 0x00, 0xC0, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x7F,
    0x80, 0x40, 0x00, 0x02, 0x01, 0x08, 0x04, 0x20, 0x10, 0x80, 0x40, 0x00, 0x02, 0x01, 0x10, 0x02,
    0x80, 0x07, 0x00, 0x00, 0x00, 0xFE, 0x07, 0x04, 0x00, 0x08, 0x20, 0x20, 0x06, 0x01, 0x27, 0x04,
    0x00, 0x11, 0x00, 0x38, 0x00, 0x00, 0x00, 0x90, 0x03, 0x20, 0x11, 0x40, 0x44, 0x20, 0x11, 0x01,
    0x25, 0x04, 0x90, 0x08, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x90, 0x03, 0x20, 0x11, 0x40, 0x44, 0x40,
    0x11, 0x81, 0x24, 0x04, 0x90, 0x08, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x90, 0x03, 0x20, 0x11, 0x50,
    0x44, 0x20, 0x11, 0x81, 0x24, 0x04, 0x94, 0x08, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x90, 0x03, 0x20,
    0x11, 0x50, 0x44, 0x20, 0x11, 0x01, 0x25, 0x04, 0x92, 0x08, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x90,
    0x03, 0x20, 0x11, 0x50, 0x44, 0x00, 0x11, 0x01, 0x25, 0x04, 0x90, 0x08, 0x80, 0x7F, 0x00, 0x00,
    0x00, 0x90, 0x03, 0x20, 0x11, 0x5C, 0x44, 0x50, 0x11, 0xC1, 0x25, 0x04, 0x90, 0x08, 0x80, 0x7F,
    0x00, 0x00, 0x00, 0x90, 0x03, 0x20, 0x11, 0x40, 0x44, 0x00, 0x11, 0x01, 0x24, 0x04, 0x90, 0x08,
    0x80, 0x3F, 0x00, 0x92, 0x00, 0x44, 0x04, 0x10, 0x11, 0x40, 0x44, 0x00, 0x92, 0x00, 0x70, 0x01,
    0x00, 0x00, 0x00, 0x1F, 0x00, 0x82, 0x00, 0x04, 0x24, 0x10, 0xB0, 0x40, 0x40, 0x03, 0x82, 0x00,
    0x00, 0x00, 0xC0, 0x07, 0x80, 0x24, 0x20, 0x11, 0x01, 0x45, 0x04, 0x10, 0x11, 0x80, 0x24, 0x00,
    0x5C, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x80, 0x24, 0x00, 0x11, 0x01, 0x45, 0x04, 0x12, 0x11, 0x80,
    0x24, 0x00, 0x5C, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x80, 0x24, 0x40, 0x11, 0x81, 0x44, 0x04, 0x12,
    0x11, 0x90, 0x24, 0x00, 0x5C, 0x00, 0x00, 0x00, 0xC0, 0x07, 0x80, 0x24, 0x40, 0x11, 0x01, 0x44,
    0x04, 0x14, 0x11, 0x80, 0x24, 0x00, 0x5C, 0x80, 0x00, 0x00, 0xF4, 0x1F, 0x00, 0x00, 0x40, 0xFF,
    0x81, 0x00, 0x00, 0x04, 0x00, 0xC8, 0x7F, 0x20, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0xC0, 0x7F,
    0x40, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x07, 0xA0, 0x20, 0xA0, 0x01, 0x81, 0x05, 0x04, 0x1C, 0x10,
    0xE8, 0x20, 0x00, 0x7C, 0x00, 0x00, 0x00, 0xF0, 0x1F, 0x90, 0x00, 0x20, 0x01, 0x00, 0x05, 0x00,
    0x12, 0x00, 0x80, 0x7F, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x20, 0x08, 0x48, 0x40, 0x40, 0x01, 0x01,
    0x04, 0x04, 0x20, 0x08, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x20, 0x08, 0x40, 0x40, 0x40,
    0x01, 0x81, 0x04, 0x04, 0x20, 0x08, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x20, 0x08, 0x50,
    0x40, 0x20, 0x01, 0x81, 0x04, 0x04, 0x24, 0x08, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x20,
    0x08, 0x50, 0x40, 0x20, 0x01, 0x01, 0x05, 0x04, 0x22, 0x08, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xF0,
    0x01, 0x20, 0x08, 0x50, 0x40, 0x00, 0x01, 0x01, 0x05, 0x04, 0x20, 0x08, 0x00, 0x1F, 0x00, 0x00,
    0x00, 0x20, 0x00, 0x80, 0x00, 0x00, 0x02, 0x00, 0x2A, 0x00, 0x20, 0x00, 0x80, 0x00, 0x00, 0x02,
    0x00, 0x00, 0x00, 0xF0, 0x05, 0x20, 0x0C, 0x40, 0x48, 0x00, 0x11, 0x01, 0x24, 0x04, 0x60, 0x08,
    0x40, 0x1F, 0x00, 0x00, 0x00, 0xFC, 0x03, 0x00, 0x10, 0x08, 0x40, 0x40, 0x00, 0x01, 0x00, 0x02,
    0xF0, 0x1F, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x04, 0x00, 0x10, 0x10, 0x40, 0x20, 0x80, 0x00,
    0xFC, 0x07, 0x00, 0x00, 0xC0, 0x3F, 0x40, 0x00, 0x81, 0x00, 0x04, 0x02, 0x10, 0x10, 0x20, 0x00,
    0xFF, 0x01, 0x00, 0x00, 0xF0, 0x0F, 0x10, 0x40, 0x00, 0x00, 0x01, 0x01, 0x04, 0x00, 0x08, 0xC0,
    0x7F, 0x00, 0x07, 0x00, 0x60, 0x20, 0x00, 0x8E, 0x10, 0xC0, 0x21, 0xE0, 0x00, 0x70, 0x00, 0x30,
    0x00, 0x00, 0x00, 0xE0, 0xFF, 0x0F, 0x08, 0x02, 0x10, 0x10, 0x40, 0x40, 0x00, 0x01, 0x01, 0x08,
    0x02, 0xC0, 0x07, 0xC0, 0x01, 0x00, 0x18, 0x08, 0x81, 0x23, 0x00, 0x70, 0x10, 0x38, 0x00, 0x1C,
    0x00, 0x0C, 0x00, 0x00
};

#endif

