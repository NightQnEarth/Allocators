#include <iostream>
#include "MemoryBlock.h"

MemoryBlock::MemoryBlock()
{
    memoryBlock = (int*)malloc(PULL_SIZE);
    previous = nullptr;
}

MemoryBlock::~MemoryBlock()
{
    free(memoryBlock);
}

size_t MemoryBlock::getMemoryBlockSize()
{
    return PULL_SIZE;
}

size_t MemoryBlock::getMemoryBlockCapacity()
{
    return getMemoryBlockSize() / sizeof(int);
}
