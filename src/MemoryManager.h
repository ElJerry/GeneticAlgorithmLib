#ifndef GENETICALGORITHMLIB_MEMORYMANAGER_H
#define GENETICALGORITHMLIB_MEMORYMANAGER_H

#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
#include <memory>

#define MAX_MEM_SIZE 500

template <class T>
class MemoryManager {
private:
    std::vector<std::shared_ptr<T>> instances;
    std::queue<int> nextSlot;

public:
    MemoryManager() {
        instances = std::vector<std::shared_ptr<T>>(MAX_MEM_SIZE);

        // fill nextSlot with empty positions
        for (int i = 0; i < MAX_MEM_SIZE ; i++) {
            nextSlot.push(i);
        }
    };

    template <class ...ARGS>
    int create(ARGS ...args) {

        if (nextSlot.empty()) {
            return -1;
        }

        int handle = nextSlot.front(); nextSlot.pop();

        if (instances[handle].get() == nullptr) {
            instances[handle].reset(new T(args...));
        }

        printf("Returning %d handle\n", handle);
        return handle;
    }

    void destroy(int handle) {
        instances[handle].reset();

        // add this empty slot to nextSlot queue
        nextSlot.push(handle);
    }

    std::shared_ptr<T> get(int handle){
        return instances[handle];
    }
};

#endif //GENETICALGORITHMLIB_MEMORYMANAGER_H
