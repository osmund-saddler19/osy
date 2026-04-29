#include <stdio.h>

// Structure for Priority Scheduling
struct priority_scheduling {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    int turn_around_time;
    int completed;
};

int main() {
    int n;
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    struct priority_scheduling p[n];

    // Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nProcess P%d\n", p[i].pid);

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);

        printf("Priority: ");
        scanf("%d", &p[i].priority);

        p[i].completed = 0;
    }

    int current_time = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        int highest_priority = 999999;

        // 🔥 Dynamic selection (main fix)
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].completed == 0) {
                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            current_time++; // CPU idle
        } else {
            p[idx].waiting_time = current_time - p[idx].arrival_time;

            current_time += p[idx].burst_time;

            p[idx].turn_around_time =
                p[idx].waiting_time + p[idx].burst_time;

            p[idx].completed = 1;
            completed++;

            total_wt += p[idx].waiting_time;
            total_tat += p[idx].turn_around_time;
        }
    }

    // Output (same as yours)
    printf("\nProcess\tAT\tBT\tPriority\tWT\tTAT\n");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].priority,
               p[i].waiting_time,
               p[i].turn_around_time);
    }

    avg_wt = (float) total_wt / n;
    avg_tat = (float) total_tat / n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
