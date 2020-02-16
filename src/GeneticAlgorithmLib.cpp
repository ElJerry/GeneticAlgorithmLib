#include <public/GeneticAlgorithmLib.h>
#include "MemoryManager.h"


MemoryManager<int> memManager;

GA_HANDLE GAL_CreateGeneticAlgorithm(int populationSize, int individualSize){
    int handle = memManager.create();
    return handle;
}

void GAL_DestroyGeneticAlgorithm(GA_HANDLE handle){
    memManager.destroy(handle);
}

//const char* GAL_GetIndividual(GA_HANDLE handle, int individualId);
//
//double GAL_CalculateFitness(GA_HANDLE handle);
//
//void GAL_Crossover(GA_HANDLE handle);
