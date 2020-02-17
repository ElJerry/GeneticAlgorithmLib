#include <cstdio>
#include <GeneticAlgorithmLib.h>
#include <iostream>

using namespace std;

float fitness(int genes[], int size){
//    cout << "calculating fittness!!" << endl;
    float res = 0;
    for(int i = 0 ; i < size; i++){
        res++;
//        printf("%d ", genes[i]);
    }
//    printf("\n");
    return res;
}

void printIndividual(GAL_Individual* ind) {
    cout << "Printing genes returned by GAL_GetIndividual" << endl;
    for(int i=0 ; i < ind->size ; i++) {
        cout << ind->genes[i] << " ";
    }
    cout << "==== " << ind->fitness<<  endl;

}

int main() {
    printf("Hello from tests\n");

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

    GAL_DestroyGeneticAlgorithm(h);

}