#ifndef ALLOCATORS_STACKALLOCATOR_H
#define ALLOCATORS_STACKALLOCATOR_H

#include <iostream>
#include "LinearAllocator.h"

class StackAllocator : public LinearAllocator
{
public:
    int pop() override;
    void removeAll() override;

protected:
    void reduceBlock() { resizeBlock(false, START_BLOCK_SIZE); }
};

#endif //ALLOCATORS_STACKALLOCATOR_H
