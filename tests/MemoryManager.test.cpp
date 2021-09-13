#include <catch2.h>
#include <../src/MemoryManager.h>

TEST_CASE("MemoryManager works as expected")
{

    int MAX_MEM_SIZE = 500;
    MemoryManager<int> manager(MAX_MEM_SIZE);

    SECTION("MemoryManager creates a maximum of MAX_MEM_SIZE elements")
    {
        int times = MAX_MEM_SIZE;
        while (times--)
        {
            manager.create(times);
        }

        int error = manager.create(999);
        REQUIRE(error == -1);
    }

    SECTION("MemoryManager destroys memory and allows new creations")
    {
        int times = MAX_MEM_SIZE;
        while (times--)
        {
            manager.destroy(times);
        }

        times = MAX_MEM_SIZE;
        while (times--)
        {
            int handle = manager.create(times);
            REQUIRE(handle != -1);
        }
    }

    SECTION("MemoryManager returns -1 when there is no memory left")
    {
        int times = MAX_MEM_SIZE;
        while (times--)
        {
            int handle = manager.create(times);
            REQUIRE(handle != -1);
        }

        int handle = manager.create(999);
        REQUIRE(handle == -1);
    }
}