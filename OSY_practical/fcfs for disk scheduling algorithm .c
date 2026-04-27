#include <stdio.h>
#include <stdlib.h>

void FCFS(int arr[], int size, int head)
{
    int seek_count = 0;

    printf("\nSeek Sequence with movement:\n");

    for(int i = 0; i < size; i++)
    {
        int distance = abs(head - arr[i]);

        // Determine direction
        if(arr[i] > head)
            printf("Head moves from %d to %d  (Seek = %d)   RIGHT \n", head, arr[i], distance);
        else if(arr[i] < head)
            printf("Head moves from %d to %d  (Seek = %d)    LEFT \n", head, arr[i], distance);
        else
            printf("Head stays at %d (Seek = 0)\n", head);

        seek_count += distance;
        head = arr[i];
    }

    printf("\nTotal seek operations: %d\n", seek_count);
}

int main()
{
    int n;
    int size;
    int head;

    printf("Enter total number of tracks (n): ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid number of tracks!\n");
        return 0;
    }

    printf("Enter number of disk requests: ");
    scanf("%d", &size);

    if(size <= 0 || size > 100)
    {
        printf("Invalid request size!\n");
        return 0;
    }

    int arr[size];

    printf("Enter %d track requests (0 to %d):\n", size, n - 1);

    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);

        if(arr[i] < 0 || arr[i] >= n)
        {
            printf("Invalid request! Must be between 0 and %d\n", n - 1);
            return 0;
        }
    }

    printf("Enter initial head position (0 to %d): ", n - 1);
    scanf("%d", &head);

    if(head < 0 || head >= n)
    {
        printf("Invalid head position!\n");
        return 0;
    }

    FCFS(arr, size, head);

    return 0;
}
