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

GAL_Individual GAL_GetIndividual(GA_HANDLE handle, int individualId){
    auto ga = memManager.get(handle);

    if (!ga->isInRage(individualId)){
        return GAL_Individual{};
    }

    Individual ind = ga->getIndividual(individualId);

    // Transform Individual to GAL_Individual
    int size = ind.genes.size();

    //Memory should be deleted using GAL_DestroyIndividualRepresentation
    int *genes = ind.genes.data();

    auto galIndividual = GAL_Individual{genes, size, ind.fitness};

    return galIndividual;
}

float GAL_CalculateFitness(GA_HANDLE handle, GAL_FitnessFunction fitnessFunction){
    auto ga = memManager.get(handle);
    ga->calculateFitness(fitnessFunction);
}

void GAL_Crossover(GA_HANDLE handle){
    auto ga = memManager.get(handle);
    ga->crossOver();
}

void GAL_PrintIndividuals(GA_HANDLE handle){
    auto ga = memManager.get(handle);
    int populationSize = ga->getPopulationSize();
    printf("======= Population Individuals =======\n");
    for (int i=0 ; i < populationSize; i++){
        ga->printIndividual(i);
    }
    printf("======================================\n");

}

void GAL_PrintIndividual(GA_HANDLE handle, int individualId){
    auto ga = memManager.get(handle);

    if (!ga->isInRage(individualId)){
        return;
    }

    ga->printIndividual(individualId);
}

void GAL_SortIndividuals(GA_HANDLE handle, GAL_SortFunction function){
    auto ga = memManager.get(handle);
    ga->sortIndividuals(function);
}