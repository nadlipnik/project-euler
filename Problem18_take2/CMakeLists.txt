cmake_minimum_required(VERSION 3.5)

project(Board VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17) #or whatever

# Library
set(LIBRARY BinaryTree.hpp)
add_library(BinaryTree STATIC ${LIBRARY})
set_target_properties(BinaryTree PROPERTIES LINKER_LANGUAGE CXX)

set(LIBRARY BinaryTreeTemplate.hpp)
add_library(BinaryTreeTemplate STATIC ${LIBRARY})
set_target_properties(BinaryTreeTemplate PROPERTIES LINKER_LANGUAGE CXX)

# for debugging
#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/file1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})




# application
add_executable(main.o main.cpp)
target_link_libraries(main.o BinaryTree BinaryTreeTemplate)