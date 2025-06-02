# Image Filtering in C++ Using Mean and Gaussian Blur

This program demonstrates basic image filtering using two methods: **Mean Blur** and **Gaussian Blur**. It takes an input grayscale image in PNG format, applies both filters, and writes two output images to disk: one blurred using the mean filter and the other using the Gaussian filter.

This project is implemented entirely in C++ using the `png++` library for PNG image input/output and standard C++ for computation. The program is terminal-based and designed for educational use, especially to understand how image convolution works.

---

## Features

- Grayscale image processing using C++
- Implementation of Mean Blur (Uniform Kernel)
- Implementation of Gaussian Blur (Weighted Kernel)
- Manual kernel generation and convolution
- Command-line file prompt
- Image output using the same dimensions as the input image

---

## File Descriptions

- `functions.h`: Header file containing function declarations.
- `functions.cpp`: Implements:
    - Image import
    - Mean blur function
    - Gaussian kernel generation
    - Gaussian blur function
- `GaussianFilter.cpp`: Main driver file.
    - Handles user input, loads the image, and applies both filters.
- `input.png`: Sample input image (user must provide).
- `mean_blur_output.png`: Output after applying the mean filter.
- `gaussian_blur_output.png`: Output after applying the Gaussian filter.

---

## Compilation and Execution

### Step 1: Make sure libpng++ is installed

On Ubuntu/Debian:
```bash
sudo apt update
sudo apt install libpng-dev
```

### Step 2: Compile the project
```bash
g++ functions.cpp GaussianFilter.cpp -lpng -o blurfilter
```

### Step 3: Run the program
``` bash
./blurfilter
```



Code Explanation
1. Image Import and Access

``` bash
void importImage(png::image<png::gray_pixel>& img, const std::string& filename) {
    img.read(filename);
}
```

  Loads a PNG image from disk into a png::image<png::gray_pixel> object.
  The image is assumed to be grayscale.

2. Mean Blur

``` bash png::image<png::gray_pixel> meanblur(png::image<png::gray_pixel>& input, int kernelsize = 3);```

  Applies a uniform blur.
  For every pixel in the image, it calculates the average of all pixels in the kernel-sized square around it and assigns that average value to the output pixel.
  Example: In a 3x3 kernel, the output pixel is the average of 9 pixels.
  Avoids image borders to prevent accessing out-of-bound pixels.

3. Generating the Gaussian Kernel

``` bash void generateGaussianKernel(float kernel[5][5], int size, float sigma);```

  Manually generates a 2D Gaussian kernel based on the formula: $G(x, y) = \exp(-(x^2 + y^2) / (2*\sigma^2))$
  The kernel is normalized so that the sum of all weights is 1.
  This avoids brightness changes in the output.

4. Gaussian Blur

``` bash png::image<png::gray_pixel> gaussianBlur(png::image<png::gray_pixel>& input, int kernelsize = 5, float sigma = 1.0f);```

  Performs convolution of the input image with the Gaussian kernel.
  Multiplies each pixel in the kernel area with the corresponding kernel weight.
  The sum of weighted values is used for the output pixel.
  Like Mean Blur, avoids borders.

5. Main Program Flow

``` bash 
int main() {
    // Prompt user for input filename
    // Load image
    // Display width and height
    // Apply meanblur, write result
    // Apply gaussianBlur, write result
}
```

  Prompts the user for an image filename.
  Loads and prints image dimensions.
  Applies both filters sequentially.
  Saves results to two output files.


