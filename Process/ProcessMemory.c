#include <sys/types.h> /* Type definitions used by many programs */
#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Prototypes of commonly used library functions, plus EXIT_SUCCESS and EXIT_FAILURE constants */
#include <unistd.h> /* Prototypes for many system calls */
#include <errno.h> /* Declares errno and defines error constants */
#include <string.h> /* Commonly used string-handling functions */
#include <sys/wait.h>


int main(int argc, char *argv[])
{
    pid_t pid1, var=0;
    
    pid1=fork();

    if(pid1<0)
        printf("Forking Failed\n");
    else if(pid1==0)
    {
        printf("Inside Child process. PID:%d Parent PID:%d .\n", getpid(), getppid());
        var=var+5;
        printf("%d\n",var);
    }
    else if(pid1>0)
    {
        wait(NULL);
        printf("Inside Parent process. PID:%d Parent PID:%d .\n",getpid(), getppid());
        var=var+105;
        printf("%d\n",var);
    }
    printf("\n");
    return 0;
}

/*Every child created by fork gets its own independent virtual memory space.
So while the variables are at the same address within each process's virtual
memory, the fact that they are separate processes means that they are
separate and modifications in one process have no effect on any other process.*/