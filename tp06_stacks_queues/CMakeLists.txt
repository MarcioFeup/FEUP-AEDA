cmake_minimum_required(VERSION 3.10)
project(aeda1920_fp06)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)



add_executable(aeda1920_fp06 src/main.cpp src/model/desk.cpp src/model/client.cpp src/util/time_manager.cpp src/exception/empty_queue.cpp tests/tests.cpp src/util/stack_ext.h)

target_link_libraries(aeda1920_fp06 gtest gtest_main)
