cmake_minimum_required(VERSION 3.15)
project(1617_exam3)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(1617_exam3 main.cpp src/Book.cpp src/Book.h src/BST.h src/ReadingClub.cpp src/ReadingClub.h src/User.cpp src/User.h test/Test.cpp)

target_link_libraries(1617_exam3 gtest gtest_main)