#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <png++/png.hpp>
#include <string>


const int KERNEL_SIZE = 3;
const int KERNEL_MATRIX[KERNEL_SIZE][KERNEL_SIZE] = {{1,1,1},{1,1,1},{1,1,1}};


void importImage(png::image<png::gray_pixel>& img, const std::string& filename);
int get_width(const png::image<png::gray_pixel>& img);
int get_height(const png::image<png::gray_pixel>& img);

png::image<png::gray_pixel> meanblur(png::image<png::gray_pixel>& input, int kernelsize);

#endif
