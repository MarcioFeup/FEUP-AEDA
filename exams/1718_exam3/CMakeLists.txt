cmake_minimum_required(VERSION 3.15)
project(1718_exam3)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(1718_exam3 main.cpp src/BST.h src/Expertize.cpp src/Expertize.h src/FEUPConsulting.cpp src/FEUPConsulting.h src/Project.cpp src/Project.h src/Student.cpp src/Student.h test/Test.cpp)

target_link_libraries(1718_exam3 gtest gtest_main)