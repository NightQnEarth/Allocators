cmake_minimum_required(VERSION 3.13)
project(Allocators)

set(CMAKE_CXX_STANDARD 17)

add_executable(Allocators main.cpp Array.h LineAllocator.cpp LineAllocator.h)