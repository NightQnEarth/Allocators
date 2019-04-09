#include <iostream>
#include "Array.h"
#include "LineAllocator.h"

using namespace std;

void testAllocator(Array& allocator)
{
    allocator[300000] = 10;
    allocator.push(456);
    cout << "arr.get(arr.Length - 1): " << allocator.get(allocator.Length - 1) << endl;
    allocator.pop();
    allocator.set(789, 3);

    for (int i = 0; i < allocator.Length; ++i)
        cout << allocator[i] << '|';

    cout << endl;

    allocator.removeAll();

    cout << "arr.Length: " << allocator.Length << endl;

    for (int i = 0; i < allocator.Length; ++i)
        cout << allocator[i] << '|';
}

int main()
{
    try
    {
        LineAllocator lineAllocator;
        Array* allocators[] = {&lineAllocator};

        for (auto & allocator : allocators)
            testAllocator(*allocator);
    }
    catch (const exception& exception)
    {
        cout << exception.what();
        return 1;
    }

    return 0;
}