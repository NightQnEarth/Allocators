#ifndef ALLOCATORS_MEMORYBLOCKSCONTAINER_H
#define ALLOCATORS_MEMORYBLOCKSCONTAINER_H

#include <cstddef>

class MemoryBlocksContainer
{
public:
    const size_t PULL_SIZE = 1024;

    MemoryBlocksContainer() = default;
    virtual ~MemoryBlocksContainer() = default;
    MemoryBlocksContainer(const MemoryBlocksContainer&) = delete;
    MemoryBlocksContainer& operator= (const MemoryBlocksContainer&) = delete;

    virtual size_t getMemoryBlockSize() = 0;
    virtual size_t getMemoryBlockCapacity() = 0;
};

#endif //ALLOCATORS_MEMORYBLOCKSCONTAINER_H
