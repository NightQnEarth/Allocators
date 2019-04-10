#include "MemoryBlock.h"

MemoryBlock::MemoryBlock(MemoryBlock* previous, MemoryBlock* next)
{
    this -> previous = previous;
    this -> next = next;
}

MemoryBlock::~MemoryBlock()
{
    free(memoryBlock);
}
