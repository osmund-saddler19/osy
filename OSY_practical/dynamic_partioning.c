#include <stdio.h>

int main()
{
    int blockSize[20], processSize[20];
    int m, n;
    int allocation[20];

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of each block:\n");
    for(int i = 0; i < m; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of each process:\n");
    for(int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Initialize allocation as -1 (not allocated)
    for(int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }

    // First Fit Algorithm
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    // Output
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
