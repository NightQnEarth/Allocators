#include <iostream>
#include "DoublyLinkedListAllocator.h"

using namespace std;

int DoublyLinkedListAllocator::getLength()
{
    return length;
}

int& DoublyLinkedListAllocator::operator[](const int index)
{
    if (index < 0) throw out_of_range("Negative index is not valid.");
    if(index >= length) length = index + 1;

    MemoryBlock* memoryBlockWithSpecifiedIndex = getMemoryBlock(index);
    const int modOfCapacity = index % memoryBlockWithSpecifiedIndex -> getMemoryBlockCapacity();

    return memoryBlockWithSpecifiedIndex -> memoryBlock[modOfCapacity];
}

void DoublyLinkedListAllocator::push(const int item)
{
    set(item, length);
}

int DoublyLinkedListAllocator::pop()
{
    if (length-- == 0) throw out_of_range("Array instance is empty.");

    if (memoryBlockCount > 1 && getMemoryBlockCapacity() - length >= PULL_SIZE / sizeof(int))
        deleteLastBlock();

    return (*this)[length];
}

int DoublyLinkedListAllocator::get(const int index)
{
    return (*this)[index];
}

void DoublyLinkedListAllocator::set(const int item, const int index)
{
    (*this)[index] = item;
}

void DoublyLinkedListAllocator::removeAll()
{
    while (memoryBlockCount > 1 && getMemoryBlockCapacity() - length >= PULL_SIZE / sizeof(int))
        deleteLastBlock();

    length = 0;
}

int DoublyLinkedListAllocator::getMemoryBlockSize()
{
    return getMemoryBlockCapacity() * sizeof(int);
}

int DoublyLinkedListAllocator::getMemoryBlockCapacity()
{
    return memoryBlockCount * lastMemoryBlock -> getMemoryBlockCapacity();
}
