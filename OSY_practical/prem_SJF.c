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

    int at[100], bt[100], rt[100];
    int wt[100], tat[100], ct[100];   // ✅ CT added
    int pid[100];

    int gantt_proc[1000];
    int gantt_time[1001];
    int gc = 0;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    gantt_time[0] = 0;

    int last_proc = -2;

    while (completed < n) {
        int selected = -1;
        int min_rt = 999999;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                selected = i;
            }
        }

        if (selected == -1) {
            if (last_proc != -1) {
                gantt_time[gc + 1] = time;
                gc++;
            }
            gantt_proc[gc] = -1;
            last_proc = -1;
            time++;
            continue;
        }

        if (last_proc != pid[selected]) {
            if (gc > 0) {
                gantt_time[gc] = time;
            }
            gantt_proc[gc] = pid[selected];
            last_proc = pid[selected];
            gc++;
        }

        rt[selected]--;
        time++;

        if (rt[selected] == 0) {
            completed++;

            ct[selected] = time;   // ✅ CT stored here

            tat[selected] = time - at[selected];
            wt[selected]  = tat[selected] - bt[selected];
            avg_wt  += wt[selected];
            avg_tat += tat[selected];
        }
    }

    gantt_time[gc] = time;

    avg_wt  /= n;
    avg_tat /= n;

    printf("\nP   AT  BT  CT  WT  TAT\n");   // ✅ CT added in header
    for (int i = 0; i < n; i++) {
        printf("P%d  %2d  %2d  %2d  %2d   %2d\n",
               pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);   // ✅ CT printed
    }

    printf("\nAverage Waiting Time    = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    //printGantt(gantt_proc, gantt_time, gc);

    return 0;
}
