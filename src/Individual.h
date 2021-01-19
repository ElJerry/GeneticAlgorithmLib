#ifndef GENETICALGORITHMLIB_INDIVIDUAL_H
#define GENETICALGORITHMLIB_INDIVIDUAL_H

#include <vector>
#include <public/GeneticAlgorithmLib.h>

class Individual
{
public:
    Individual(int size, int min, int max);
    Individual();
    std::vector<int> genes_;
    float fitness_;

    void printIndividual(int id);
    float calculateFitness(GAL_FitnessFunction fitnessFunction, void *context);
};

#endif //GENETICALGORITHMLIB_INDIVIDUAL_H
