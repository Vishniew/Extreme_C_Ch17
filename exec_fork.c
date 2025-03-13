#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {   
        char *args[] = {"date", NULL};  
        execvp("date", args);
        printf("execvp() failed\n");
    } else {
        printf("Parent is waiting for the child to finish...\n");
        wait(NULL);
        printf("Child process finished.\n");
    }

    return 0;
}

