# Minimum CMake version required
# Using a relatively recent version ensures access to modern CMake features.
cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

# Define the project name and enable C++ language support
project(ImageFiltersForCNN LANGUAGES CXX)

# Find the required external libraries: PNG and ZLIB.
# REQUIRED means CMake will stop if these packages are not found.
find_package(PNG REQUIRED)
find_package(ZLIB REQUIRED)

# Add the executable target for your application.
add_executable(image_blur_app
    functions.cpp
    GaussianFilter.cpp
)

# Specify include directories.
# This tells the compiler where to look for header files.
target_include_directories(image_blur_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR} # For functions.h
    ${PNG_INCLUDE_DIRS}         # For png++/png.hpp and libpng C headers
)

target_link_libraries(image_blur_app PRIVATE
    png    # Link against libpng
    z      # Link against libz (zlib)
)

# Optional: Set C++ standard.
set_property(TARGET image_blur_app PROPERTY CXX_STANDARD 11)
set_property(TARGET image_blur_app PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET image_blur_app PROPERTY CXX_EXTENSIONS OFF) # Use strict C++ standard
