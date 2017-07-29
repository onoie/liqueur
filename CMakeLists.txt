
message(STATUS "LiqueurCMake")

cmake_minimum_required(VERSION 3.8)

project(liqueur)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")

find_package(PkgConfig REQUIRED)
find_package(Boost 1.64.0 REQUIRED)
find_package(Boost COMPONENTS program_options REQUIRED)

pkg_check_modules(SQLITE3 REQUIRED sqlite3)
#-D
#add_definitions(-DFOO -DBAR=xyz)

#-I
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${Boost_INCLUDE_DIRS})

#include_directories(/usr/include/)

#-L
#link_directories(/usr/lib64/)

set(SOURCE_FILES src/main.cpp src/slib.h src/slib.cpp src/bmp.h src/sl3.h)
add_executable(
    liqueur
    ${SOURCE_FILES}
)

#-l
target_link_libraries( liqueur ${Boost_LIBRARIES} ${SQLITE3_LIBRARIES})

install(TARGETS liqueur DESTINATION bin)