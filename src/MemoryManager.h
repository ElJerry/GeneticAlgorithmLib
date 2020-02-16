#ifndef GENETICALGORITHMLIB_MEMORYMANAGER_H
#define GENETICALGORITHMLIB_MEMORYMANAGER_H

#include <vector>
#include <cstdio>
#include <iostream>

#define MAX_MEM_SIZE 500

template <class T>
class MemoryManager {
private:
    std::vector<T*> instances;
public:
    MemoryManager() {
        instances.assign(MAX_MEM_SIZE, nullptr);
    };

    template <class ...ARGS>
    int create(ARGS ...args) {
        static int nextPosition = 0;

        int handle = nextPosition;

        // increment position
        // TODO: avoid collisions with already used instance
        nextPosition = (nextPosition + 1) % MAX_MEM_SIZE;

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
    }

    T* get(int handle){
        T* ins = instances[handle];
    }
};

#endif //GENETICALGORITHMLIB_MEMORYMANAGER_H
