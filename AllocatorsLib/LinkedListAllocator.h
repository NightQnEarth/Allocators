#ifndef ALLOCATORS_LINKEDLISTALLOCATOR_H
#define ALLOCATORS_LINKEDLISTALLOCATOR_H

#include "Allocator.h"
#include "MemoryBlock.h"

class LinkedListAllocator : public Allocator
{
public:
    ~LinkedListAllocator() override;

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
    size_t length = 0;
    size_t memoryBlockCount = 1;
    MemoryBlock* lastMemoryBlock = new MemoryBlock();

    MemoryBlock* getMemoryBlock(int index);
    void deleteLastBlock();
};

#endif //ALLOCATORS_LINKEDLISTALLOCATOR_H
