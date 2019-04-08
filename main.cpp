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
        if (index < 0 || index >= Length)
            throw out_of_range("Index out of array range.");

        return memoryBlock[index];
    }

    void push(int item)
    {
        set(item, Length);
    }

    int pop()
    {
        if (Length-- == 0) throw out_of_range("Array instance is empty.");

        if (memoryBlockSize - Length > START_BLOCK_SIZE)
            reduceArray();

        return memoryBlock[Length];
    }

    int get(int index)
    {
        if (index < 0 || index >= Length)
            throw out_of_range("Index out of array range.");

        return memoryBlock[index];
    }

    void set(int item, int index)
    {
        if (index > memoryBlockSize) enlargeArray();
        if(index >= Length) Length = index + 1;

        memoryBlock[index] = item;
    }

    void removeAll()
    {
        if (memoryBlockSize > START_BLOCK_SIZE)
            resizeArray(false, memoryBlockSize - START_BLOCK_SIZE);

        clearMemoryBlock();
    }

private:
    int* memoryBlock = (int*)malloc(START_BLOCK_SIZE);
    int memoryBlockSize = START_BLOCK_SIZE;

    void enlargeArray() { resizeArray(true, START_BLOCK_SIZE); }

    void reduceArray() { resizeArray(false, START_BLOCK_SIZE); }

    void resizeArray(bool enlarge, int bytesCount)
    {
        memoryBlockSize += enlarge ? bytesCount : -bytesCount;
        int* newMemoryBlock = (int*)malloc(memoryBlockSize);

        for (int i = 0; i < Length; ++i)
            newMemoryBlock[i] = memoryBlock[i];

        free(memoryBlock);

        memoryBlock = newMemoryBlock;
    }

    void clearMemoryBlock()
    {
        for (int i = 0; i < memoryBlockSize; ++i)
            memoryBlock[i] = 0;

        Length = 0;
    }
};

int main()
{
    Array arr;

    cout << "sizeof(arr): " << sizeof(arr) << endl;

    arr[5] = 10;
    arr.push(-3);
    arr.pop();
    arr.get(0);
    arr.set(1, 3);

    for (int i = 0; i < arr.Length; ++i)
    {
        cout << arr[i] << ' ';
    }

    arr.removeAll();

    for (int i = 0; i < arr.Length; ++i)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}