#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Bubble Sort Functions
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main()
{
    int sms_size = 5;
    int input[sms_size];

    printf("Write Data : ");
    for (int i = 0; i < sms_size; i++)
    {
        scanf("%d", &input[i]);
    }

    bubbleSort(input,sms_size);
    printf("Sorted Data : ");
    for(int i = 0; i < sms_size; i++){
        printf("%d ",input[i]);
    }
    printf("\n");

    // ftok to generate unique key
    // key_t key = ftok("shmfile",65);
    key_t key = 1122;
    size_t size = sizeof(int) * sms_size;

    // creating a new shared memory segment
    //  shmget returns an identifier in shmid
    int shmid = shmget(key, sizeof(int) * sms_size, 0666 | IPC_CREAT);

    // shmat to attach to shared memory
    int *buff = (int *)shmat(shmid, (void *)0, 0);

    // read data in buffer
    for (int i = 0; i < sms_size; i++)
    {
        buff[i] = input[i];
    }

    printf("Sent Data : ");
    for(int i = 0; i < sms_size; i++){
        printf("%d ",buff[i]);
    }
    printf("\n");

    // detach from shared memory
    shmdt(buff);

    return 0;
}
