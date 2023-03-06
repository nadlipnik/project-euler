cmake_minimum_required(VERSION 3.5)

project(Board VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) #or whatever

# Library
set(LIBRARY Player.cpp)
add_library(Player STATIC ${LIBRARY})


# for debugging
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# main application
find_package(GTest REQUIRED)
add_executable(main.o main.cpp)
target_link_libraries(main.o Player)

# test application
add_executable(test_hands.o test/player_test.cpp)
target_include_directories(test_hands.o PRIVATE GTEST_INCLUDE_DIRS lib_board)
target_link_libraries(test_hands.o Player GTest::gtest GTest::gtest_main)


add_test(GAME test_hands.o)