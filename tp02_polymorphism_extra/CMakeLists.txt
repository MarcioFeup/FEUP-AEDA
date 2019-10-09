cmake_minimum_required(VERSION 3.10)
project(aeda1920_fp02_extra)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/run")

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aeda1920_fp02_extra src/main.cpp tests/tests.cpp src/vet.cpp src/animal.cpp src/zoo.cpp)

target_link_libraries(aeda1920_fp02_extra gtest gtest_main)

