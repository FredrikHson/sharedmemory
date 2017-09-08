#include "memorystructure.hpp"

int main(int argc, char* argv[])
{
    sharedmemory mem;
    mem.open();
    int basenumber = 0;

    for(;;)
    {
        for(int i = 0; i < 20; i++)
        {
            mem.d->numbers[i] = i + basenumber;
        }

        basenumber = basenumber + 1;;
        fprintf(stdout,"basenumber:%i numbers[0]:%i\n",basenumber, mem.d->numbers[0]);
        sleep(1);
    }

    return 0;
}
