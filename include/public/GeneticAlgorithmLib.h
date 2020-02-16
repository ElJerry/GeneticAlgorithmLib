#ifndef GENETICALGORITHMLIB_H
#define GENETICALGORITHMLIB_H

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int GA_HANDLE;

GA_HANDLE GAL_CreateGeneticAlgorithm(int populationSize, int individualSize);

void GAL_DestroyGeneticAlgorithm(GA_HANDLE handle);

const char* GAL_GetIndividual(GA_HANDLE handle, int individualId);

double GAL_CalculateFitness(GA_HANDLE handle);

void GAL_Crossover(GA_HANDLE handle);

#ifdef __cplusplus
};
#endif
#endif //GENETICALGORITHMLIB_H