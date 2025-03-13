#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    
    printf("Parent process ID: %d\nBefore forking...\n",getpid());

    pid_t ret = fork();

    if(ret)
        printf("Child process spawned with PID : %d\n", ret);
    else
        printf("Child process with PID : %d\n", getpid());


    printf("Type CTRL+C to exit... ");
    while(1);

    return 0;
}
