#include <stdio.h>

// Structure for Priority Scheduling
struct priority_scheduling {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    int turn_around_time;
};

int main() {
    int n;
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    struct priority_scheduling p[n], temp;

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
    }

    // Sorting (by Arrival Time, then Priority)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time ||
               (p[i].arrival_time == p[j].arrival_time &&
                p[i].priority > p[j].priority)) {

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Waiting Time & Turnaround Time Calculation
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
        }

        p[i].waiting_time = current_time - p[i].arrival_time;

        current_time += p[i].burst_time;

        p[i].turn_around_time = p[i].waiting_time + p[i].burst_time;
    }

    // Output
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

    // Average Waiting Time
    for (int i = 0; i < n; i++) {
        total_wt += p[i].waiting_time;
    }

    avg_wt = (float) total_wt / n;

    // Average Turnaround Time
    for (int i = 0; i < n; i++) {
        total_tat += p[i].turn_around_time;
    }

    avg_tat = (float) total_tat / n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}
