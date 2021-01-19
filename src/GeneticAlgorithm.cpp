#include <cstdio>
#include <algorithm>
#include <iostream>
#include <functional>
#include "GeneticAlgorithm.h"

#define MUTATION_PROBABILITY 5

// Genetic Algorithm
GeneticAlgorithm::GeneticAlgorithm(int population, int individualSize, int minGene, int maxGene)
{
    populationSize_ = population;
    individualSize_ = individualSize;
    maxGene_ = maxGene;
    minGene_ = minGene;
    this->population.clear();

    //Fill population with new individuals
    while (population--)
    {
        this->population.push_back(Individual(individualSize, minGene, maxGene));
    }
}

bool GeneticAlgorithm::isInRage(int id)
{
    if (id >= populationSize_)
        return false;

    return true;
}

void GeneticAlgorithm::calculateFitness(GAL_FitnessFunction func, void *context)
{
    for (int i = 0; i < population.size(); i++)
    {
        population[i].calculateFitness(func, context);
    }
}

void GeneticAlgorithm::crossOver(GAL_MutationFunction mutationCallback, void *context)
{
    std::vector<Individual> newIndividuals;
    for (int i = 0; i < populationSize_; i = i + 2)
    {
        if (i + 1 >= populationSize_)
            continue;

        Individual newIndividual;

        for (int j = 0; j < individualSize_; j++)
        {
            if (rand() % 2)
            {
                newIndividual.genes_.push_back(population[i].genes_[j]);
            }
            else
            {
                newIndividual.genes_.push_back(population[i + 1].genes_[j]);
            }

            // Check for mutation
            int mutationAux = rand() % 101;
            if (mutationAux <= MUTATION_PROBABILITY)
            {
                if (mutationCallback != nullptr)
                {
                    newIndividual.genes_[j] = mutationCallback(context, newIndividual.genes_[j]);
                }
            }
        }

        newIndividuals.push_back(newIndividual);
    }

    // Replace last n/2 individuals with the new ones
    int firstIndex = population.size() / 2;
    int newIndex = 0;
    for (int i = firstIndex; i < population.size(); i++)
    {
        population[i] = newIndividuals[newIndex++];
    }
}

void GeneticAlgorithm::printIndividual(int id)
{
    population[id].printIndividual(id);
}

Individual *GeneticAlgorithm::getIndividual(int id)
{
    return &population[id];
}

void GeneticAlgorithm::sortIndividuals(GAL_SortFunction sortFunction, void *context)
{
    std::sort(population.begin(), population.end(), [=](const Individual &i1, const Individual &i2) {
        return sortFunction(context, i1.fitness_, i2.fitness_);
    });
}

int GeneticAlgorithm::getPopulationSize()
{
    return populationSize_;
}