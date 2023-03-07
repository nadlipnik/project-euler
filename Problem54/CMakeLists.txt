cmake_minimum_required(VERSION 3.5)

project(Board VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) #or whatever

# Library
set(LIBRARY Player.cpp)
add_library(Player STATIC ${LIBRARY})
#target_include_directories(Player PRIVATE .)

set(LIBRARY main.cpp)
add_library(Main STATIC ${LIBRARY})
#target_include_directories(Main PRIVATE .)


# for debugging
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# main application
find_package(GTest REQUIRED)
#add_executable(main.o main.cpp)
#target_link_libraries(main.o Player)

# test application
include_directories("${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/test")
add_executable(player_test.o test/player_test.cpp)
target_include_directories(player_test.o PRIVATE GTEST_INCLUDE_DIRS Player Main)
target_link_libraries(player_test.o Main Player GTest::gtest GTest::gtest_main)


add_test(GAME player_test.o)