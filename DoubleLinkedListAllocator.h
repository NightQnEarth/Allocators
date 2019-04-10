#ifndef ALLOCATORS_DOUBLELINKEDLISTALLOCATOR_H
#define ALLOCATORS_DOUBLELINKEDLISTALLOCATOR_H

#include "Allocator.h"

class DoubleLinkedListAllocator : public Allocator
{
public:
    ~DoubleLinkedListAllocator() override;

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

#endif //ALLOCATORS_DOUBLELINKEDLISTALLOCATOR_H
