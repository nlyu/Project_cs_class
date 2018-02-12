#include <stdlib.h>
#include "gradientColorPicker.h"

/**
 * Constructs a new gradientColorPicker.
 *
 * @param fadeColor1 The first color to start the gradient at.
 * @param fadeColor2 The second color to end the gradient with.
 * @param radius How quickly to transition to fadeColor2.
 * @param centerX X coordinate for the center of the gradient.
 * @param centerY Y coordinate for the center of the gradient.
 */
gradientColorPicker::gradientColorPicker(RGBAPixel fadeColor1_p,
                                         RGBAPixel fadeColor2_p, int radius_p,
                                         int centerX_p, int centerY_p)
{
    /**
     * @todo Construct your gradientColorPicker here! You may find it
     *	helpful to create additional member variables to store things.
     */
    fadeColor1 = fadeColor1_p;
    fadeColor2 = fadeColor2_p;
    radius = radius_p;
    centerX = centerX_p;
    centerY = centerY_p;
}

/**
 * Picks the color for pixel (x, y).
 *
 * The first color fades into the second color as you move from the initial
 * fill point, the center, to the radius. Beyond the radius, all pixels
 * should be just color2.
 *
 * You should calculate the distance between two points using the standard
 * Manhattan distance formula,
 *
 * \f$d = |center\_x - given\_x| + |center\_y - given\_y|\f$
 *
 * Then, scale each of the three channels (R, G, and B) from fadeColor1 to
 * fadeColor2 linearly from d = 0 to d = radius.
 *
 * For example, the red color at distance d where d is less than the radius
 * must be
 *
 * \f$ redFill = fadeColor1.red - \left\lfloor
   \frac{d*fadeColor1.red}{radius}\right\rfloor +
   \left\lfloor\frac{d*fadeColor2.red}{radius}\right\rfloor\f$
 *
 * Note that all values are integers. If you do not follow this formula,
 * your colors may be very close but round differently than ours.
 *
 * @param x The x coordinate to pick a color for.
 * @param y The y coordinate to pick a color for.
 * @return The color selected for (x, y).
 */
RGBAPixel gradientColorPicker::operator()(int x, int y)
{
    RGBAPixel color;
    /**
     * @todo Return the correct color here!
     */
     int d = abs(centerX -x) + abs(centerY - y);
     if (d <= radius){
    	RGBAPixel color(fadeColor1.red-(fadeColor1.red*d)/radius+(fadeColor2.red)*d/radius, fadeColor1.green-(fadeColor1.green*d)/radius+(fadeColor2.green)*d/radius, fadeColor1.blue-(fadeColor1.blue*d)/radius+(fadeColor2.blue*d)/radius);
    	return color;
     }
    return fadeColor2;
}
