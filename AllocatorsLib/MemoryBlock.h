#ifndef ALLOCATORS_MEMORYBLOCK_H
#define ALLOCATORS_MEMORYBLOCK_H

#include "MemoryBlocksContainer.h"

class MemoryBlock : MemoryBlocksContainer
{
public:
    int* memoryBlock;
    MemoryBlock* previous;

    MemoryBlock();
    ~MemoryBlock() override;

    size_t getMemoryBlockSize() override;
    size_t getMemoryBlockCapacity() override;
};

#endif //ALLOCATORS_MEMORYBLOCK_H
