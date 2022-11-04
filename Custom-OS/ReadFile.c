#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "OpenOrCreate.h"

void ReadFile(char *filename)
{
    //stat() function gets status information about a specified file and places it in the area of memory pointed to by the buf argument.
    struct stat st;
    stat(filename, &st);
    //getting the size of the file to be read
    int file_size = st.st_size;

    char *buffer = calloc(file_size * sizeof(char), sizeof(char));

    int file_handle = open(filename, O_RDONLY);

    if (file_handle > 0){ //File Exists
        if (file_size == 0)
        {
            printf("File is empty!\n");
        }
        else
        {
            //ssize_t read(int file, void *buf, size_t nbyte);
            int file_stat = read(file_handle, buffer, file_size);
            buffer[file_size] = '\0';
            printf("%s\n", buffer);
        }
    }
    else{ //File does not exist
        printf("Created new file %s!\n", filename);
        OpenOrCreate(filename);
        ReadFile(filename);
    }
}