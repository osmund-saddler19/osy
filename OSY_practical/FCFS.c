#include <stdio.h>

// Define a structure to hold process details
typedef struct {
    int id;         // Process ID
    int arrival;    // Arrival Time
    int burst;      // Burst Time
    int completion; // Completion Time
    int turnaround; // Turnaround Time
    int waiting;    // Waiting Time
} Process;

// Function to sort processes based on arrival time (using Bubble Sort)
void sortProcesses(Process arr[], int n) {
    int i, j;
    Process temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].arrival > arr[j + 1].arrival) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate times and averages
void calculateFCFS(Process arr[], int n) {
    int current_time = 0;
    float total_waiting = 0, total_turnaround = 0;

    // Sort processes by arrival time
    sortProcesses(arr, n);

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    printf("---------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        // Current process starts when it arrives or when the previous one finishes
        if (current_time < arr[i].arrival) {
            current_time = arr[i].arrival;
        }

        arr[i].completion = current_time + arr[i].burst;
        arr[i].turnaround = arr[i].completion - arr[i].arrival;
        arr[i].waiting = arr[i].turnaround - arr[i].burst;
        current_time = arr[i].completion;

        total_waiting += arr[i].waiting;
        total_turnaround += arr[i].turnaround;

        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               arr[i].id, arr[i].arrival, arr[i].burst, arr[i].completion, arr[i].turnaround, arr[i].waiting);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process P%d: ", processes[i].id);
        scanf("%d", &processes[i].arrival);
        printf("Enter burst time for process P%d: ", processes[i].id);
        scanf("%d", &processes[i].burst);
    }

    calculateFCFS(processes, n);

    return 0;
}
