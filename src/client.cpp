#include "memorystructure.hpp"

int main(int argc, char* argv[])
{
    sharedmemory mem;
    mem.open();

    for(;;)
    {
        msync(mem.d, sizeof(data), MS_SYNC);
        for(int i = 0; i < 20; i++)
        {
            fprintf(stdout, "mem.d->numbers[%i]=%i\n", i, mem.d->numbers[i]);
        }

        sleep(1);
    }

    return 0;
}
