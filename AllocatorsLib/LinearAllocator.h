#ifndef ALLOCATOR_LINEARALLOCATOR_H
#define ALLOCATOR_LINEARALLOCATOR_H

#include "Allocator.h"

class LinearAllocator : public Allocator
{
public:
    LinearAllocator();
    ~LinearAllocator() override;

    size_t getLength() override;
    int& operator[] (int index) override;
    void push(int item) override;
    int pop() override;
    int get(int index) override;
    void set(int item, int index) override;
    void removeAll() override;

    size_t getMemoryBlockSize() override;
    size_t getMemoryBlockCapacity() override;

protected:
    int* memoryBlock;
    size_t memoryBlockSize;
    size_t length;
    size_t capacity;

    void enlargeBlock();
    void resizeBlock(bool enlarge, size_t addingBytesCount, bool saveValues = true);
};

#endif //ALLOCATOR_LINEARALLOCATOR_H
