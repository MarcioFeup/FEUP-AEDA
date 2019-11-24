cmake_minimum_required(VERSION 3.10)
project(aeda1920_fp07)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)



add_executable(aeda1920_fp07 main.cpp test/tests.cpp src/binary_tree/binary_tree.h src/binary_tree/bst.h src/dictionary/dictionary.cpp src/dictionary/dictionary.h src/dictionary/word.cpp src/dictionary/word.h src/game/circle.cpp src/game/circle.h src/game/game.cpp src/game/game.h src/dictionary/non_existing_word.cpp src/dictionary/non_existing_word.h)

target_link_libraries(aeda1920_fp07 gtest gtest_main)
