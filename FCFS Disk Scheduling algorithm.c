// FCFS Disk Scheduling algorithm

#include <stdio.h>
#include <math.h>

void FCFS(int arr[], int size, int head)
{
    int seek_count = 0;
    int cur_track, distance;

    for (int i = 0; i < size; i++) {
        cur_track = arr[i];
        
        distance = abs(head - cur_track);

        seek_count += distance;

        head = cur_track;
    }

    printf("Total number of seek operations: %d\n", seek_count);

    printf("Seek Sequence is\n");

    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    int size;
    printf("Enter the number of disk requests: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the disk requests: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int head;
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    FCFS(arr, size, head);

    return 0;
}



Input:
      Request sequence = {176, 79, 34, 60, 92, 11, 41, 114}
      Initial head position = 50
Output:
      Total number of seek operations = 510
      Seek Sequence is 176 79 34 60 92 11 41 114
        
Seek Time: Seek time refers to the time it takes for a hard disk drive (HDD) or other storage device to position its read/write head to the desired location on the disk or storage medium. 
           It is the time required for the mechanical components of the drive to physically move the read/write head to the correct track or cylinder where the data is stored. 
           Seek time is typically measured in milliseconds (ms) and contributes to the overall access time of the storage device.

Rotational Latency: Rotational latency, also known as rotational delay or rotational access time, is the time it takes for a specific sector on a rotating disk to rotate into position under the read/write head.
                    In other words, it is the delay experienced while waiting for the desired data to come around to the read/write head.
                    Rotational latency is determined by the rotational speed of the disk, commonly measured in revolutions per minute (RPM). 
                    The average rotational latency can be calculated as half the time it takes for one complete rotation of the disk.

Transfer Time: Transfer time refers to the time required to read or write data from/to a storage device. 
               It represents the time taken to transfer the data between the storage medium (such as a disk or solid-state drive) and the computer's memory or another destination. 
               Transfer time is influenced by factors such as the data transfer rate of the storage device, the size of the data being transferred, and any overhead involved in the data transfer process.
               It is typically measured in seconds or milliseconds. Faster transfer times indicate quicker data access and can contribute to overall system performance.






