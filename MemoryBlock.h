#ifndef ALLOCATORS_MEMORYBLOCK_H
#define ALLOCATORS_MEMORYBLOCK_H

#include <iostream>
#include "MemoryBlocksContainer.h"

class MemoryBlock : MemoryBlocksContainer
{
public:
    int* memoryBlock = (int*)malloc(getMemoryBlockSize());
    MemoryBlock* previous;
    MemoryBlock* next;

    ~MemoryBlock() override;

    int getMemoryBlockSize() override;
    int getMemoryBlockCapacity() override;
};

#endif //ALLOCATORS_MEMORYBLOCK_H
