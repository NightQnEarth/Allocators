#include "StackAllocator.h"

StackAllocator::StackAllocator()
{

}

StackAllocator::~StackAllocator()
{

}

int& StackAllocator::operator[](int index)
{
    return index;
}

void StackAllocator::push(int item)
{

}

int StackAllocator::pop()
{
    return 0;
}

int StackAllocator::get(int index)
{
    return 0;
}

void StackAllocator::set(int item, int index)
{

}

void StackAllocator::removeAll()
{

}

int StackAllocator::getLength()
{
    return length;
}