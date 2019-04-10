#ifndef ALLOCATORS_DOUBLYLINKEDLISTALLOCATOR_H
#define ALLOCATORS_DOUBLYLINKEDLISTALLOCATOR_H

#include "Allocator.h"

class DoublyLinkedListAllocator : public Allocator
{
public:
    ~DoublyLinkedListAllocator() override;

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

};

#endif //ALLOCATORS_DOUBLYLINKEDLISTALLOCATOR_H
