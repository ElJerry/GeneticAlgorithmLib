#include <cstdio>
#include <cstdlib>
#include "GeneticAlgorithm.h"

// Individual
Individual::Individual(int size) {
    genes.resize(size);
    //TODO: fill with random numbers?
    for (int i = 0 ; i < size ; i++) {
        genes[i] = rand() % 2;
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

// Algorithm
GeneticAlgorithm::GeneticAlgorithm(int population, int individualSize) {
    mPopulationSize = population;
    mIndividualSize = individualSize;

    this->population.clear();

    //Fill population with new individuals
    while(population--) {
        this->population.push_back(Individual(individualSize));
    }
}

void GeneticAlgorithm::calculateFitness(GAL_FitnessFunction func) {
    for (int i=0 ; i < mPopulationSize ; i++) {
        population[i].calculateFitness(func);
    }
}


void GeneticAlgorithm::crossOver() {
    //TODO: Crossover
    printf("Crossover....\n");
}

void GeneticAlgorithm::printIndividual(int id) {
    //TODO: Check provided id is in range
    population[id].printIndividual(id);
}

Individual GeneticAlgorithm::getIndividual(int id) {
    return population[id];
}