#ifndef GENETICALGORITHMLIB_ONEMAXPROBLEM_H
#define GENETICALGORITHMLIB_ONEMAXPROBLEM_H

#include <GeneticAlgorithmLib.h>

#include "Problem.h"

class OneMaxProblem: public Problem {
private:
    GAL_HANDLE handle_;

    void printIndividuals();
    void iterate();
    void initializeProblem();

    static float fitnessFunction(const int genes[], int size);
    static bool sortFunction(float individualA, float individualB);


public:
    std::string getProblemName() override;
    void executeProblem() override;
};


#endif //GENETICALGORITHMLIB_ONEMAXPROBLEM_H
