#include <iostream>
#include <functional>

#include "OneMaxProblem.h"

std::string OneMaxProblem::getProblemName() {
    return "One max";
}

void OneMaxProblem::executeProblem() {

    initializeProblem();

    int iterations = 50;

    while (iterations--) {
        iterate();
    }

    std::cout << "Printing top individual "  << std::endl;
    GAL_PrintIndividual(handle_, 0);
}


void OneMaxProblem::printIndividuals() {
    GAL_PrintIndividuals(handle_);
}

float OneMaxProblem::fitnessFunction(void* context, const int genes[], const int size) {

    float fitness = 0;
    for (int i = 0; i < size ; i++) {
        fitness += genes[i];
    }

    return fitness;
}

bool OneMaxProblem::sortFunction(void* context, float individualA, float individualB) {
    return individualA > individualB;
}

void OneMaxProblem::iterate() {
    GAL_Crossover(handle_);

    GAL_CalculateFitness(handle_, fitnessFunction, this);
    GAL_SortIndividuals(handle_, sortFunction, this);
}

void OneMaxProblem::initializeProblem() {
#ifdef __linux__
    srand(time(nullptr));
#endif

    handle_ = GAL_CreateGeneticAlgorithm(100, 60, 0, 1);
    GAL_CalculateFitness(handle_, OneMaxProblem::fitnessFunction, this);
    GAL_SortIndividuals(handle_, OneMaxProblem::sortFunction, this);
    printIndividuals();
}