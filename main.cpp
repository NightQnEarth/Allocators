#include <iostream>

using namespace std;

const int START_BLOCK_SIZE = 1024 * 1024;

class Array
{
public:
    int Length = 0;

    Array()
    {
        clearMemoryBlock();
    }

    ~Array()
    {
        free(memoryBlock);
    }

    int& operator[] (const int index)
    {
        if (index < 0) throw out_of_range("Negative index is not valid.");

        while (index > capacity)
            enlargeArray();

        if(index >= Length) Length = index + 1;

        return memoryBlock[index];
    }

    void push(const int item)
    {
        set(item, Length);
    }

    int pop()
    {
        if (Length-- == 0) throw out_of_range("Array instance is empty.");

        if (capacity - Length > getMemoryBlockCapacity(START_BLOCK_SIZE))
            reduceArray();

        return memoryBlock[Length];
    }

    int get(const int index)
    {
        return (*this)[index];
    }

    void set(const int item, const int index)
    {
        while (index > capacity)
            enlargeArray();

        if(index >= Length) Length = index + 1;

        memoryBlock[index] = item;
    }

    void removeAll()
    {
        if (memoryBlockSize > START_BLOCK_SIZE)
            resizeArray(false, memoryBlockSize - START_BLOCK_SIZE, false);

        clearMemoryBlock();
    }

private:
    int* memoryBlock = (int*)malloc(START_BLOCK_SIZE);
    int memoryBlockSize = START_BLOCK_SIZE;
    int capacity = getMemoryBlockCapacity(memoryBlockSize);

    void enlargeArray() { resizeArray(true, START_BLOCK_SIZE); }

    void reduceArray() { resizeArray(false, START_BLOCK_SIZE); }

    void resizeArray(const bool enlarge, const int addingBytesCount, const bool saveValues = true)
    {
        memoryBlockSize += enlarge ? addingBytesCount : -addingBytesCount;
        int* newMemoryBlock = (int*)malloc(memoryBlockSize);

        if (saveValues)
            for (int i = 0; i < Length; ++i)
                newMemoryBlock[i] = memoryBlock[i];

        free(memoryBlock);

        memoryBlock = newMemoryBlock;
        capacity = getMemoryBlockCapacity(memoryBlockSize);
    }

    void clearMemoryBlock()
    {
        for (int i = 0; i < capacity; ++i)
            memoryBlock[i] = 0;

        Length = 0;
    }

    static int getMemoryBlockCapacity(int blockSize)
    {
        return blockSize / sizeof(int);
    }
};

int main()
{
    try
    {
        Array arr;

        arr[300000] = 10;
        arr.push(456);
        cout << "arr.get(arr.Length - 1): " << arr.get(arr.Length - 1) << endl;
        arr.pop();
        arr.set(789, 3);

        for (int i = 0; i < arr.Length; ++i)
            cout << arr[i] << '|';

        cout << endl;

        arr.removeAll();

        cout << "arr.Length: " << arr.Length << endl;

        for (int i = 0; i < arr.Length; ++i)
            cout << arr[i] << '|';

    }
    catch (const exception& exception)
    {
        cout << exception.what();
        return 1;
    }

    return 0;
}