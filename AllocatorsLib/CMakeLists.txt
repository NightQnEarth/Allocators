project(AllocatorsLib)

set(HEADER_FILES
        Array.h
        LinearAllocator.h
        StackAllocator.h
        LinkedListAllocator.h
        MemoryBlocksContainer.h
        Allocator.h
        MemoryBlock.h)

set(SOURCE_FILES
        LinearAllocator.cpp
        StackAllocator.cpp
        LinkedListAllocator.cpp
        MemoryBlock.cpp
        )

add_library(AllocatorsLib STATIC ${SOURCE_FILES} ${HEADER_FILES})
