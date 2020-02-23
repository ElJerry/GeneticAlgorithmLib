#ifndef GENETICALGORITHMLIB_MEMORYMANAGER_H
#define GENETICALGORITHMLIB_MEMORYMANAGER_H

#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>

#define MAX_MEM_SIZE 500

template <class T>
class MemoryManager {
private:
    std::vector<T*> instances;
    std::queue<int> nextSlot;
public:
    MemoryManager() {
        instances.assign(MAX_MEM_SIZE, nullptr);

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

        if (instances[handle] == nullptr) {
            auto instance = new T(args...);
            instances[handle] = instance;
        }

        printf("Returning %d handle\n", handle);
        return handle;
    }

    void destroy(int handle) {
        T* instance = instances[handle];
        delete(instance);

        instances[handle] = nullptr;
        // add this empty slot to nextSlot queue
        nextSlot.push(handle);
    }

    T* get(int handle){
        T* ins = instances[handle];
    }
};

#endif //GENETICALGORITHMLIB_MEMORYMANAGER_H
