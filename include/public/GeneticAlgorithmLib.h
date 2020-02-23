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

typedef unsigned int GA_HANDLE;

typedef float(*GAL_FitnessFunction)(const int genes[], const int size);

typedef bool(*GAL_SortFunction)(float individualA, float individualB);

GA_HANDLE GAL_CreateGeneticAlgorithm(int populationSize, int individualSize, int minGene, int maxGene);

void GAL_DestroyGeneticAlgorithm(GA_HANDLE handle);

/*
 * Returns a representation of and individual.
 */
GAL_Individual GAL_GetIndividual(GA_HANDLE handle, int individualId);

float GAL_CalculateFitness(GA_HANDLE handle, GAL_FitnessFunction);

void GAL_Crossover(GA_HANDLE handle);

void GAL_PrintIndividuals(GA_HANDLE handle);

void GAL_PrintIndividual(GA_HANDLE handle, int individualId);

void GAL_SortIndividuals(GA_HANDLE handle, GAL_SortFunction sortFunction);


#ifdef __cplusplus
};
#endif
#endif //GENETICALGORITHMLIB_H