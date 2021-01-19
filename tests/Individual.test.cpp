#include <catch2.h>
#include "../src/Individual.cpp"

TEST_CASE("Individual fitness calculation tests")
{

    SECTION("Individual fitness calculation succeeds")
    {
        Individual testIndividual(5, 0, 1);
        testIndividual.genes_ = {0, 1, 1, 0, 0};
        float fitness = testIndividual.calculateFitness([](void *context, const int genes[], const int size) {
            float sum = 0;
            for (int i = 0; i < size; i++)
            {
                sum += genes[i];
            }
            return sum;
        },
                                                        nullptr);

        REQUIRE(fitness == 2.0f);
    }

    SECTION("Individual constructor works as expected")
    {
        Individual testIndividual(10, 0, 1);
        REQUIRE(testIndividual.genes_.size() == 10);
    }
}