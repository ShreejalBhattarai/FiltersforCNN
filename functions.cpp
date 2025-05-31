#include "functions.h"
#include <algorithm>

void importImage(png::image<png::gray_pixel>& img, const std::string& filename) {
    img.read(filename);
}

int get_width(const png::image<png::gray_pixel>& img) {
    return img.get_width();
}

int get_height(const png::image<png::gray_pixel>& img) {
    return img.get_height();
}

//Implementation of mean blur
png::image<png::gray_pixel> meanblur(png::image<png::gray_pixel>& input, int kernelsize){
    int width = get_width(input);
    int height = get_height(input);
    //This initalises empty output image of same size.
    png::image<png::gray_pixel> output(width, height);
    int offset = kernelsize/2;


    for (int y = offset; y < height - offset; ++y) {
        for (int x = offset; x < width - offset; ++x) {
            int sum = 0;

            for (int ky = -offset; ky <= offset; ++ky) {
                for (int kx = -offset; kx <= offset; ++kx) {
                    sum += input[y + ky][x + kx];
                }
            }

            int area = kernelsize * kernelsize;
            output[y][x] = sum / area;
        }
    }
    return output;
}
