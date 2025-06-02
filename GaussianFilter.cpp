#include <iostream>
#include <png++/png.hpp>
#include "functions.h"
using namespace std;

int main() {

    string filename;


    cout << "INITIALISING........." << endl;
    cout << "Please Enter the file name for the input image." << endl;
    cout << "Note that the output would be grayscale regardless of the input image. Make sure to upload the image in the following format: imagename.png:::::  ";
    cin >> filename;
    png::image<png::gray_pixel> input;
    importImage(input, filename);

    int width = get_width(input);
    int height = get_height(input);

    cout << "Width and Height: " << width << " x " << height << endl;


    // Apply mean blur
    auto mean_blurred = meanblur(input, 10);
    mean_blurred.write("mean_blur_output.png");

    cout <<"--------------------------------------------------------------"<<endl;
    cout << "Image processed and saved as mean_blur_output.png" << endl;
    cout <<"--------------------------------------------------------------"<<endl;


    // Apply Gaussian blur
    auto gaussian_blurred = gaussianBlur(input, 3, 5);
    gaussian_blurred.write("gaussian_blur.png");

    cout <<"--------------------------------------------------------------"<<endl;
    cout << "Image processed and saved as mean_blur_output.png" << endl;
    cout <<"--------------------------------------------------------------"<<endl;
    return 0;
}
