/*
 * OmniVision OV7695 sensor driver
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

#ifndef __OV7695_H__
#define __OV7695_H__

#define ENABLE_COLOR_PATTERN 0

#define OV7695_SATURATION_MIN			0
#define OV7695_SATURATION_MAX			200
#define OV7695_SATURATION_STEP          100
#define OV7695_SATURATION_DEF			100

#define OV7695_SHARPNESS_MIN			0
#define OV7695_SHARPNESS_MAX			200
#define OV7695_SHARPNESS_STEP           100
#define OV7695_SHARPNESS_DEF			100

/**
 *struct ov7695_reg - ov7695 register format
 *@reg: 16-bit offset to register
 *@val: 8/16/32-bit register value
 *@length: length of the register
 *
 * Define a structure for OV7695 register initialization values
 */
struct ov7695_reg {
	u16 reg;
	u8 val;
};

/* TODO: Divide this properly */
static const struct ov7695_reg yuv422_init_common[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg jpeg_init_common[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_init_common[] = {
	{0x0103, 0x01}, /* software reset */
	{0x3620, 0x2f},
	{0x3623, 0x12},
	{0x3718, 0x88},
	{0x3631, 0x44},
	{0x3632, 0x05},
	{0x3013, 0xd0},
	{0x3705, 0x1d},
	{0x3713, 0x0e},
	{0x3012, 0x0a},
	{0x3717, 0x19},
#ifdef CONFIG_MACH_HAWAII_GARNET_C_W68TK
	{0x0307, 0x76},
#endif
	{0x0309, 0x24}, /* DAC clk div by 4 */
	{0x3820, 0x90},
	{0x5100, 0x01}, /* lenc */
	{0x520a, 0xf4}, /* red gain from 0x400 to 0xfff */
	{0x520b, 0xf4}, /* green gain from 0x400 to 0xfff */
	{0x520c, 0xf4}, /* blue gain from 0x400 to 0xfff */
	{0x3a18, 0x01}, /* gain ceiling 0x100 */
	{0x3a19, 0x00}, /* gain ceiling */
	{0x3503, 0x03}, /* AGC manual on, AEC manual on */
	{0x3500, 0x00}, /* exposure */
	{0x3501, 0x21}, /* exposure */
	{0x3502, 0x00}, /* exposure */
	{0x350a, 0x00}, /* gain */
	{0x350b, 0x00}, /* gain */
	{0x4008, 0x02}, /* bl start */
	{0x4009, 0x09}, /* bl end */
	{0x3002, 0x09}, /* FSIN output */
	{0x3024, 0x00},
	{0x3503, 0x00}, /* AGC auto on, AEC auto on */
	{0x4300, 0x30}, /* format: UYVY */
	/* OV7695_ISP */
#if defined(CONFIG_MACH_HAWAII_GARNET_C_W68TK) ||\
	defined(CONFIG_MACH_JAVA_C_LC1) ||\
	defined(CONFIG_MACH_JAVA_C_5609A)
	{0x0101, 0x02}, /* mirror off, flip on */
#else
	{0x0101, 0x01}, /* mirror on, flip off */
#endif
	{0x5002, 0x40}, /* [7:6] Y source select, manual 60Hz */
	{0x5910, 0x00}, /* Y formula */
	{0x3a0f, 0x58}, /* AEC in H */
	{0x3a10, 0x48}, /* 38 ;AEC in L */
	{0x3a1b, 0x58}, /* 40 ;AEC out H */
	{0x3a1e, 0x48}, /* 36 ;AEC out L */
	{0x3a11, 0x90}, /* 80 ;control zone H */
	{0x3a1f, 0x40}, /* 18 ;control zone L */
	{0x3a18, 0x00}, /* gain ceiling */
	{0x3a19, 0x7f}, /* gain ceiling, max gain 15.5x */
	{0x3503, 0x00}, /* aec/agc auto on */
	{0x5000, 0xff}, /* lcd, gma, awb, awbg, bc, wc, lenc, isp */
	{0x5001, 0x3f}, /* avg, blc, sde, uv_avg, cmx, cip */
	/* AE */
	{0x3A00, 0x3c},
	{0x3a14, 0x06},
	{0x3a15, 0x48},
	{0x3a02, 0x06},
	{0x3a03, 0x48},
	{0x3a08, 0x00},
	{0x3a09, 0xa0},
	{0x3a0a, 0x00},
	{0x3a0b, 0x86},
	{0x3a0e, 0x0a},
	{0x3a0d, 0x0c},
	{0x382a, 0x08},
	/* brightness */
	{0x5807, 0x10},
	{0x5808, 0x08},
	/* lens */
	{0x5100, 0x01},
	{0x5101, 0x30},
	{0x5102, 0x00},
	{0x5103, 0xf0},
	{0x5104, 0x5f},
	{0x5105, 0x05},
	{0x5106, 0xff},
	{0x5107, 0x0f},
	{0x5108, 0x01},
	{0x5109, 0x20},
	{0x510a, 0x00},
	{0x510b, 0xda},
	{0x510c, 0x59},
	{0x510d, 0x06},
	{0x510e, 0xff},
	{0x510f, 0x0f},
	{0x5110, 0x01},
	{0x5111, 0x38},
	{0x5112, 0x00},
	{0x5113, 0xe8},
	{0x5114, 0x21},
	{0x5115, 0x05},
	{0x5116, 0xff},
	{0x5117, 0x0f},
	/* AWB */
	{0x520a, 0x74}, /* red gain from 0x400 to 0x7ff */
	{0x520b, 0x64}, /* green gain from 0x400 to 0x7ff */
	{0x520c, 0xd4}, /* blue gain from 0x400 to 0xdff */
	{0x5004, 0x42}, /* blue gain from 0x400 to 0xdff */
	/* Gamma */
	{0x5301, 0x05},
	{0x5302, 0x0c},
	{0x5303, 0x1c},
	{0x5304, 0x2a},
	{0x5305, 0x39},
	{0x5306, 0x45},
	{0x5307, 0x53},
	{0x5308, 0x5d},
	{0x5309, 0x68},
	{0x530a, 0x7f},
	{0x530b, 0x91},
	{0x530c, 0xa5},
	{0x530d, 0xc6},
	{0x530e, 0xde},
	{0x530f, 0xef},
	{0x5310, 0x16},
		/* sharpen/denoise */
	{0x5500, 0x08}, /* sharp th1 8x */
	{0x5501, 0x48}, /* sharp th2 8x */
	{0x5502, 0x12}, /* sharp mt offset1 */
	{0x5503, 0x03}, /* sharp mt offset2 */
	{0x5504, 0x08}, /* dns th1 8x */
	{0x5505, 0x48}, /* dns th2 8x */
	{0x5506, 0x08}, /* dns offset1 */
	{0x5507, 0x16}, /* dns offset2 */
	{0x5508, 0xad}, /* [6]:sharp_man [4]:dns_man */
	{0x5509, 0x08}, /* sharpth th1 8x */
	{0x550a, 0x48}, /* sharpth th2 8x */
	{0x550b, 0x06}, /* sharpth offset1 */
	{0x550c, 0x04}, /* sharpth offset2 */
	{0x550d, 0x01}, /* recursive_en */
	/* SDE, for saturation 120% under D65 */
	{0x5800, 0x06}, /* saturation on, contrast on */
	{0x5803, 0x2a}, /* 40 ; sat th2 */
	{0x5804, 0x1b}, /* 34 ; sat th1 */
	{0x580b, 0x02}, /* Y offset man on */
	/* CMX QE */
	{0x5600, 0x00}, /* mtx 1.7, UV CbCr disable */
	{0x5601, 0x2c}, /* CMX1 */
	{0x5602, 0x5a}, /* CMX2 */
	{0x5603, 0x06}, /* CMX3 */
	{0x5604, 0x1c}, /* CMX4 */
	{0x5605, 0x65}, /* CMX5 */
	{0x5606, 0x81}, /* CMX6 */
	{0x5607, 0x9f}, /* CMX7 */
	{0x5608, 0x8a}, /* CMX8 */
	{0x5609, 0x15}, /* CMX9 */
	{0x560a, 0x01}, /* Sign */
	{0x560b, 0x9c}, /* Sign */
	{0x3811, 0x07}, /* Tradeoff position to make YUV/RAW x VGA/QVGA x  */
			/* Mirror/Flip all work */
	{0x3813, 0x06},
	{0x3a05, 0xb0}, /* banding filter 50hz */
	/* MIPI */
	{0x4800, 0x20},
	{0x4801, 0x0e},
	{0x4802, 0x14},
	{0x4803, 0x0a},
	{0x4804, 0x0a},
	{0x4805, 0x0a},
	{0x4806, 0x30},
	{0x4807, 0x05},
	{0x0100, 0x01}, /* streaming */

	{0x034c, 0x02},
	{0x034d, 0x80},
	{0x034e, 0x01},
	{0x034f, 0xe0},
	{0x0340, 0x02},
	{0x0341, 0x18},
	{0x0342, 0x02},
	{0x0343, 0xea},

	{0xFFFF, 0xff},
};

static const struct ov7695_reg hawaii_preview_init[] = {
	{0x034c, 0x02},
	{0x034d, 0x80},
	{0x034e, 0x01},
	{0x034f, 0xe0},
	{0x0340, 0x02},
	{0x0341, 0x18},
	{0x0342, 0x02},
	{0x0343, 0xea},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg hawaii_capture_init[] = {
	{0x034c, 0x02},
	{0x034d, 0x80},
	{0x034e, 0x01},
	{0x034f, 0xe0},
	{0x0340, 0x02},
	{0x0341, 0x18},
	{0x0342, 0x02},
	{0x0343, 0xea},
	{0xFFFF, 0xff},
};
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*EFFECT */
static const struct ov7695_reg ov7695_effect_normal_tbl[] = {
	{0x5803, 0x2e},
	{0x5804, 0x20},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_effect_bw_tbl[] = {
	{0x5803, 0x80},
	{0x5804, 0x80},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_effect_sepia_tbl[] = {
	{0x5803, 0x40},
	{0x5804, 0xa0},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_effect_negative_tbl[] = {
	{0xFFFF, 0xff},
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*AntiBanding */
static const struct ov7695_reg ov7695_antibanding_auto_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_antibanding_50z_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_antibanding_60z_tbl[] = {
	{0xFFFF, 0xff},
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*Lens_shading*/

static const struct ov7695_reg ov7695_lens_shading_on_tbl[] = {
	/*@@ Lenc On(C) */
	{0xFFFF, 0xff},
};


static const struct ov7695_reg ov7695_lens_shading_off_tbl[] = {
	{0xFFFF, 0xff},
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/*Contrast */

static const struct ov7695_reg ov7695_contrast_default_lv3_tbl[] = {
	{0x5805, 0x00},
	{0x5806, 0x20},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_contrast_lv1_tbl[] = {
	{0x5805, 0x14},
	{0x5806, 0x14},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_contrast_lv2_tbl[] = {
	{0x5805, 0x1a},
	{0x5806, 0x1a},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_contrast_lv4_tbl[] = {
	{0x5805, 0x14},
	{0x5806, 0x24},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_contrast_lv5_tbl[] = {
	{0x5805, 0x1c},
	{0x5806, 0x2c},
	{0xFFFF, 0xff},
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*sharpness */

static const struct ov7695_reg ov7695_sharpness_default_lv2_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_sharpness_lv0_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_sharpness_lv1_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_sharpness_lv3_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_sharpness_lv4_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_sharpness_lv5_tbl[] = {
	{0xFFFF, 0xff},
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* saturation */

static const struct ov7695_reg ov7695_saturation_default_lv3_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_saturation_lv0_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_saturation_lv1_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_saturation_lv2_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_saturation_lv4_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_saturation_lv5_tbl[] = {
	{0xFFFF, 0xff},
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* brightness */

static const struct ov7695_reg ov7695_brightness_lv0_tbl[] = {
	{0x3a0f, 0x80},
	{0x3a10, 0x70},
	{0x3a11, 0xa0},
	{0x3a1b, 0x70},
	{0x3a1e, 0x70},
	{0x3a1f, 0x30},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_brightness_lv1_tbl[] = {
	{0x3a0f, 0x60},
	{0x3a10, 0x58},
	{0x3a11, 0xa0},
	{0x3a1b, 0x60},
	{0x3a1e, 0x58},
	{0x3a1f, 0x20},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_brightness_lv2_default_tbl[] = {
	{0x3a0f, 0x58},
	{0x3a10, 0x50},
	{0x3a11, 0x91},
	{0x3a1b, 0x58},
	{0x3a1e, 0x50},
	{0x3a1f, 0x20},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_brightness_lv3_tbl[] = {
	{0x3a0f, 0x48},
	{0x3a10, 0x40},
	{0x3a11, 0x80},
	{0x3a1b, 0x48},
	{0x3a1e, 0x40},
	{0x3a1f, 0x20},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_brightness_lv4_tbl[] = {
	{0x3a0f, 0x28},
	{0x3a10, 0x20},
	{0x3a11, 0x51},
	{0x3a1b, 0x28},
	{0x3a1e, 0x20},
	{0x3a1f, 0x10},
	{0xFFFF, 0xff},
};

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Auto Expourse */

static const struct ov7695_reg ov7695_ae_average_tbl[] = {
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_ae_centerweight_tbl[] = {
	{0xFFFF, 0xff},
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*default awb */
static const struct ov7695_reg ov7695_wb_def[] = {
	{0xFFFF, 0xff},
};

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
/* White Balance */
static const struct ov7695_reg ov7695_wb_fluorescent[] = {
	{0x5204, 0x06},
	{0x5205, 0x00},
	{0x5206, 0x04},
	{0x5207, 0xdc},
	{0x5208, 0x08},
	{0x5209, 0xb4},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_wb_daylight[] = {
	{0x5204, 0x05},
	{0x5205, 0x7b},
	{0x5206, 0x04},
	{0x5207, 0x00},
	{0x5208, 0x05},
	{0x5209, 0x15},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_wb_cloudy[] = {
	{0x5204, 0x06},
	{0x5205, 0x00},
	{0x5206, 0x04},
	{0x5207, 0x00},
	{0x5208, 0x04},
	{0x5209, 0x60},
	{0xFFFF, 0xff},
};

static const struct ov7695_reg ov7695_wb_tungsten[] = {
	{0x5204, 0x03},
	{0x5205, 0xa0},
	{0x5206, 0x04},
	{0x5207, 0x00},
	{0x5208, 0x08},
	{0x5209, 0x4e},
	{0xFFFF, 0xff},
};


static const struct ov7695_reg ov7695_fps_30[] = {
	{0xFFFF, 0xff},
};

#endif /* __OV7695_H__ */
