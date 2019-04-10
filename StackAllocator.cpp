#include "StackAllocator.h"

int StackAllocator::pop()
{
    int poppedItem = LinearAllocator::pop();

    if (capacity - length > getMemoryBlockCapacity())
        reduceBlock();

    return poppedItem;
}

void StackAllocator::removeAll()
{
    if (memoryBlockSize > PULL_SIZE)
        resizeBlock(false, memoryBlockSize - PULL_SIZE, false);

    LinearAllocator::removeAll();
}
