#ifndef GENETICALGORITHMLIB_GENETICALGORITHM_H
#define GENETICALGORITHMLIB_GENETICALGORITHM_H

#include <vector>
#include <public/GeneticAlgorithmLib.h>

#include "Individual.h"

class GeneticAlgorithm {
private:
    std::vector<Individual> population;
    int mPopulationSize, mIndividualSize;
    int mMinGene, mMaxGene;

public:
    bool isInRage(int id);
    GeneticAlgorithm(int population, int individualSize, int minGene, int maxGene);

    void calculateFitness(GAL_FitnessFunction fitnessFunction);
    void crossOver();
    void printIndividual(int id);
    Individual getIndividual(int id);
    void sortIndividuals(GAL_SortFunction sortFunction);
    int getPopulationSize();
};

#endif //GENETICALGORITHMLIB_GENETICALGORITHM_H
