#ifndef ALLOCATOR_LINEARALLOCATOR_H
#define ALLOCATOR_LINEARALLOCATOR_H

#include "Array.h"
#include <iostream>

class LinearAllocator : public Array
{
public:
    const int START_BLOCK_SIZE = 1024 * 1024;

    ~LinearAllocator() override;

    int& operator[] (int index) override;
    void push(int item) override;
    int pop() override;
    int get(int index) override;
    void set(int item, int index) override;
    void removeAll() override;

    int getLength() override;
    int getMemoryBlockSize() override;
    int getMemoryBlockCapacity() override;

protected:
    int* memoryBlock = (int*)malloc(START_BLOCK_SIZE);
    int memoryBlockSize = START_BLOCK_SIZE;
    int length = 0;
    int capacity = getMemoryBlockCapacity();

    void enlargeBlock() { resizeBlock(true, START_BLOCK_SIZE); }

    void resizeBlock(const bool enlarge, const int addingBytesCount, const bool saveValues = true)
    {
        memoryBlockSize += enlarge ? addingBytesCount : -addingBytesCount;
        int* newMemoryBlock = (int*)malloc(memoryBlockSize);

        if (saveValues)
            for (int i = 0; i < length; ++i)
                newMemoryBlock[i] = memoryBlock[i];

        free(memoryBlock);

        memoryBlock = newMemoryBlock;
        capacity = getMemoryBlockCapacity();
    }
};

#endif //ALLOCATOR_LINEARALLOCATOR_H