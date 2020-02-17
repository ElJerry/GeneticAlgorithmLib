#include <cstdlib>
#include <cstdio>
#include "Individual.h"

// Individual
Individual::Individual(int size, int min, int max) {
    genes.resize(size);

    for (int i = 0 ; i < size ; i++) {
        genes[i] = (rand() % ((max-min)+1)) + min;
    }
}

void Individual::printIndividual(int id) {
    printf("=== Individual %d ===\n", id);
    printf("Genes: ");
    for (auto i = genes.begin(); i != genes.end(); i++) {
        printf ("%d",*i);
    }
    printf("\n");

    printf("Fitness: %.2f\n", fitness);
}

float Individual::calculateFitness(GAL_FitnessFunction fitnessFunction) {
    int genes_int[genes.size()];

    for(int i=0 ; i < genes.size(); i++) {
        genes_int[i] = genes[i];
    }

    fitness = fitnessFunction(genes_int, genes.size());
    return fitness;
}
