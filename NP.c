#include <stdio.h>

struct process {
    int pid;      // Process ID
    int bt;       // Burst time
    int wt;       // Waiting time
    int tt;       // Turnaround time
    int prior;    // Priority
};

int main() {
    struct process p[10], temp;
    int i, j, n;
    int totwt = 0, tottt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter the burst time for process P%d: ", p[i].pid);
        scanf("%d", &p[i].bt);
        printf("Enter the priority for process P%d: ", p[i].pid);
        scanf("%d", &p[i].prior);
    }

    // Sort processes based on priority (ascending order)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].prior > p[j].prior) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    p[0].wt = 0; // First process has no waiting time
    for (i = 1; i < n; i++) {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    for (i = 0; i < n; i++) {
        p[i].tt = p[i].wt + p[i].bt;
        totwt += p[i].wt;
        tottt += p[i].tt;
    }

    // Display process details
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d", 
               p[i].pid, p[i].bt, p[i].prior, p[i].wt, p[i].tt);
    }

    // Display average waiting and turnaround times
    printf("\n\nAverage Waiting Time: %.2f", (float)totwt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)tottt / n);

    return 0;
}
