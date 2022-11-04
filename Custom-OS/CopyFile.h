#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>


void CopyFile(char *inputFile, char *outputFile)
{
    struct stat st;
    stat(inputFile, &st);
    int file_size = st.st_size;

    char *buffer = calloc(file_size * sizeof(char), sizeof(char));

    int file_handle = open(inputFile, O_RDONLY);

    if (file_handle > 0)
    {
        int file_stat = read(file_handle, buffer, file_size);
        buffer[file_size] = '\0';

        int file_handle2 = open(outputFile, O_RDWR | O_CREAT);

        if (file_handle2 > 0)
        {
            write(file_handle2, buffer, file_size);
            printf("File Copied.\n");
        }
        else
        {
            printf("Could not write!\n");
        }
    }
    else
    {
        printf("Could not read!\n");
    }
}