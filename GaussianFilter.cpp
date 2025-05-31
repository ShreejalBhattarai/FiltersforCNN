#include <iostream>
#include <png++/png.hpp>
#include "functions.h"
using namespace std;

int main() {
    cout << "INITIALISING........." << endl;

    png::image<png::gray_pixel> input;
    importImage(input, "input.png");

    int width = get_width(input);
    int height = get_height(input);

    cout << "Width and Height: " << width << " x " << height << endl;


    // Apply mean blur
    auto blurred = meanblur(input, 3);
    blurred.write("mean_blur_output.png");

    cout << "Image processed and saved as mean_blur_output.png" << endl;
    return 0;
}
