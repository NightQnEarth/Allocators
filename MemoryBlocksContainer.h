#ifndef ALLOCATORS_MEMORYBLOCKSCONTAINER_H
#define ALLOCATORS_MEMORYBLOCKSCONTAINER_H

class MemoryBlocksContainer
{
public:
    const int PULL_SIZE = 1024 * 1024;

    virtual ~MemoryBlocksContainer() = default;

    virtual int getMemoryBlockSize() = 0;
    virtual int getMemoryBlockCapacity() = 0;
};

#endif //ALLOCATORS_MEMORYBLOCKSCONTAINER_H
