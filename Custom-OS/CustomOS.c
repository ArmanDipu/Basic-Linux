#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "Readfile.h"
#include "CopyFile.h"

int main(int argc, char **argv)
{
    char *path = "home/Desktop >";
    char *commands[] = {"vim", "desc","copy","read","open"};
    
    printf("\n<============ Welcome To MyOS ===========>\n Commands: ");

    for (int i = 0; i < 5; i++)
    {
        printf("%s ", commands[i]);
    }
    printf("cntl+c(Exit)\n");

    pid_t pid;
    pid = fork();

    if (pid == 0)
    {
        printf("\nChild Process\n");

        printf("%s ",path);

        char command[10];
        scanf("%s", command);

        if (strcmp(command, "desc") == 0)
        {
            execlp("ls", "ls", "-l", NULL);
        }

        else if (strcmp(command, "vim") == 0)
        {
            char filename[256];
            scanf("%s", filename);
            execlp("vim", "vim", filename, NULL);
        }

        else if (strcmp(command, "copy") == 0)
        {
            char original_file[256], copy_file[256];

            scanf("%s", original_file);

            scanf("%s", copy_file);

            CopyFile(original_file, copy_file);
        }

        else if (strcmp(command, "open") == 0)
        {
            char filename[256];

            OpenOrCreate(filename);
        }
        else if (strcmp(command, "read") == 0)
        {
            char filename[256];

            scanf("%s", filename);

            ReadFile(filename);
        }
        else
        {
            printf("Command not recognized!\n");
        }
    }
    else if (pid > 0)
    {

        wait(NULL);
        main(argc, argv);
    }

    // wait(NULL);
}