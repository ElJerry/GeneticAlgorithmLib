#ifndef GENETICALGORITHMLIB_KNAPSACKPROBLEM_H
#define GENETICALGORITHMLIB_KNAPSACKPROBLEM_H

#include <GeneticAlgorithmLib.h>
#include <vector>

#include "Problem.h"

class Knapsack : public Problem
{
private:
    struct item
    {
        std::string _name;
        int _weight;
        int _value;
    };

    GAL_HANDLE handle_;
    int bagCapacity_; // kilograms
    std::vector<item> items_;

    void configureProblem();
    void iterate();
    void printProductsFromSolution(GAL_Individual ind);
    static bool sortFunction(void *context, const float A, const float B);
    static float fitnessFunction(void *context, const int genes[], const int size);

public:
    std::string getProblemName() override;
    void executeProblem() override;
};

#endif //GENETICALGORITHMLIB_KNAPSACKPROBLEM_H