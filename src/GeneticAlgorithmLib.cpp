#include <public/GeneticAlgorithmLib.h>
#include "MemoryManager.h"
#include "GeneticAlgorithm.h"

MemoryManager<GeneticAlgorithm> memManager_;

GAL_HANDLE GAL_CreateGeneticAlgorithm(int populationSize, int individualSize, int minGene, int maxGene)
{
    int handle = memManager_.create(populationSize, individualSize, minGene, maxGene);
    return handle;
}

void GAL_DestroyGeneticAlgorithm(GAL_HANDLE handle)
{
    memManager_.destroy(handle);
}

GAL_Individual GAL_GetIndividual(GAL_HANDLE handle, int individualId)
{
    auto geneticAlgorithm = memManager_.get(handle);

    if (!geneticAlgorithm->isInRage(individualId))
    {
        return GAL_Individual{};
    }

    Individual *ind = geneticAlgorithm->getIndividual(individualId);

    // Transform Individual to GAL_Individual
    int size = ind->genes_.size();

    //Memory should be deleted using GAL_DestroyIndividualRepresentation
    int *genes = ind->genes_.data();

    auto galIndividual = GAL_Individual{genes, size, ind->fitness_};

    return galIndividual;
}

void GAL_CalculateFitness(GAL_HANDLE handle, GAL_FitnessFunction fitnessFunction, void *context)
{
    auto ga = memManager_.get(handle);
    ga->calculateFitness(fitnessFunction, context);
}

void GAL_Crossover(GAL_HANDLE handle)
{
    auto ga = memManager_.get(handle);
    ga->crossOver();
}

void GAL_PrintIndividuals(GAL_HANDLE handle)
{
    auto ga = memManager_.get(handle);
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
    auto ga = memManager_.get(handle);

    if (!ga->isInRage(individualId))
    {
        return;
    }

    ga->printIndividual(individualId);
}

void GAL_SortIndividuals(GAL_HANDLE handle, GAL_SortFunction function, void *context)
{
    auto ga = memManager_.get(handle);
    ga->sortIndividuals(function, context);
}