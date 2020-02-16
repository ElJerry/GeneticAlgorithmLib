#ifndef GENETICALGORITHMLIB_H
#define GENETICALGORITHMLIB_H

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int GA_HANDLE;

typedef float(*GAL_FitnessFunction)(int genes[], int size);

GA_HANDLE GAL_CreateGeneticAlgorithm(int populationSize, int individualSize);

void GAL_DestroyGeneticAlgorithm(GA_HANDLE handle);

const char* GAL_GetIndividual(GA_HANDLE handle, int individualId);

float GAL_CalculateFitness(GA_HANDLE handle, GAL_FitnessFunction);

void GAL_Crossover(GA_HANDLE handle);

void GAL_PrintIndividual(GA_HANDLE handle, int individualId);

#ifdef __cplusplus
};
#endif
#endif //GENETICALGORITHMLIB_H