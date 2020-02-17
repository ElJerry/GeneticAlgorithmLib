#include <public/GeneticAlgorithmLib.h>
#include "MemoryManager.h"
#include "GeneticAlgorithm.h"

MemoryManager<GeneticAlgorithm> memManager;

GA_HANDLE GAL_CreateGeneticAlgorithm(int populationSize, int individualSize, int minGene, int maxGene){
    int handle = memManager.create(populationSize, individualSize, minGene, maxGene);
    return handle;
}

void GAL_DestroyGeneticAlgorithm(GA_HANDLE handle){
    memManager.destroy(handle);
}

GAL_Individual* GAL_GetIndividual(GA_HANDLE handle, int individualId){
    GeneticAlgorithm* ga = memManager.get(handle);
    Individual ind = ga->getIndividual(individualId);

    // Transform Individual to GAL_Individual
    int size = ind.genes.size();

    //Memory should be deleted using GAL_DestroyIndividualRepresentation
    int *genes = new int[size];

    for(int i=0 ; i < size ; i++){
        genes[i] = ind.genes[i];
        std::cout << genes[i] << "+";
    }
    printf("\n");

    auto galIndividual = new GAL_Individual{genes, size, ind.fitness};

    return galIndividual;
}

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

void GAL_DestroyIndividualRepresentation(GAL_Individual* individual){
    //TODO: check if this really deletes all array memory
    delete[] individual->genes;
    delete individual;
}

void GAL_SortIndividuals(GA_HANDLE handle, GAL_SortFunction function){
    GeneticAlgorithm* ga = memManager.get(handle);
    ga->sortIndividuals(function);
}