#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
  
int main()
{
    int findNum, sms_size = 5;
    int buff[sms_size];
    // ftok to generate unique key
    // key_t key = ftok("shmfile",65);
    key_t key = 1122;
    size_t size = sizeof(int)*sms_size;

    // locating an existing shared memory segment based on a key
    // shmget returns an identifier in shmid
    int shmid = shmget(key,size,0666);
  
    // shmat to attach to shared memory
    int *num = (int *)shmat(shmid, (void *)0, 0);
  
    printf("Data read from memory:");
    for(int i=0; i<sms_size; i++){
        printf(" %d",num[i]);
    }
    printf("\n");

    printf("Enter a number to find :");
    scanf("%d",&findNum);
    printf("Number found in %d index.",binarySearch(num,0,sms_size-1,findNum));
    
    //detach from shared memory 
    shmdt(num);
  
    return 0;
}