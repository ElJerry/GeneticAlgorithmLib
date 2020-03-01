//TODO: Document header
#ifndef GENETICALGORITHMLIB_H
#define GENETICALGORITHMLIB_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
    // Array of genes
    const int *genes;
    // Gene count
    const int size;
    // Individual fitness
    const float fitness;
} GAL_Individual;

typedef unsigned int GAL_HANDLE;

typedef float(*GAL_FitnessFunction)(void* context, const int genes[], const int size);

typedef bool(*GAL_SortFunction)(void* context, const float individualA, const float individualB);

GAL_HANDLE GAL_CreateGeneticAlgorithm(int populationSize, int individualSize, int minGene, int maxGene);

void GAL_DestroyGeneticAlgorithm(GAL_HANDLE handle);

/*
 * Returns a representation of and individual.
 */
GAL_Individual GAL_GetIndividual(GAL_HANDLE handle, int individualId);

void GAL_CalculateFitness(GAL_HANDLE handle, GAL_FitnessFunction, void* context);

void GAL_Crossover(GAL_HANDLE handle);

void GAL_PrintIndividuals(GAL_HANDLE handle);

void GAL_PrintIndividual(GAL_HANDLE handle, int individualId);

void GAL_SortIndividuals(GAL_HANDLE handle, GAL_SortFunction sortFunction, void* context);


#ifdef __cplusplus
};
#endif

#endif //GENETICALGORITHMLIB_H