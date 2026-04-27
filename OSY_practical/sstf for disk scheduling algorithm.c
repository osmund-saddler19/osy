#include <stdio.h>
#include <stdlib.h>

void SSTF(int arr[], int size, int head)
{
    int seek_count = 0;
    int visited[size];

    // Initialize visited array
    for(int i = 0; i < size; i++)
        visited[i] = 0;

    printf("\nSeek Sequence with movement:\n");

    for(int i = 0; i < size; i++)
    {
        int min = 99999;
        int index = -1;

        // 🔹 Find closest unvisited request
        for(int j = 0; j < size; j++)
        {
            if(!visited[j])
            {
                int distance = abs(head - arr[j]);

                if(distance < min)
                {
                    min = distance;
                    index = j;
                }
            }
        }

        // 🔹 Mark visited
        visited[index] = 1;

        // 🔹 Print movement
        if(arr[index] > head)
            printf("Head moves from %d to %d  (Seek = %d)   RIGHT\n", head, arr[index], min);
        else if(arr[index] < head)
            printf("Head moves from %d to %d  (Seek = %d)   LEFT\n", head, arr[index], min);
        else
            printf("Head stays at %d (Seek = 0)\n", head);

        seek_count += min;
        head = arr[index];
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

    SSTF(arr, size, head);

    return 0;
}
