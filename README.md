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
- Uses CMake for cross-platform build management

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
- `src/`: Directory containing all source code files:
- `functions.h`: Header file containing function declarations for image operations.
- `functions.cpp`: Implements core image processing functions including image import, mean blur, Gaussian kernel generation, and Gaussian blur.
- `GaussianFilter.cpp`: Main driver file, handles user input, loads the image, and applies both filters.
Generated Outputs (will appear in build/ directory after execution):
- `mean_blur_output.png`: Output image after applying the mean filter.
- `gaussian_blur_output.png`: Output image after applying the Gaussian filter.
- `image_blur_app`: The compiled executable program.

---

## Compilation and Execution

### Prerequisites:

- Before you begin, ensure you have the following installed on your system:

- C++ Compiler: (e.g., G++ on Linux, AppleClang on macOS, MSVC on Windows)

- CMake: Version 3.15 or higher.

- Linux (Debian/Ubuntu): sudo apt update && sudo apt install cmake build-essential

- macOS: brew install cmake (if you have Homebrew) or install Xcode Command Line Tools xcode-select --install (which includes CMake and a compiler).

- libpng and zlib development libraries:

- Linux (Debian/Ubuntu): sudo apt install libpng-dev zlib1g-dev

- macOS: These are often provided by Xcode Command Line Tools. If not, brew install libpng zlib.


### Building the Project:

- Follow these steps from your terminal:

- Clone the repository:
- If you haven't already, clone your project from GitHub.

`git clone https://github.com/ShreejalBhattarai/Filters-for-CNN.git # Replace with your actual repo URL`
`cd Filters-for-CNN`

- Create a build directory:
It's best practice to perform an "out-of-source" build to keep your source directory clean.

`mkdir build`
`cd build`

- Configure the project with CMake:
This command will read your CMakeLists.txt (located in the parent directory, ..) and generate the native build files (e.g., Makefiles on Linux/macOS, Visual Studio project files on Windows).

`cmake ..`

You should see messages indicating successful configuration and generation.

- Build the project:
This command triggers the compilation and linking process using the build files generated by CMake.

`cmake --build .`

You will see compilation progress and, if successful, no errors at the end. The executable image_blur_app will be created inside this build directory.

### Running the Program

- Navigate to the build directory (if not already there):

`cd Filters-for-CNN/build`

- Ensure you have an input image:
Place a PNG image named input.png (or any other .png file you wish to use) inside the build directory. Alternatively, you can provide the full path to your image when the program prompts you.

### Execute the program:

`./image_blur_app`

The program will prompt you to enter the input image filename. After processing, it will generate mean_blur_output.png and gaussian_blur_output.png in the same build directory.




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


