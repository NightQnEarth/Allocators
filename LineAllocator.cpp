#include "LineAllocator.h"

using namespace std;

LineAllocator::LineAllocator()
{
    clearMemoryBlock();
}

LineAllocator::~LineAllocator()
{
    free(memoryBlock);
}

int& LineAllocator::operator[] (const int index)
{
    if (index < 0) throw out_of_range("Negative index is not valid.");

    while (index > capacity)
        enlargeArray();

    if(index >= Length) Length = index + 1;

    return memoryBlock[index];
}

void LineAllocator::push(const int item)
{
    set(item, Length);
}

int LineAllocator::pop()
{
    if (Length-- == 0) throw out_of_range("Array instance is empty.");

    if (capacity - Length > getMemoryBlockCapacity(START_BLOCK_SIZE))
        reduceArray();

    return memoryBlock[Length];
}

int LineAllocator::get(const int index)
{
    return (*this)[index];
}

void LineAllocator::set(const int item, const int index)
{
    while (index > capacity)
        enlargeArray();

    if(index >= Length) Length = index + 1;

    memoryBlock[index] = item;
}

void LineAllocator::removeAll()
{
    if (memoryBlockSize > START_BLOCK_SIZE)
        resizeArray(false, memoryBlockSize - START_BLOCK_SIZE, false);

    clearMemoryBlock();
}