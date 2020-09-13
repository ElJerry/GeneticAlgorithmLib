#include <iostream>
#include <memory>

#include "Problem.h"
#include "OneMaxProblem.h"
#include "Knapsack.h"

using namespace std;

int main()
{
    auto problem = unique_ptr<Problem>(new OneMaxProblem());

    cout << "Executing " << problem->getProblemName() << endl;
    problem->executeProblem();

    problem = unique_ptr<Problem>(new Knapsack());
    cout << "Executing " << problem->getProblemName() << endl;
    problem->executeProblem();
}