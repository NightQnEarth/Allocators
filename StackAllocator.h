#ifndef ALLOCATORS_STACKALLOCATOR_H
#define ALLOCATORS_STACKALLOCATOR_H

#include "Array.h"
#include <iostream>

class StackAllocator : public Array
{
public:
    StackAllocator();
    ~StackAllocator() override;

    int& operator[] (int index)  override;
    void push(int item)  override;
    int pop()  override;
    int get(int index)  override;
    void set(int item, int index)  override;
    void removeAll() override;

    int getLength() override;

private:
    int length = 0;
};


#endif //ALLOCATORS_STACKALLOCATOR_H
