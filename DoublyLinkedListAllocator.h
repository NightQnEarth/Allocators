#ifndef ALLOCATORS_DOUBLYLINKEDLISTALLOCATOR_H
#define ALLOCATORS_DOUBLYLINKEDLISTALLOCATOR_H

#include <iostream>
#include "Allocator.h"
#include "MemoryBlock.h"

class DoublyLinkedListAllocator : public Allocator
{
public:
    int getLength() override;
    int& operator[] (int index) override;
    void push(int item) override;
    int pop() override;
    int get(int index) override;
    void set(int item, int index) override;
    void removeAll() override;

    int getMemoryBlockSize() override;
    int getMemoryBlockCapacity() override;

protected:
    int length = 0;
    int memoryBlockCount;
    MemoryBlock* lastMemoryBlock;

    MemoryBlock* getMemoryBlock(const int index)
    {
        int currentBlockNumber = memoryBlockCount;

        while (memoryBlockCount * lastMemoryBlock -> getMemoryBlockCapacity() - 1 < index)
        {
            MemoryBlock newMemoryBlock;
            newMemoryBlock.previous = lastMemoryBlock;
            newMemoryBlock.next = nullptr;
            lastMemoryBlock -> next = &newMemoryBlock;
            lastMemoryBlock = &newMemoryBlock;

            memoryBlockCount++;
        }

        MemoryBlock* memoryBlock = lastMemoryBlock;

        while (memoryBlock -> getMemoryBlockCapacity() * (currentBlockNumber - 1) >= index)
            memoryBlock = memoryBlock -> previous;

        return memoryBlock;
    }

    void deleteLastBlock()
    {
        lastMemoryBlock = lastMemoryBlock -> previous;
        lastMemoryBlock -> next = nullptr;
    }
};

#endif //ALLOCATORS_DOUBLYLINKEDLISTALLOCATOR_H
