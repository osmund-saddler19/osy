#include <stdio.h>
#include <limits.h>

// Structure
struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_bt;
    int priority;
    int completion_time;
    int waiting_time;
    int turn_around_time;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    // Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nProcess P%d\n", p[i].pid);

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);

        printf("Priority (lower value = higher priority): ");
        scanf("%d", &p[i].priority);

        p[i].remaining_bt = p[i].burst_time;
    }

    int completed = 0, current_time = 0;
    int total_wt = 0, total_tat = 0;

    // Scheduling
    while (completed < n) {
        int idx = -1;
        int highest_priority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].remaining_bt > 0) {

                // Priority + Tie-breaking (Arrival Time)
                if (p[i].priority < highest_priority ||
                   (p[i].priority == highest_priority &&
                    p[i].arrival_time < p[idx].arrival_time)) {

                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        // CPU Idle
        if (idx == -1) {
            current_time++;
            continue;
        }

        // Execute for 1 unit (Preemption happens here)
        p[idx].remaining_bt--;
        current_time++;

        // If process completes
        if (p[idx].remaining_bt == 0) {
            completed++;

            p[idx].completion_time = current_time;
            p[idx].turn_around_time =
                p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time =
                p[idx].turn_around_time - p[idx].burst_time;

            total_wt += p[idx].waiting_time;
            total_tat += p[idx].turn_around_time;
        }
    }

    // Output
    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].priority,
               p[i].waiting_time,
               p[i].turn_around_time);
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    printf("\nAverage Waiting Time = %.2f\n", avg_wt);
    printf("Average Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
