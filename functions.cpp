#include "functions.h"
#include <algorithm>
#include <cmath>
using namespace std;

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
png::image<png::gray_pixel> meanblur(png::image<png::gray_pixel>& input, int kernelsize=3){
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

//Generating a Gaussian Kernel
void generateGaussianKernel(float kernel[5][5], int size, float sigma){
    float sum = 0.0f;
    int offset = size/2;

    for (int i = -offset; i<=offset; i++){
        for (int j = -offset; j<= offset; j++){
            float value = exp(-(i*i + j*j)/2*sigma*sigma);
            kernel[ i + offset ][ j + offset ] = value;
            sum += value;
        }
    }

    for (int y = 0; y < size; ++y)
    for (int x = 0; x < size; ++x)
        kernel[y][x] /= sum;

}


//Now use the generated gaussian kernel to convolve the given 'inputimage'
png::image<png::gray_pixel> gaussianBlur(png::image<png::gray_pixel>& input, int kernelsize, float sigma) {
    int width = get_width(input);
    int height = get_height(input);
    png::image<png::gray_pixel> output(width, height);
    int offset = kernelsize / 2;

    // Step 1: Generate kernel
    float kernel[5][5];
    generateGaussianKernel(kernel, kernelsize, sigma);

    // Step 2: Convolve
    for (int y = offset; y < height - offset; ++y) {
        for (int x = offset; x < width - offset; ++x) {
            float sum = 0.0f;

            for (int ky = -offset; ky <= offset; ++ky) {
                for (int kx = -offset; kx <= offset; ++kx) {
                    sum += input[y + ky][x + kx] * kernel[ky + offset][kx + offset];
                }
            }

            // Clamp value between 0–255
            int value = std::min(255, std::max(0, static_cast<int>(sum)));
            output[y][x] = value;
        }
    }

    return output;
}
