#include <stdio.h>

int main()
{
    int m, n;
    int page_fault = 0;
    int page_hit = 0;

    int total_frames, total_pages;

    printf("Enter number of frames: ");
    scanf("%d", &total_frames);

    int frames[total_frames];
    int time[total_frames]; 
    printf("Enter number of pages: ");
    scanf("%d", &total_pages);

    int pages[total_pages];

    printf("Enter page reference string:\n");
    for(int i = 0; i < total_pages; i++)
    {
        scanf("%d", &pages[i]);
    }

    // 🔹 Initialize frames
    for(m = 0; m < total_frames; m++)
    {
        frames[m] = -1;
        time[m] = 0;
    }

    int counter = 0;  

    printf("\nReference string : ");
    for (int i = 0; i < total_pages; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");

    printf("-------------------------------------------------------------\n");
    printf("Step\tPage\t");

    for(int i = 0; i < total_frames; i++)
        printf("Frame%d\t", i+1);

    printf("Status\n");
    printf("-------------------------------------------------------------\n");

    for(n = 0; n < total_pages; n++)
    {
        int found = 0;
        counter++;

        
        for(m = 0; m < total_frames; m++)
        {
            if(frames[m] == pages[n])
            {
                found = 1;
                page_hit++;
                time[m] = counter;  
                break;
            }
        }

        
        if(found == 0)
        {
            int lru_index = 0;

            // find least recently used
            for(m = 1; m < total_frames; m++)
            {
                if(time[m] < time[lru_index])
                {
                    lru_index = m;
                }
            }

            frames[lru_index] = pages[n];
            time[lru_index] = counter;
            page_fault++;
        }

        
        printf("%d\t%d\t", n+1, pages[n]);

        for(m = 0; m < total_frames; m++)
        {
            if(frames[m] == -1)
                printf("-\t");
            else
                printf("%d\t", frames[m]);
        }

        if(found)
            printf("Hit\n");
        else
            printf("*\n");
    }

    printf("-------------------------------------------------------------\n");

    float hit_ratio = (float)page_hit / total_pages * 100;
    float fault_ratio = (float)page_fault / total_pages * 100;

    printf("Total Page Faults = %d\n", page_fault);
    printf("Total Page Hits = %d\n", page_hit);

    printf("Hit Percentage = %.2f%%\n", hit_ratio);
    printf("Fault Percentage = %.2f%%\n", fault_ratio);

    return 0;
}
