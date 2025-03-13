#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"./output", NULL};  
    execvp(args[0], args);

    printf("execvp() failed!\n");
    return 1;
}

