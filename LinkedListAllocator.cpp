#include <iostream>
#include "LinkedListAllocator.h"

using namespace std;

int LinkedListAllocator::getLength()
{
    return length;
}

int& LinkedListAllocator::operator[](const int index)
{
    if (index < 0) throw out_of_range("Negative index is not valid.");
    if(index >= length) length = index + 1;

    MemoryBlock* memoryBlockWithSpecifiedIndex = getMemoryBlock(index);
    const int modOfCapacity = index % memoryBlockWithSpecifiedIndex -> getMemoryBlockCapacity();

    return memoryBlockWithSpecifiedIndex -> memoryBlock[modOfCapacity];
}

void LinkedListAllocator::push(const int item)
{
    set(item, length);
}

int LinkedListAllocator::pop()
{
    if (length-- == 0) throw out_of_range("Array instance is empty.");

    int poppedItem = (*this)[length];
    length--;

    if (memoryBlockCount > 1 && getMemoryBlockCapacity() - length >= PULL_SIZE / sizeof(int))
        deleteLastBlock();

    return poppedItem;
}

int LinkedListAllocator::get(const int index)
{
    return (*this)[index];
}

void LinkedListAllocator::set(const int item, const int index)
{
    (*this)[index] = item;
}

void LinkedListAllocator::removeAll()
{
    while (memoryBlockCount > 1 && getMemoryBlockCapacity() - length >= PULL_SIZE / sizeof(int))
        deleteLastBlock();

    length = 0;
}

int LinkedListAllocator::getMemoryBlockSize()
{
    return getMemoryBlockCapacity() * sizeof(int);
}

int LinkedListAllocator::getMemoryBlockCapacity()
{
    return memoryBlockCount * lastMemoryBlock -> getMemoryBlockCapacity();
}