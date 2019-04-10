#ifndef ALLOCATOR_LINEARALLOCATOR_H
#define ALLOCATOR_LINEARALLOCATOR_H

#include "Array.h"
#include <iostream>

class LinearAllocator : public Array
{
public:
    const int START_BLOCK_SIZE = 1024 * 1024;

    LinearAllocator();
    ~LinearAllocator() override;

    int& operator[] (int index) override;
    void push(int item) override;
    int pop() override;
    int get(int index) override;
    void set(int item, int index) override;
    void removeAll() override;

    int getLength() override;

private:
    int* memoryBlock = (int*)malloc(START_BLOCK_SIZE);
    int memoryBlockSize = START_BLOCK_SIZE;
    int length = 0;
    int capacity = getMemoryBlockCapacity(memoryBlockSize);

    void enlargeArray() { resizeArray(true, START_BLOCK_SIZE); }

    void reduceArray() { resizeArray(false, START_BLOCK_SIZE); }

    void resizeArray(const bool enlarge, const int addingBytesCount, const bool saveValues = true)
    {
        memoryBlockSize += enlarge ? addingBytesCount : -addingBytesCount;
        int* newMemoryBlock = (int*)malloc(memoryBlockSize);

        if (saveValues)
            for (int i = 0; i < length; ++i)
                newMemoryBlock[i] = memoryBlock[i];

        free(memoryBlock);

        memoryBlock = newMemoryBlock;
        capacity = getMemoryBlockCapacity(memoryBlockSize);
    }

    void clearMemoryBlock()
    {
        for (int i = 0; i < capacity; ++i)
            memoryBlock[i] = 0;

        length = 0;
    }

    static int getMemoryBlockCapacity(int blockSize)
    {
        return blockSize / sizeof(int);
    }
};

#endif //ALLOCATOR_LINEARALLOCATOR_H