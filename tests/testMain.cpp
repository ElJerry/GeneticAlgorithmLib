#include <cstdio>
#include <GeneticAlgorithmLib.h>
#include <iostream>

int main() {
    printf("Hello from tests\n");
    int x = 10;
    while(x--) {
        GA_HANDLE h = GAL_CreateGeneticAlgorithm(1, 2);
        std::cout << "Handle: " << h << std::endl;
        GAL_DestroyGeneticAlgorithm(h);
    }


}