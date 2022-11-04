#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void OpenOrCreate(char *filename)
{
    //opening file in Readonly Mode
    //int open(const char *pathname, int flags);
    //int open(const char *pathname, int flags, mode_t mode);
    //open returns a file discriptor(a small non-negative integer) after creating a file
    //The file descriptor is used in subsequent system calls to refer to the open file.

    int file_handle = open(filename, O_RDONLY);

    if (file_handle > 0)
    {
        printf("File Opened.\n");
    }
    else
    {
        printf("Created New File\n");
        file_handle = open(filename, O_CREAT);
    }
}