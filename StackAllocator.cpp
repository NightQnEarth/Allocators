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
    if (memoryBlockSize > START_BLOCK_SIZE)
        resizeBlock(false, memoryBlockSize - START_BLOCK_SIZE, false);

    LinearAllocator::removeAll();
}
