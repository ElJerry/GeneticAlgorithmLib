#ifndef GENETICALGORITHMLIB_PROBLEM_H
#define GENETICALGORITHMLIB_PROBLEM_H

#include <string>

class Problem {

private:
    std::string name_;

public:
    virtual std::string getProblemName() = 0;
    virtual void executeProblem() = 0;
};


#endif //GENETICALGORITHMLIB_PROBLEM_H
