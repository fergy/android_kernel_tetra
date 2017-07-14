/*
 * GC2035 sensor driver
 *
 * This program is free software; you can redistribute it and/or
 *modify it under the terms of the GNU General Public License as
 *published by the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 *kind, whether express or implied; without even the implied warranty
 *of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __GC2035_H__
#define __GC2035_H__

#define ENABLE_COLOR_PATTERN 0

#define GC2035_SATURATION_MIN			0
#define GC2035_SATURATION_MAX			200
#define GC2035_SATURATION_STEP          100
#define GC2035_SATURATION_DEF			100

#define GC2035_SHARPNESS_MIN			0
#define GC2035_SHARPNESS_MAX			200
#define GC2035_SHARPNESS_STEP           100
#define GC2035_SHARPNESS_DEF			100

#define GC2035_REG_DELAY                (0xFFFE)
#define GC2035_REG_END                  (0xFFFF)

/**
 *struct gc2035_reg - gc2035 register format
 *@reg: 16-bit offset to register
 *@val: 8/16/32-bit register value
 *@length: length of the register
 *
 * Define a structure for GC2035 register initialization values
 */
struct gc2035_reg {
	u16 reg;
	u8 val;
};

/* TODO: Divide this properly */
static const struct gc2035_reg configscript_common1[] = {
	{0xfe, 0x80},
	{0xfe, 0x80},
	{0xfe, 0x80},
	{0xfc, 0x06},
	{0xf9, 0xfe},
	{0xfa, 0x00},
	{0xf6, 0x00},

#if defined(_MAXCLK_104_)
	{0xf7, 0x05},
	{0xf8, 0x87},
#else
	{0xf7, 0x05},
	{0xf8, 0x85},
#endif
	{0xfe, 0x00},
	{0x82, 0x00},
	{0xb3, 0x60},
	{0xb4, 0x40},
	{0xb5, 0x60},
	{0x03, 0x05},
	{0x04, 0x08},
	{0xfe, 0x00},
	{0xec, 0x04},
	{0xed, 0x04},
	{0xee, 0x60},
	{0xef, 0x90},
	{0x0a, 0x00},
	{0x0c, 0x00},
	{0x0d, 0x04},
	{0x0e, 0xc0},
	{0x0f, 0x06},
	{0x10, 0x58},
	{0x17, 0x17},
	{0x18, 0x0a},
	{0x19, 0x0c},
	{0x1a, 0x01},
	{0x1b, 0x48},
	{0x1e, 0x88},
	{0x1f, 0x0f},
	{0x20, 0x05},
	{0x21, 0x0f},
	{0x22, 0xf0},
	{0x23, 0xc3},
	{0x24, 0x16},
	{0xfe, 0x01},
	{0x09, 0x00},
	{0x0b, 0x90},
	{0x13, 0x78},
	{0xfe, 0x00},
	{0xfe, 0x00},

#if defined(_MAXCLK_104_)
	{0x03, 0x05},
	{0x04, 0x3a},
	{0x05, 0x01},
	{0x06, 0x39},
	{0x07, 0x00},
	{0x08, 0x6a},
	{0xfe, 0x01},
	{0x27, 0x00},
	{0x28, 0xdf},
	{0x29, 0x05},
	{0x2a, 0x3a},
	{0x2b, 0x06},
	{0x2c, 0x19},
	{0x2d, 0x07},
	{0x2e, 0xd7},
	{0x2f, 0x0d},
	{0x30, 0xf0},
	{0x3e, 0x00},
#else
	{0x03, 0x05},
	{0x04, 0x08},
	{0x05, 0x00},
	{0x06, 0xd0},
	{0x07, 0x00},
	{0x08, 0x38},
	{0xfe, 0x01},
	{0x27, 0x00},
	{0x28, 0xb8},
	{0x29, 0x05},
	{0x2a, 0x08},
	{0x2b, 0x05},
	{0x2c, 0xc0},
	{0x2d, 0x06},
	{0x2e, 0x78},
	{0x2f, 0x0b},
	{0x30, 0x80},
	{0x3e, 0x00},
#endif

	{0xfe, 0x00},
	{0xb6, 0x03},
	{0xfe, 0x00},
	{0x3f, 0x00},
	{0x40, 0x77},
	{0x42, 0x7f},
	{0x43, 0x30},
	{0x5c, 0x08},
	{0x5e, 0x20},
	{0x5f, 0x20},
	{0x60, 0x20},
	{0x61, 0x20},
	{0x62, 0x20},
	{0x63, 0x20},
	{0x64, 0x20},
	{0x65, 0x20},
	{0x66, 0x20},
	{0x67, 0x20},
	{0x68, 0x20},
	{0x69, 0x20},
	{0x90, 0x01},
	{0x95, 0x04},
	{0x96, 0xb0},
	{0x97, 0x06},
	{0x98, 0x40},
	{0xfe, 0x03},
	{0x42, 0x80},
	{0x43, 0x06},
	{0x41, 0x00},
	{0x40, 0x00},
	{0x17, 0x01},
	{0xfe, 0x00},
	{0x80, 0xff},
	{0x81, 0x26},
	{0x03, 0x05},
	{0x04, 0x2e},
	{0x84, 0x00},
	{0x86, 0x02},
	{0x87, 0x80},
	{0x8b, 0xbc},
	{0xa7, 0x80},
	{0xa8, 0x80},
	{0xb0, 0x80},
	{0xc0, 0x40},
	{0xfe, 0x01},

/*0x17=0x15   //left Red --right Green*/
	{0xc2, 0x1e},
	{0xc3, 0x10},
	{0xc4, 0x09},
	{0xc8, 0x16},
	{0xc9, 0x0a},
	{0xca, 0x00},
	{0xbc, 0x1a},
	{0xbd, 0x12},
	{0xbe, 0x0b},
	{0xb6, 0x30},
	{0xb7, 0x09},
	{0xb8, 0x00},

	{0xc5, 0x00},
	{0xc6, 0x00},
	{0xc7, 0x00},
	{0xcb, 0x00},
	{0xcc, 0x0b},
	{0xcd, 0x16},
	{0xbf, 0x00},
	{0xc0, 0x00},
	{0xc1, 0x00},
	{0xb9, 0x0c},
	{0xba, 0x00},
	{0xbb, 0x12},
	{0xaa, 0x00},
	{0xab, 0x00},
	{0xac, 0x00},
	{0xad, 0x12},
	{0xae, 0x00},
	{0xaf, 0x00},
	{0xb0, 0x00},
	{0xb1, 0x00},
	{0xb2, 0x00},
	{0xb3, 0x00},
	{0xb4, 0x00},
	{0xb5, 0x06},
	{0xd0, 0x00},
	{0xd2, 0x0e},
	{0xd3, 0x0b},
	{0xd8, 0x21},
	{0xda, 0x18},
	{0xdb, 0x18},
	{0xdc, 0x00},
	{0xde, 0x09},
	{0xdf, 0x00},
	{0xd4, 0x08},
	{0xd6, 0x0e},
	{0xd7, 0x00},
	{0xa4, 0x00},
	{0xa5, 0x00},
	{0xa6, 0x40},
	{0xa7, 0x00},
	{0xa8, 0x00},
	{0xa9, 0x40},
	{0xa1, 0x80},
	{0xa2, 0x80},

	{0xfe, 0x02},
	{0xa4, 0x00},
	{0xfe, 0x00},
	{0xfe, 0x02},
	{0xc0, 0x01},
	{0xc1, 0x40},
	{0xc2, 0xfc},
	{0xc3, 0x05},
	{0xc4, 0xec},
	{0xc5, 0x42},
	{0xc6, 0xf8},
	{0xc7, 0x40},
	{0xc8, 0xf8},
	{0xc9, 0x06},
	{0xca, 0xfd},
	{0xcb, 0x3e},
	{0xcc, 0xf3},
	{0xcd, 0x36},
	{0xce, 0xf6},
	{0xcf, 0x04},
	{0xe3, 0x0c},
	{0xe4, 0x44},
	{0xe5, 0xe5},
	{0xfe, 0x00},
	{0xfe, 0x01},
	{0x4f, 0x00},
	{0x4d, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0x10},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0x20},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0x30},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x02},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0x40},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x04},
	{0x4e, 0x02},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0x50},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x08},
	{0x4e, 0x08},
	{0x4e, 0x04},
	{0x4e, 0x04},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0x60},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x20},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0x70},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x20},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0x80},
	{0x4e, 0x00},
	{0x4e, 0x20},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0x90},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0xa0},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0xb0},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0xc0},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0xd0},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0xe0},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4d, 0xf0},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4e, 0x00},
	{0x4f, 0x01},
	{0x50, 0x80},
	{0x56, 0x06},

	{0x52, 0x40},
	{0x54, 0x60},
	{0x57, 0x20},
	{0x58, 0x01},
	{0x5b, 0x08},
	{0x61, 0xaa},
	{0x62, 0xaa},
	{0x71, 0x00},
	{0x72, 0x25},
	{0x74, 0x10},
	{0x77, 0x08},
	{0x78, 0xfd},
	{0x86, 0x30},
	{0x87, 0x00},
	{0x88, 0x04},
	{0x8a, 0xc0},
	{0x89, 0x71},
	{0x84, 0x08},
	{0x8b, 0x00},
	{0x8d, 0x70},
	{0x8e, 0x70},
	{0x8f, 0xf4},
	{0xfe, 0x00},
	{0x82, 0x02},
	{0xfe, 0x01},
	{0x21, 0xbf},
	{0xfe, 0x02},
	{0xa5, 0x50},
	{0xa2, 0xb0},
	{0xa6, 0x50},
	{0xa7, 0x30},
	{0xab, 0x31},
	{0x88, 0x15},
	{0xa9, 0x6c},
	{0xb0, 0x55},
	{0xb3, 0x70},
	{0x8c, 0xf6},
	{0x89, 0x03},
	{0xde, 0xb6},
	{0x38, 0x08},
	{0x39, 0x50},
	{0xfe, 0x00},
	{0x81, 0x26},
	{0x87, 0x80},
	{0xfe, 0x02},
	{0x83, 0x00},
	{0x84, 0x45},
	{0xd1, 0x38},
	{0xd2, 0x38},
	{0xdd, 0x38},
	{0xfe, 0x00},
	{0xfe, 0x02},
	{0x2b, 0x00},
	{0x2c, 0x04},
	{0x2d, 0x09},
	{0x2e, 0x18},
	{0x2f, 0x27},
	{0x30, 0x37},
	{0x31, 0x49},
	{0x32, 0x5c},
	{0x33, 0x7e},
	{0x34, 0xa0},
	{0x35, 0xc0},
	{0x36, 0xe0},
	{0x37, 0xff},
	{0xfe, 0x00},
	{0x82, 0xfe},
	/*MIPI */
	{0xf2, 0x00},
	{0xf3, 0x00},
	{0xf4, 0x00},
	{0xf5, 0x00},
	{0xfe, 0x01},
	{0x0b, 0x90},
	{0x87, 0x10},
	{0xfe, 0x00},

	{0xfe, 0x03},
	{0x01, 0x03},
	{0x02, 0x11},
	{0x03, 0x10},
	{0x06, 0x90},
	{0x11, 0x1E},
	{0x12, 0x80},
	{0x13, 0x0c},
	{0x15, 0x12},
	{0x04, 0x20},
	{0x05, 0x00},
	{0x17, 0x00},

	{0x21, 0x01},

#if defined(_MAXCLK_104_)
	{0x22, 0x03},
	{0x23, 0x05},
	{0x29, 0x03},
	{0x2a, 0x05},
#else
	{0x22, 0x02},
	{0x23, 0x03},
	{0x29, 0x02},  /*settle time*/
	{0x2a, 0x03},  /*settle time  280ns*/
#endif

	{0x10, 0x94},
	{0xfe, 0x00},

	{GC2035_REG_END, 0x00},
};

static const struct gc2035_reg gc2035_mode[][64] = {
	/* VGA */
	{
		{0x17, 0x17},/*0x14*/
		{0xfa, 0x00},
		{0xb6, 0x03},
		{GC2035_REG_DELAY, 200},
		{0xc8, 0x15},

		{0x90, 0x01},
		{0x95, 0x01},
		{0x96, 0xe0},
		{0x97, 0x02},
		{0x98, 0x80},

		{0xfe, 0x03},
		{0x12, 0x00},
		{0x13, 0x05},
		{0x04, 0x90},
		{0x05, 0x00},
		{0xfe, 0x00},

		{GC2035_REG_END, 0x00}
	},
	/* UXGA */
	{
		{0x17, 0x17},/*0x14*/
		{0xfa, 0x11},
		{0xb6, 0x00},
		{0xc8, 0x00},

		{0x90, 0x01},
		{0x95, 0x04},
		{0x96, 0xb0},
		{0x97, 0x06},
		{0x98, 0x40},

		{0xfe, 0x03},
		{0x12, 0x80},
		{0x13, 0x0c},
		{0x04, 0x20},
		{0x05, 0x00},
		{0xfe, 0x00},

		{GC2035_REG_END, 0x00}
	},
};

static const struct gc2035_reg gc2035_streamon[] = {
	{0xfe, 0x03},
	{0x10, 0x94},
	{0xfe, 0x00},
	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_streamoff[] = {
	{0xfe, 0x03},
	{0x10, 0x00},
	{0xfe, 0x00},
	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_power_down[] = {
	/* System Control */

	{GC2035_REG_END, 0x00}
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*EFFECT */
static const struct gc2035_reg gc2035_effect_normal_tbl[] = {
	{0xfe, 0x00},
	{0x83, 0xe0},
	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_effect_bw_tbl[] = {
	{0xfe, 0x00},
	{0x83, 0x12},
	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_effect_sepia_tbl[] = {
	{0xfe, 0x00},
	{0x83, 0x82},
	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_effect_negative_tbl[] = {
	{0xfe, 0x00},
	{0x83, 0x01},
	{GC2035_REG_END, 0x00}
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*AntiBanding */
static const struct gc2035_reg gc2035_antibanding_auto_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_antibanding_50z_tbl[] = {


	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_antibanding_60z_tbl[] = {

	{GC2035_REG_END, 0x00}
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*Lens_shading*/

static const struct gc2035_reg gc2035_lens_shading_on_tbl[] = {

	{GC2035_REG_END, 0x00}
};


static const struct gc2035_reg gc2035_lens_shading_off_tbl[] = {
	/*@@ Lenc Off */


	{GC2035_REG_END, 0x00}
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*Contrast */

static const struct gc2035_reg gc2035_contrast_default_lv3_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_contrast_lv0_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_contrast_lv1_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_contrast_lv2_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_contrast_lv4_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_contrast_lv5_tbl[] = {

	{GC2035_REG_END, 0x00}
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*sharpness */

static const struct gc2035_reg gc2035_sharpness_default_lv2_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_sharpness_lv0_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_sharpness_lv1_tbl[] = {


	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_sharpness_lv3_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_sharpness_lv4_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_sharpness_lv5_tbl[] = {

	{GC2035_REG_END, 0x00}
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* saturation */

static const struct gc2035_reg gc2035_saturation_default_lv3_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_saturation_lv0_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_saturation_lv1_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_saturation_lv2_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_saturation_lv4_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_saturation_lv5_tbl[] = {

	{GC2035_REG_END, 0x00}
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* brightness */

static const struct gc2035_reg gc2035_brightness_lv0_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_brightness_lv1_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_brightness_lv2_default_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_brightness_lv3_tbl[] = {


	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_brightness_lv4_tbl[] = {

	{GC2035_REG_END, 0x00}
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Auto Expourse */

static const struct gc2035_reg gc2035_ae_average_tbl[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_ae_centerweight_tbl[] = {

	{GC2035_REG_END, 0x00}
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*default awb */
static const struct gc2035_reg gc2035_wb_def[] = {

	{GC2035_REG_END, 0x00}
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* White Balance */
static const struct gc2035_reg gc2035_wb_fluorescent[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_wb_daylight[] = {


	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_wb_cloudy[] = {


	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_wb_tungsten[] = {


	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_fps_5[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_fps_7[] = {

	{GC2035_REG_END, 0x00}
};
static const struct gc2035_reg gc2035_fps_10[] = {

	{GC2035_REG_END, 0x00}
};
static const struct gc2035_reg gc2035_fps_15[] = {

	{GC2035_REG_END, 0x00}
};
static const struct gc2035_reg gc2035_fps_20[] = {

	{GC2035_REG_END, 0x00}
};
static const struct gc2035_reg gc2035_fps_25[] = {

	{GC2035_REG_END, 0x00}
};

static const struct gc2035_reg gc2035_fps_30[] = {


	{GC2035_REG_END, 0x00}
};


#endif /* __GC2035_H__ */
