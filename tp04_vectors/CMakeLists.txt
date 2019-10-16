cmake_minimum_required(VERSION 3.10)
project(aeda1920_fp04)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


add_executable(aeda1920_fp04 src/main.cpp tests/tests.cpp src/model/parking_lot.cpp src/model/client.cpp src/model/client.h src/utils/utils.h src/exception/non_existent_client.cpp src/exception/non_existent_client.h src/exception/non_existent_position.cpp src/exception/non_existent_position.h)

target_link_libraries(aeda1920_fp04 gtest gtest_main)
