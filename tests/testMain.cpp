#include <cstdio>
#include <GeneticAlgorithmLib.h>
#include <iostream>

using namespace std;

float fitness(int genes[], int size){
    cout << "calculating fittness!!" << endl;
    float res = 0;
    for(int i = 0 ; i < size; i++){
        res++;
        printf("%d ", genes[i]);
    }
    printf("\n");
    return res;
}

int main() {
    printf("Hello from tests\n");

    GA_HANDLE h = GAL_CreateGeneticAlgorithm(10, 5);
    std::cout << "Handle: " << h << std::endl;
    GAL_CalculateFitness(h, fitness);
    GAL_Crossover(h);
    GAL_PrintIndividual(h, 0);
    GAL_PrintIndividual(h, 1);
    GAL_DestroyGeneticAlgorithm(h);

}