cmake_minimum_required(VERSION 3.13)
project(Allocators)

set(CMAKE_CXX_STANDARD 17)

include_directories ("${PROJECT_SOURCE_DIR}/AllocatorsLib")
include_directories ("${PROJECT_SOURCE_DIR}/AllocatorsLibTests")
add_subdirectory (AllocatorsLib)
add_subdirectory(AllocatorsLibTests)

add_executable(Allocators main.cpp)
target_link_libraries (Allocators AllocatorsLib AllocatorsLibTests)
