#ifndef __MEMORYSTRUCTURE_H__
#define __MEMORYSTRUCTURE_H__

#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

struct data
{
    char textdata[1024];
    int numbers[20];
    float halfnumbers[3];
};
class sharedmemory
{
public:
    data* d;
    void open()
    {
        int fd = shm_open("SharedMemoryTest", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);

        if(fd == -1)
        {
            fprintf(stderr, "error opening shared memory\n");
        }

        if(ftruncate(fd, sizeof(data)) == -1)
        {
            fprintf(stderr, "error sizing shared memory\n");
        }

        d = (data*)mmap(nullptr, sizeof(data), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

        if(d == MAP_FAILED)
        {
            fprintf(stderr, "error mapping shared memory\n");
        }
        fprintf(stdout,"done mapping shared memory\nshould be:%i bytes big\n",sizeof(data));
    }

};

#endif //__MEMORYSTRUCTURE_H__
