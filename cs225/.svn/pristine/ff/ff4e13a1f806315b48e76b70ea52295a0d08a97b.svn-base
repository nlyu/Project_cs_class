#include <algorithm>
#include <iostream>

#include "rgbapixel.h"
#include "png.h"

using namespace std;

int main(){
    // Open a new PNG image from the file sample.png.
    PNG image_in("in.png");
    size_t h, w;
    h = image_in.height();
    w = image_in.width();
    PNG image_out(w, h);

    // Blend sample.png and overlay.png together.
        for(size_t row = 0; row < w; ++row ){
                for(size_t col = 0; col < h; ++col){
                        image_out(w-row-1, h-col-1)->red = image_in(row, col)->red;
                        image_out(w-row-1, h-col-1)->green = image_in(row, col)->green;
                        image_out(w-row-1, h-col-1)->blue = image_in(row, col)->blue;
                        image_out(w-row-1, h-col-1)->alpha = image_in(row, col)->alpha;
                }
        }

    image_out.writeToFile("out.png");
    return 0;
	}
