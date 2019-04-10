#include <iostream>
#include "Allocator.h"
#include "LinearAllocator.h"
#include "StackAllocator.h"

using namespace std;

void testAllocator(Allocator& allocator)
{
    cout << "arr.getMemoryBlockSize(): " << allocator.getMemoryBlockSize() << endl;
    cout << "arr.getMemoryBlockCapacity(): " << allocator.getMemoryBlockCapacity() << endl;
    cout << endl;

    allocator[allocator.getMemoryBlockCapacity()] = 10;
    cout << "allocator[allocator.getMemoryBlockCapacity()] = 10;" << endl;
    cout << "arr.getMemoryBlockSize(): " << allocator.getMemoryBlockSize() << endl;
    cout << "arr.getMemoryBlockCapacity(): " << allocator.getMemoryBlockCapacity() << endl;

    cout << endl;
    allocator.push(456);
    cout << "allocator.push(456);" << endl;
    cout << "arr.getMemoryBlockSize(): " << allocator.getMemoryBlockSize() << endl;
    cout << "arr.getMemoryBlockCapacity(): " << allocator.getMemoryBlockCapacity() << endl;
    cout << "arr.getLength(): " << allocator.getLength() << endl;
    cout << "arr.get(Length - 1): " << allocator.get(allocator.getLength() - 1) << endl;
    cout << "arr.get(Length - 1): " << allocator.get(allocator.getLength() - 2) << endl;

    cout << endl;
    allocator.pop();
    cout << "allocator.pop();" << endl;
    cout << "arr.get(Length - 1): " << allocator.get(allocator.getLength() - 2) << endl;
    cout << "arr.getMemoryBlockSize(): " << allocator.getMemoryBlockSize() << endl;
    cout << "arr.getMemoryBlockCapacity(): " << allocator.getMemoryBlockCapacity() << endl;

    cout << endl;
    allocator.set(789, 3);
    cout << "allocator.set(789, 3);" << endl;

    for (int i = 0; i < 100; ++i)
        cout << allocator[i] << ' ';

    cout << endl << endl;

    allocator.removeAll();
    cout << "allocator.removeAll();" << endl;

    cout << endl;

    cout << "Length: " << allocator.getLength() << endl;
    cout << "arr.getMemoryBlockSize(): " << allocator.getMemoryBlockSize() << endl;
    cout << "arr.getMemoryBlockCapacity(): " << allocator.getMemoryBlockCapacity() << endl;
}

int main()
{
    try
    {
        LinearAllocator lineAllocator;
        StackAllocator stackAllocator;

        Allocator* allocators[] = {&lineAllocator, &stackAllocator};

        for (auto & allocator : allocators)
        {
            testAllocator(*allocator);

            cout << endl << "--------------------------------------" << endl;
        }
    }
    catch (const exception& exception)
    {
        cout << exception.what();
        return 1;
    }

    return 0;
}
