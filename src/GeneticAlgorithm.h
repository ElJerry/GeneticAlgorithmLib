#ifndef GENETICALGORITHMLIB_GENETICALGORITHM_H
#define GENETICALGORITHMLIB_GENETICALGORITHM_H

#include <vector>
#include <public/GeneticAlgorithmLib.h>

class Individual{
public:
    Individual(int size);
    std::vector<int> genes;
    float fitness;

    void printIndividual();
    float calculateFitness(GAL_FitnessFunction fitnessFunction);
};

class GeneticAlgorithm {
private:
    std::vector<Individual> population;
    int populationSize, individualSize;
public:

    GeneticAlgorithm(int population, int individualSize);

    void calculateFitness(GAL_FitnessFunction fitnessFunction);
    void crossOver();
    void printIndividual(int id);

};


#endif //GENETICALGORITHMLIB_GENETICALGORITHM_H
