#include <cstdlib>
#include <cstdio>
#include "Individual.h"

// Individual
Individual::Individual()
{
    fitness_ = 0;
}

Individual::Individual(int size, int min, int max)
{
    genes_.resize(size);

    for (int i = 0; i < size; i++)
    {
        genes_[i] = (rand() % ((max - min) + 1)) + min;
    }

    fitness_ = 0;
}

void Individual::printIndividual(int id)
{
    printf("=== Individual %d ===\n", id);
    printf("Genes: ");
    for (auto i = genes_.begin(); i != genes_.end(); i++)
    {
        printf("%d", *i);
    }
    printf("\n");

    printf("Fitness: %.2f\n", fitness_);
}

float Individual::calculateFitness(GAL_FitnessFunction fitnessFunction, void *context)
{
    std::vector<int> genes_int(genes_.size());

    for (int i = 0; i < genes_.size(); i++)
    {
        genes_int[i] = genes_[i];
    }

    fitness_ = fitnessFunction(context, genes_int.data(), genes_.size());
    return fitness_;
}
