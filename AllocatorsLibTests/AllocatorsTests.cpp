#include "gtest/gtest.h"
#include "../AllocatorsLib/StackAllocator.h"
#include "../AllocatorsLib/LinkedListAllocator.h"

namespace
{
    class Allocators : public testing::Test
    {
    public:
        LinearAllocator linearAllocator;
        StackAllocator stackAllocator;
        LinkedListAllocator linkedListAllocator;
    };
}

TEST_F(Allocators, throw_on_negative_index)
{
    Allocator* allocators[] = {&linearAllocator, &stackAllocator, &linkedListAllocator};

    for (auto allocator : allocators)
        ASSERT_THROW(allocator -> get(-1), std::out_of_range);
}

TEST_F(Allocators, correct_push_pop_item)
{
    Allocator* allocators[] = {&linearAllocator, &stackAllocator, &linkedListAllocator};

    for (auto & allocator : allocators)
    {
        ASSERT_NO_THROW(allocator->push(5));
        ASSERT_EQ(allocator->pop(), 5);
    }
}

TEST_F(Allocators, not_throw_when_index_more_than_length)
{
    Allocator* allocators[] = {&linearAllocator, &stackAllocator, &linkedListAllocator};

    for (auto & allocator : allocators)
    {
        ASSERT_EQ(allocator->getLength(), 0);
        ASSERT_NO_THROW((*allocator)[0]);
        ASSERT_EQ(allocator->getLength(), 1);
    }
}

TEST_F(Allocators, throw_on_pop_when_allocator_is_empty)
{
    Allocator* allocators[] = {&linearAllocator, &stackAllocator, &linkedListAllocator};

    for (auto & allocator : allocators)
    {
        ASSERT_EQ(allocator->getLength(), 0);
        ASSERT_THROW(allocator->pop(), std::out_of_range);
    }
}

TEST_F(Allocators, start_size_equal_pullsize)
{
    Allocator* allocators[] = {&linearAllocator, &stackAllocator, &linkedListAllocator};

    for (auto & allocator : allocators)
        ASSERT_EQ(allocator->getMemoryBlockSize(), allocator->PULL_SIZE);
}

TEST_F(Allocators, correct_start_capacity)
{
    Allocator* allocators[] = {&linearAllocator, &stackAllocator, &linkedListAllocator};

    for (auto & allocator : allocators)
        ASSERT_EQ(allocator->getMemoryBlockCapacity(), allocator->PULL_SIZE / sizeof(int));
}

TEST_F(Allocators, start_length_is_zero)
{
    Allocator* allocators[] = {&linearAllocator, &stackAllocator, &linkedListAllocator};

    for (auto & allocator : allocators)
        ASSERT_EQ(allocator->getLength(), 0);
}

TEST_F(Allocators, correct_enlarge_memory_block)
{
    Allocator* allocators[] = {&linearAllocator, &stackAllocator, &linkedListAllocator};

    for (auto & allocator : allocators)
    {
        size_t startCapacity = allocator->getMemoryBlockCapacity();

        ASSERT_NO_THROW((*allocator)[startCapacity] = 100);
        ASSERT_EQ(allocator->get(startCapacity), 100);

        ASSERT_EQ(allocator->getMemoryBlockCapacity(), 2 * startCapacity);
        ASSERT_EQ(allocator->getLength(), startCapacity + 1);
        ASSERT_EQ(allocator->getMemoryBlockSize(), 2 * allocator->PULL_SIZE);
    }
}

TEST_F(Allocators, correct_reduce_memory_block) // For StackAllocator and LinkedListAllocator
{
    Allocator* allocators[] = {&stackAllocator, &linkedListAllocator};

    for (auto & allocator : allocators)
    {
        size_t startCapacity = allocator->getMemoryBlockCapacity();
        allocator->set(100, startCapacity);
        allocator->pop();

        ASSERT_EQ(allocator->getMemoryBlockCapacity(), startCapacity);
        ASSERT_EQ(allocator->getMemoryBlockSize(), allocator->PULL_SIZE);
        ASSERT_EQ(allocator->getLength(), startCapacity);
    }
}

TEST_F(Allocators, not_reduce_memory_block_for_linear_allocator)
{
    Allocator* allocators[] = {&linearAllocator};

    for (auto & allocator : allocators)
    {
        size_t startCapacity = allocator->getMemoryBlockCapacity();
        allocator->set(100, startCapacity);
        allocator->pop();

        ASSERT_EQ(allocator->getMemoryBlockCapacity(), 2 * startCapacity);
        ASSERT_EQ(allocator->getLength(), startCapacity);
        ASSERT_EQ(allocator->getMemoryBlockSize(), 2 * allocator->PULL_SIZE);
    }
}

TEST_F(Allocators, length_not_reduce)
{
    Allocator* allocators[] = {&linearAllocator, &stackAllocator, &linkedListAllocator};

    for (auto & allocator : allocators)
    {
        size_t startCapacity = allocator->getMemoryBlockCapacity();
        ASSERT_EQ(allocator->getLength(), 0);

        allocator->set(100, startCapacity);
        ASSERT_EQ(allocator->getLength(), startCapacity + 1);

        allocator->pop();
        ASSERT_EQ(allocator->getLength(), startCapacity);
    }
}
