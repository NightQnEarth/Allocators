#ifndef ALLOCATOR_ARRAY_H
#define ALLOCATOR_ARRAY_H

class Array
{
public:
    int Length = 0;

    virtual ~Array() = default;

    virtual int& operator[] (int index) = 0;
    virtual void push(int item) = 0;
    virtual int pop() = 0;
    virtual int get(int index) = 0;
    virtual void set(int item, int index) = 0;
    virtual void removeAll() = 0;
};

#endif // ALLOCATOR_ARRAY_H