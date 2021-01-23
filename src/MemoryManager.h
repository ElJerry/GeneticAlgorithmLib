#ifndef GENETICALGORITHMLIB_MEMORYMANAGER_H
#define GENETICALGORITHMLIB_MEMORYMANAGER_H

#include <vector>
#include <cstdio>
#include <iostream>
#include <set>
#include <memory>

template <class T>
class MemoryManager
{
private:
    std::vector<std::shared_ptr<T>> instances_;
    std::set<int> freeSlots_;
    int maxMemSize_ = 500;

public:
    MemoryManager(int maxElementSize)
    {
        maxMemSize_ = maxElementSize;
        instances_ = std::vector<std::shared_ptr<T>>(maxMemSize_);

        // fill nextSlot with empty positions
        for (int i = 0; i < maxMemSize_; i++)
        {
            freeSlots_.insert(i);
        }
    }

    MemoryManager() : MemoryManager(500){};

    template <class... ARGS>
    int create(ARGS... args)
    {

        if (freeSlots_.empty())
        {
            return -1;
        }

        // grab an available handle from the set
        int handle = *freeSlots_.begin();
        freeSlots_.erase(handle);

        if (instances_[handle].get() == nullptr)
        {
            instances_[handle].reset(new T(args...));
        }

        return handle;
    }

    void destroy(int handle)
    {
        instances_[handle].reset();

        // add this empty slot to nextSlot queue
        freeSlots_.insert(handle);
    }

    std::shared_ptr<T> get(int handle)
    {
        return instances_[handle];
    }
};

#endif //GENETICALGORITHMLIB_MEMORYMANAGER_H
