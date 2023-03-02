cmake_minimum_required(VERSION 3.5)

project(Board VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) #or whatever

# Library
#set(LIBRARY BinaryTree.cpp)
#add_library(BinaryTree STATIC ${LIBRARY})


# for debugging
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# application
add_executable(main.o main.cpp)