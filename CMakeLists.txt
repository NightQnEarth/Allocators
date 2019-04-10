cmake_minimum_required(VERSION 3.13)
project(Allocators)

set(CMAKE_CXX_STANDARD 17)

add_executable(Allocators main.cpp include/Array.h source/LinearAllocator.cpp include/LinearAllocator.h source/StackAllocator.cpp include/StackAllocator.h source/LinkedListAllocator.cpp include/LinkedListAllocator.h include/MemoryBlocksContainer.h include/Allocator.h source/MemoryBlock.cpp include/MemoryBlock.h)