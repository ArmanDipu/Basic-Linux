#include <sys/types.h> /* Type definitions used by many programs */
#include <stdio.h>     /* Standard I/O functions */
#include <stdlib.h>    /* Prototypes of commonly used library functions, plus EXIT_SUCCESS and EXIT_FAILURE constants */
#include <unistd.h>    /* Prototypes for many system calls */
#include <errno.h>     /* Declares errno and defines error constants */
#include <string.h>    /* Commonly used string-handling functions */
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // This ProcessCreation.c can be considered a process when it's executing.
    pid_t pid1, pid2, pid3;

    // creating Process
    pid1 = fork();
    pid2 = fork();
    pid3 = fork();

    if (pid1 < 0)
        printf("Forking Failed\n");
    else if (pid1 == 0)
    {
        printf("Inside Child process. PID:%d Parent PID:%d .\n", getpid(), getppid());
    } 
    else if (pid1 > 0)
    {
        printf("Inside Parent process. PID:%d Parent PID:%d .\n",getpid(), getppid());
    }

    //waiting for child to finish 
    wait(NULL);

    return 0;
}

/*
                       |-> 5884 -> 5888
                       |
              |-> 5881 -
              |        |
              |        |-> 5886
              |
              |
5476 -> 5880 -> 5882 -> 5885
              |
              |
              |
              |
              |-> 5883

*/