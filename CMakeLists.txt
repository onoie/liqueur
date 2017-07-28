cmake_minimum_required(VERSION 3.8)
project(liqueur)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/slib.h src/slib.cpp)
add_executable(liqueur ${SOURCE_FILES})