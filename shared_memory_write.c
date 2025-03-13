#include <stdio.h>
#include <fcntl.h> //File control
#include <unistd.h> //truncate, close
#include <errno.h>
#include <string.h>
#include <sys/mman.h>


#define SHM_SIZE 16
int main(int argc, char **argv) {
    
    int shm_fd = shm_open("/shm0", O_CREAT | O_RDWR , 0600);
    
    fprintf(stdout, "Shared memory is created with fd: %d\n", shm_fd);
    if(ftruncate(shm_fd, SHM_SIZE * sizeof(char)) < 0)
    {
        fprintf(stderr,"Trucation failed: %s\n", strerror(errno));
        return 1;
    }

    void *map = mmap(0, SHM_SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if(map == MAP_FAILED)
    {
        fprintf(stderr,"Mapping failed: %s\n",strerror(errno));
        return 1;
    }

    char *ptr = (char *)map;
    ptr[0] = 'C';
    ptr[1] = 'L';
    ptr[2] = 'U';
    ptr[3] = 'B';
    ptr[4] = '\n';
    ptr[5] = '\0';

    while(1);
    munmap(ptr, SHM_SIZE);

    close(shm_fd);
    shm_unlink("/shm0");
    return 0;
}
