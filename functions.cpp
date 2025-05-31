#include "functions.h"

void importImage(png::image<png::gray_pixel>& img, const std::string& filename) {
    img.read(filename);
}

int get_width(const png::image<png::gray_pixel>& img) {
    return img.get_width();
}

int get_height(const png::image<png::gray_pixel>& img) {
    return img.get_height();
}
