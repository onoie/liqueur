
message(STATUS "LiqueurCMake")

cmake_minimum_required(VERSION 3.8)

project(liqueur)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

#find_package(Boost 1.64.0)
#-D
#add_definitions(-DFOO -DBAR=xyz)
#-I
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#include_directories(${CMAKE_CURRENT_BINARY_DIR})
#include_directories(${Boost_INCLUDE_DIRS})
#include_directories(/usr/include/)
#-L
#link_directories(/usr/lib64/)

set(SOURCE_FILES src/main.cpp src/slib.h src/slib.cpp src/bmp.h src/sl3.h)
add_executable(
    liqueur
    ${SOURCE_FILES}
)

#-l
target_link_libraries( liqueur ${Boost_LIBRARIES} sqlite3)

install(TARGETS liqueur DESTINATION bin)