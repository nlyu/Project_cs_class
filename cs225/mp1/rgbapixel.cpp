#include "rgbapixel.h"

RGBAPixel::RGBAPixel()
{
	red = 255;
	green = 255;
	blue = 255;
	alpha = 255;
}

RGBAPixel::RGBAPixel(uint8_t red_i, uint8_t green_i, uint8_t blue_i)
{
	red = red_i;
	green = green_i;
	blue = blue_i;
	alpha = 255;
}
	
