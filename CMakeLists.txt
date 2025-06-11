cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(ImageFiltersforCNN CXX)
find_package(PNG REQUIRED)
find_package(ZLIB REQUIRED)
add_executable(image_blur_app
    functions.cpp
    gaussianblur.cpp
)
target_include_directories(image_blur_app PRIVATE
    ${PNG_LIBRARIES}
    ${ZLIB_LIBRARIES}
)