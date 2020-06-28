#include "Knapsack.h"
#include <iostream>
#include <string>

std::string Knapsack::getProblemName()
{
    return "Knapsack problem";
}

bool Knapsack::sortFunction(void *context, const float A, const float B)
{
    return A > B;
}

std::string genesToString(const int genes[], const int size)
{
    std::string s = "";

    for (int i = 0; i < size; i++)
    {
        s += std::to_string(genes[i]);

        if (i < size - 1)
        {
            s += "-";
        }
    }

    return s;
}

void Knapsack::printProductsFromSolution(GAL_Individual solution)
{
    const int *genes = solution.genes;
    const int size = solution.size;

    std::cout << "============ ITEMS ============" << std::endl;
    for (int i = 0; i < size; i++)
    {
        if (genes[i])
        {
            std::cout << items_[i]._name << " V:" << items_[i]._value << " W:" << items_[i]._weight << std::endl;
        }
    }
}

void Knapsack::executeProblem()
{
    configureProblem();

    int iterations = 50;

    while (iterations--)
    {
        iterate();
    }

    // Get optimal solution
    GAL_Individual optimal = GAL_GetIndividual(handle_, 0);
    std::cout << "Optimal solution: " << genesToString(optimal.genes, optimal.size) << std::endl
              << "fitness: " << optimal.fitness << std::endl;
    printProductsFromSolution(optimal);
}

float Knapsack::fitnessFunction(void *context, const int genes[], const int size)
{
    Knapsack *knapsack_ = (Knapsack *)context;
    float weight = 0;
    float value = 0;

    for (int i = 0; i < size; i++)
    {
        if (genes[i])
        {
            weight += knapsack_->items_[i]._weight;
            value += knapsack_->items_[i]._value;
        }
    }

    // std::cout << weight << " " << value << std::endl;

    if (weight > knapsack_->bagCapacity_)
        return 0;

    return value;
}

void Knapsack::iterate()
{

    GAL_CalculateFitness(handle_, fitnessFunction, this);
    GAL_SortIndividuals(handle_, sortFunction, nullptr);
    GAL_Crossover(handle_);
    GAL_SortIndividuals(handle_, sortFunction, nullptr);
}

void Knapsack::configureProblem()
{
    // Define bag capacity
    bagCapacity_ = 5; //kilograms

    items_ = std::vector<item>{
        {"Burguer", 1, 3},
        {"Xbox", 3, 500},
        {"Laptop", 3, 1200},
        {"Candy", 1, 10},
        {"IPhone", 1, 900},
        {"USB drive", 1, 20}

    };

    handle_ = GAL_CreateGeneticAlgorithm(50, items_.size(), 0, 1);
    std::cout << "Configured!" << std::endl;
}