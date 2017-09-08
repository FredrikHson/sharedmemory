#include "memorystructure.hpp"

int main(int argc, char* argv[])
{
    sharedmemory mem;
    mem.open();

    for(;;)
    {
        for(int i = 0; i < 20; i++)
        {
            mem.d->numbers[i] = i;
        }
    }

    return 0;
}
