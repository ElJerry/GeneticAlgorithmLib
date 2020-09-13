#include <public/GeneticAlgorithmLib.h>
#include "MemoryManager.h"
#include "GeneticAlgorithm.h"

MemoryManager<GeneticAlgorithm> memManager;

GAL_HANDLE GAL_CreateGeneticAlgorithm(int populationSize, int individualSize, int minGene, int maxGene)
{
    int handle = memManager.create(populationSize, individualSize, minGene, maxGene);
    return handle;
}

void GAL_DestroyGeneticAlgorithm(GAL_HANDLE handle)
{
    memManager.destroy(handle);
}

GAL_Individual GAL_GetIndividual(GAL_HANDLE handle, int individualId)
{
    auto ga = memManager.get(handle);

    if (!ga->isInRage(individualId))
    {
        return GAL_Individual{};
    }

    Individual *ind = ga->getIndividual(individualId);

    // Transform Individual to GAL_Individual
    int size = ind->genes.size();

    //Memory should be deleted using GAL_DestroyIndividualRepresentation
    int *genes = ind->genes.data();

    auto galIndividual = GAL_Individual{genes, size, ind->fitness};

    return galIndividual;
}

void GAL_CalculateFitness(GAL_HANDLE handle, GAL_FitnessFunction fitnessFunction, void *context)
{
    auto ga = memManager.get(handle);
    ga->calculateFitness(fitnessFunction, context);
}

void GAL_Crossover(GAL_HANDLE handle)
{
    auto ga = memManager.get(handle);
    ga->crossOver();
}

void GAL_PrintIndividuals(GAL_HANDLE handle)
{
    auto ga = memManager.get(handle);
    int populationSize = ga->getPopulationSize();
    printf("======= Population Individuals =======\n");
    for (int i = 0; i < populationSize; i++)
    {
        ga->printIndividual(i);
    }
    printf("======================================\n");
}

void GAL_PrintIndividual(GAL_HANDLE handle, int individualId)
{
    auto ga = memManager.get(handle);

    if (!ga->isInRage(individualId))
    {
        return;
    }

    ga->printIndividual(individualId);
}

void GAL_SortIndividuals(GAL_HANDLE handle, GAL_SortFunction function, void *context)
{
    auto ga = memManager.get(handle);
    ga->sortIndividuals(function, context);
}