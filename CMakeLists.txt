cmake_minimum_required(VERSION 3.13)
project(Allocators)

set(CMAKE_CXX_STANDARD 17)

include_directories ("${PROJECT_SOURCE_DIR}/AllocatorsLib")
include_directories ("${PROJECT_SOURCE_DIR}/AllocatorsLibTests")
include_directories(AllocatorsLibTests/lib/googletest-release-1.8.1/googletest/include)
include_directories(AllocatorsLibTests/lib/googletest-release-1.8.1/googlemock/include)

add_subdirectory (AllocatorsLib)
add_subdirectory(AllocatorsLibTests)

add_executable(Allocators main.cpp AllocatorsLibTests/AllocatorsTests.cpp)
target_link_libraries (Allocators AllocatorsLib AllocatorsLibTests)
