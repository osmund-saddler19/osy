#include<stdio.h>
#include<stdlib.h>
#define MAX_PAGES 100
#define MAX_FRAMES 10
int main() {
    int pages[MAX_PAGES]; // array to hold page references
    int frames[MAX_FRAMES]; // array to hold frames
    int num_pages, num_frames; // number of pages and frames
    int page_faults = 0; // count of page faults

    // Input the number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &num_pages);

    // Input the page reference sequence
    printf("Enter the page reference sequence: ");
    for (int i = 0; i < num_pages; i++)
        scanf("%d", &pages[i]);

    // Input the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &num_frames);

    // Initialize frames to -1 indicating empty frame
    for (int i = 0; i < num_frames; i++)
        frames[i] = -1;

    // Simulate FCFS paging algorithm
    printf("\nFCFS Paging Simulation:\n");
    printf("Page reference sequence: ");
    for (int i = 0; i < num_pages; i++)
        printf("%d ", pages[i]);
    printf("\n\n");

    for (int i = 0; i < num_pages; i++) {
        // Check if page is already in frame
        int page_in_frame = 0;
        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == pages[i]) {
                page_in_frame = 1;
                break;
            }
        }
        // If page is not in frame, perform page fault and replace the page
        if (!page_in_frame) {
            frames[page_faults % num_frames] = pages[i]; // replace page
            page_faults++; // increment page fault count
        }

        // Display current frame state
        printf("Page %d -> Frames: ", pages[i]);
        for (int j = 0; j < num_frames; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", page_faults);

    return 0;
}
