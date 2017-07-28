cmake_minimum_required(VERSION 3.8)
project(liqueur)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.64.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${Boost_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp src/slib.h src/slib.cpp)
add_executable(liqueur ${SOURCE_FILES})

target_link_libraries( liqueur ${Boost_LIBRARIES} )

install(TARGETS liqueur DESTINATION bin)