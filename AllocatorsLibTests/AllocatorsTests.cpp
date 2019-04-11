#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "../AllocatorsLib/Allocator.h"
#include "../AllocatorsLib/LinearAllocator.h"
#include "../AllocatorsLib/StackAllocator.h"
#include "../AllocatorsLib/LinkedListAllocator.h"

using testing::Eq;

namespace
{
    class AllocatorDeclaration : public testing::Test
    {
    public:
        LinearAllocator linearAllocator;
        AllocatorDeclaration()
        {
            linearAllocator;
        }
    };
}

TEST_F(AllocatorDeclaration, test_eq)
{
    linearAllocator[5] = 10;
    ASSERT_EQ(6, linearAllocator.getLength());
}

TEST_F(AllocatorDeclaration, test_neq)
{
    ASSERT_ANY_THROW(linearAllocator.get(-5));
}
