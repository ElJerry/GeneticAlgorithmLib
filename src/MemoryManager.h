#ifndef GENETICALGORITHMLIB_MEMORYMANAGER_H
#define GENETICALGORITHMLIB_MEMORYMANAGER_H

#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
#include <memory>

#define MAX_MEM_SIZE 500

template <class T>
class MemoryManager
{
private:
    std::vector<std::shared_ptr<T>> instances_;
    std::queue<int> nextSlot_;

public:
    MemoryManager()
    {
        instances_ = std::vector<std::shared_ptr<T>>(MAX_MEM_SIZE);

        // fill nextSlot with empty positions
        for (int i = 0; i < MAX_MEM_SIZE; i++)
        {
            nextSlot_.push(i);
        }
    };

    template <class... ARGS>
    int create(ARGS... args)
    {

        if (nextSlot_.empty())
        {
            return -1;
        }

        int handle = nextSlot_.front();
        nextSlot_.pop();

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
        nextSlot_.push(handle);
    }

    std::shared_ptr<T> get(int handle)
    {
        return instances_[handle];
    }
};

#endif //GENETICALGORITHMLIB_MEMORYMANAGER_H
