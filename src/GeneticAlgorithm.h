#ifndef GENETICALGORITHMLIB_GENETICALGORITHM_H
#define GENETICALGORITHMLIB_GENETICALGORITHM_H

#include <vector>
#include <public/GeneticAlgorithmLib.h>

#include "Individual.h"

class GeneticAlgorithm
{
private:
    std::vector<Individual> population;
    int populationSize_, individualSize_;
    int minGene_, maxGene_;

public:
    bool isInRage(int id);
    GeneticAlgorithm(int population, int individualSize, int minGene, int maxGene);

    void calculateFitness(GAL_FitnessFunction fitnessFunction, void *context);
    void crossOver(GAL_MutationFunction mutationCallback, void *context);
    void printIndividual(int id);
    Individual *getIndividual(int id);
    void sortIndividuals(GAL_SortFunction sortFunction, void *context);
    int getPopulationSize();
};

#endif //GENETICALGORITHMLIB_GENETICALGORITHM_H
