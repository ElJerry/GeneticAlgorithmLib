#ifndef GENETICALGORITHMLIB_MEMORYMANAGER_H
#define GENETICALGORITHMLIB_MEMORYMANAGER_H

#include <vector>
#include <cstdio>

#define MAX_MEM_SIZE 500

template <class T>
class MemoryManager {
private:
    std::vector<T*> instances;
public:
    MemoryManager() {
        instances.assign(MAX_MEM_SIZE, nullptr);
    };

    int create() {
        static int nextPosition = 0;

        int handle = nextPosition;

        // increment position
        // TODO: avoid collisions with already used instance
        nextPosition = (nextPosition + 1) % MAX_MEM_SIZE;

        if (instances[nextPosition] == nullptr) {
            instances[nextPosition] = new T();
        }

        printf("Returning %d handle\n", nextPosition);
        return handle;
    }

    void destroy(int handle) {
        T* instance = instances[handle];
        delete(instance);

        instances[handle] = nullptr;
        printf("Destroyed handle %d\n", handle);
    }
};

#endif //GENETICALGORITHMLIB_MEMORYMANAGER_H
