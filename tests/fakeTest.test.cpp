#include <catch2.h>

TEST_CASE("testing!!")
{
    SECTION("Test pass on purpose")
    {
        REQUIRE(1 == 1);
    }
}