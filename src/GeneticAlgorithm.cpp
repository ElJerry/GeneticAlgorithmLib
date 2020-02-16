#include <cstdio>
#include "GeneticAlgorithm.h"

// Individual
Individual::Individual(int size) {
    genes.resize(size);
    //TODO: fill with random numbers?
}

void Individual::printIndividual() {
    for (auto i = genes.begin(); i != genes.end(); i++) {
        printf ("%d",*i);
    }
    printf("\n");
}

float Individual::calculateFitness(GAL_FitnessFunction fitnessFunction) {
    int genes_int[genes.size()];

    for(int i=0 ; i < genes.size(); i++) {
        genes_int[i] = genes[i];
    }

    return fitnessFunction(genes_int, genes.size());
}

// Algorithm
GeneticAlgorithm::GeneticAlgorithm(int population, int individualSize) {
    this->population.assign(population, individualSize);
    populationSize = population;
    individualSize = individualSize;
    //TODO: calculate fitness;
}

void GeneticAlgorithm::calculateFitness(GAL_FitnessFunction func) {
    //TODO: caclulate fitness
    printf("Calculating fitness....\n");
    for (int i=0 ; i<populationSize ; i++) {
        population[i].calculateFitness(func);
    }
}


void GeneticAlgorithm::crossOver() {
    //TODO: Crossover
    printf("Crossover....\n");
}

void GeneticAlgorithm::printIndividual(int id) {
    //TODO: Check provided id is in range
    population[id].printIndividual();
}