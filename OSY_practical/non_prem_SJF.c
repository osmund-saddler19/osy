
#include <stdio.h>

/*void printGantt(int chart[], int times[], int count) {
    printf("\nGantt Chart:\n ");
    for (int i = 0; i < count; i++) {
        printf("-------");
    }
    printf("\n|");
    for (int i = 0; i < count; i++) {
        if (chart[i] == -1) printf(" IDLE |");
        else                printf(" P%d  |", chart[i]);
    }
    printf("\n ");
    for (int i = 0; i < count; i++) {
        printf("-------");
    }
    printf("\n%d", times[0]);
    for (int i = 1; i <= count; i++) {
        printf("      %d", times[i]);
    }
    printf("\n");
}*/

int main() {
    int n, time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[100], bt[100], remaining[100];
    int wt[100], tat[100];
    int pid[100];

    int gantt_proc[1000];
    int gantt_time[1001];
    int gc = 0;

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        remaining[i] = bt[i];
    }

    gantt_time[0] = 0;
    int last_proc = -2;  // sentinel value

    while (completed < n) {
        int selected = -1;
        int min_burst = 999999;

        // Find arrived process with shortest original burst time that is not finished
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && remaining[i] > 0 && bt[i] < min_burst) {
                min_burst = bt[i];
                selected = i;
            }
        }

        if (selected == -1) {
            // CPU idle
            if (last_proc != -1) {
                gantt_time[gc] = time;
                gc++;
            }
            gantt_proc[gc] = -1;
            last_proc = -1;
            time++;
            continue;
        }

        // Start new Gantt segment if process changed
        if (last_proc != pid[selected]) {
            if (gc > 0 && last_proc != -1) {
                gantt_time[gc] = time;
            }
            gantt_proc[gc] = pid[selected];
            last_proc = pid[selected];
            gc++;
        }

        // Non-preemptive: run entire remaining burst
        time += remaining[selected];

        // Process finishes
        remaining[selected] = 0;
        completed++;

        tat[selected] = time - at[selected];
        wt[selected]  = tat[selected] - bt[selected];

        avg_wt  += wt[selected];
        avg_tat += tat[selected];

        // Record end of this execution block
        gantt_time[gc] = time;
    }

    avg_wt  /= n;
    avg_tat /= n;

    // Output table
    printf("\nProcess  Arrival  Burst  Waiting  Turnaround\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("P%-7d %-7d %-6d %-7d %d\n",
               pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time    = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    //printGantt(gantt_proc, gantt_time, gc);

    return 0;
}
