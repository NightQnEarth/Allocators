cmake_minimum_required(VERSION 3.13)
project(Allocators)

set(CMAKE_CXX_STANDARD 17)

add_executable(Allocators main.cpp Array.h LinearAllocator.cpp LinearAllocator.h StackAllocator.cpp StackAllocator.h DoubleLinkedListAllocator.cpp DoubleLinkedListAllocator.h MemoryBlocksContainer.h Allocator.h)