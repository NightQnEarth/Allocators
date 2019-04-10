#ifndef ALLOCATORS_MEMORYBLOCK_H
#define ALLOCATORS_MEMORYBLOCK_H

#include <iostream>
#include "MemoryBlocksContainer.h"

class MemoryBlock : MemoryBlocksContainer
{
public:
    int* memoryBlock = (int*)malloc(PULL_SIZE);
    MemoryBlock* previous;
    MemoryBlock* next;

    MemoryBlock(MemoryBlock* previous, MemoryBlock* next);
    ~MemoryBlock() override;
};

#endif //ALLOCATORS_MEMORYBLOCK_H
