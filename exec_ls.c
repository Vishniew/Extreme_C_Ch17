#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    execvp("ls", args);
    
    // This will run only if execvp fails
    printf("execvp() failed: %s\n", strerror(errno));
    return 1;
}

