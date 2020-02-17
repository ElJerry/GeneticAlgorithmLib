#include <cstdio>
#include <GeneticAlgorithmLib.h>
#include <iostream>

using namespace std;

float fitness(int genes[], int size){
    float res = 0;
    for(int i = 0 ; i < size; i++){
        res += genes[i];
    }
    return res;
}

void printIndividual(GAL_Individual* ind) {
    cout << "Printing genes returned by GAL_GetIndividual" << endl;

    for(int i=0 ; i < ind->size ; i++) {
        cout << ind->genes[i] << " ";
    }
    cout << "==== " << ind->fitness<<  endl;

}

bool sortFunction(float a, float b) {
    return a>b;
}

int main() {
    srand(time(nullptr));

    GA_HANDLE h = GAL_CreateGeneticAlgorithm(10, 5, 0 , 1);
    std::cout << "Handle: " << h << std::endl;
    GAL_CalculateFitness(h, fitness);
    GAL_Crossover(h);
    GAL_PrintIndividual(h, 0);
    GAL_PrintIndividual(h, 1);
    GAL_PrintIndividual(h, 8);

    auto ind = GAL_GetIndividual(h, 0);
    auto ind2 = GAL_GetIndividual(h, 1);

    printIndividual(ind);
    printIndividual(ind2);

    GAL_DestroyIndividualRepresentation(ind);
    GAL_DestroyIndividualRepresentation(ind2);

    GAL_SortIndividuals(h, sortFunction);
    GAL_PrintIndividual(h, 0);

    GAL_PrintIndividuals(h);

    GAL_DestroyGeneticAlgorithm(h);

}