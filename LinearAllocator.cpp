#include "LinearAllocator.h"

using namespace std;

LinearAllocator::LinearAllocator()
{
    clearMemoryBlock();
}

LinearAllocator::~LinearAllocator()
{
    free(memoryBlock);
}

int& LinearAllocator::operator[] (const int index)
{
    if (index < 0) throw out_of_range("Negative index is not valid.");

    while (index > capacity)
        enlargeArray();

    if(index >= length) length = index + 1;

    return memoryBlock[index];
}

void LinearAllocator::push(const int item)
{
    set(item, length);
}

int LinearAllocator::pop()
{
    if (length-- == 0) throw out_of_range("Array instance is empty.");

    if (capacity - length > getMemoryBlockCapacity(START_BLOCK_SIZE))
        reduceArray();

    return memoryBlock[length];
}

int LinearAllocator::get(const int index)
{
    return (*this)[index];
}

void LinearAllocator::set(const int item, const int index)
{
    while (index > capacity)
        enlargeArray();

    if(index >= length) length = index + 1;

    memoryBlock[index] = item;
}

void LinearAllocator::removeAll()
{
    if (memoryBlockSize > START_BLOCK_SIZE)
        resizeArray(false, memoryBlockSize - START_BLOCK_SIZE, false);

    clearMemoryBlock();
}

int LinearAllocator::getLength()
{
    return length;
}