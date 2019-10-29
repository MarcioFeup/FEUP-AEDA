cmake_minimum_required(VERSION 3.15)
project(aeda1718_ci1)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aeda1718_ci1 src/main.cpp tests/Test.cpp src/Car.cpp)

target_link_libraries(aeda1718_ci1 gtest gtest_main)