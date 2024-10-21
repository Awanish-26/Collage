/*
Objective - Implementation of Shortest Remaining time first Cpu scheduling algorithum
Arguments:
    1-No of Process
    2-Arrival Time
    3-Burst Time
Returns:
    1:Average Waiting Time
    2:Average Turnaround TIme
*/
#include <stdio.h>
#include <limits.h>

// Function to find the waiting time for all processes
void findWaitingTime(int n, int bt[], int at[], int wt[]) {
    int rt[n], complete = 0, t = 0, minm = INT_MAX, shortest = 0, check = 0;

    // Copy burst times to remaining time array
    for (int i = 0; i < n; i++) rt[i] = bt[i];

    // Process until all processes get completed
    while (complete != n) {
        // Find process with minimum remaining time at the current time
        minm = INT_MAX, check = 0;
        for (int j = 0; j < n; j++) {
            if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j], shortest = j, check = 1;
            }
        }

        if (check == 0) { t++; continue; }

        rt[shortest]--; // Reduce remaining time by 1

        // If a process gets completely executed
        if (rt[shortest] == 0) {
            complete++;
            int finish_time = t + 1;
            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if (wt[shortest] < 0) wt[shortest] = 0;
        }
        t++;
    }
}

// Function to calculate turn around time
void findTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) tat[i] = bt[i] + wt[i];
}

// Function to calculate average waiting and turn-around time
void findAvgTime(int n, int bt[], int at[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Find waiting time of all processes
    findWaitingTime(n, bt, at, wt);

    // Find turnaround time of all processes
    findTurnaroundTime(n, bt, wt, tat);

    // Display processes along with their burst time, waiting time, and turnaround time
    printf("Processes\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i], total_tat += tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n];

    // Input arrival and burst time for all processes
    for (int i = 0; i < n; i++) {
        printf("Process %d Arrival Time | Burst Time:", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Calculate average waiting time and turnaround time
    findAvgTime(n, bt, at);
    return 0;
}