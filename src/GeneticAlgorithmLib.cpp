#include <public/GeneticAlgorithmLib.h>
#include "MemoryManager.h"
#include "GeneticAlgorithm.h"

MemoryManager<GeneticAlgorithm> memManager;

GA_HANDLE GAL_CreateGeneticAlgorithm(int populationSize, int individualSize){
    int handle = memManager.create(populationSize, individualSize);
    return handle;
}

void GAL_DestroyGeneticAlgorithm(GA_HANDLE handle){
    memManager.destroy(handle);
}

//const char* GAL_GetIndividual(GA_HANDLE handle, int individualId);
//
float GAL_CalculateFitness(GA_HANDLE handle, GAL_FitnessFunction fitnessFunction){
    GeneticAlgorithm* ga = memManager.get(handle);
    ga->calculateFitness(fitnessFunction);
}

void GAL_Crossover(GA_HANDLE handle){
    GeneticAlgorithm* ga = memManager.get(handle);
    ga->crossOver();
}

void GAL_PrintIndividual(GA_HANDLE handle, int individualId){
    GeneticAlgorithm* ga = memManager.get(handle);
    ga->printIndividual(individualId);
}