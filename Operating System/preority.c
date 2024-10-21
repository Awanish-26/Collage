/*
    Impementation of Preority CPU scheduling Algorithm
    In priority CPU Scheduling algorithm the process with highest priority will the get the CPU first till it completely 
    executes until next process with highest priority comes
    Arguments:
        1 - Arrival TIme
        2 - Burst Time
        3 - Prority
    Output:
        1 - Average Waiting TIme
        2 - Average Turnaround TIme
*/

#include <stdio.h>

// Structure to represent a process
struct Process {
    int id;         // Process ID
    int bt;         // Burst time
    int at;         // Arrival time
    int priority;   // Priority
    int wt;         // Waiting time
    int tat;        // Turnaround time
};

// Function to sort processes by priority (if same, sort by arrival time)
void sortByPriority(struct Process proc[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].priority > proc[j].priority || 
               (proc[i].priority == proc[j].priority && proc[i].at > proc[j].at)) {
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

// Function to calculate waiting time for all processes
void findWaitingTime(struct Process proc[], int n) {
    int service_time[n];
    service_time[0] = proc[0].at;
    proc[0].wt = 0;

    for (int i = 1; i < n; i++) {
        service_time[i] = service_time[i - 1] + proc[i - 1].bt;
        proc[i].wt = service_time[i] - proc[i].at;

        if (proc[i].wt < 0)
            proc[i].wt = 0;
    }
}

// Function to calculate turnaround time for all processes
void findTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++)
        proc[i].tat = proc[i].bt + proc[i].wt;
}

// Function to calculate average waiting and turnaround time
void findAvgTime(struct Process proc[], int n) {
    int total_wt = 0, total_tat = 0;

    // Find waiting time for all processes
    findWaitingTime(proc, n);

    // Find turnaround time for all processes
    findTurnaroundTime(proc, n);

    // Display processes along with all details
    printf("Processes\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               proc[i].id, proc[i].bt, proc[i].at, proc[i].priority, proc[i].wt, proc[i].tat);
    }

    printf("Average waiting time = %.2f\n", (float)total_wt / n);
    printf("Average turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n;

    printf("Enter the number of processes for Priority CPU Scheduling: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Input burst time, arrival time, and priority for each process
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Process %d Arrival Time | Burst Time | Priority:", proc[i].id);
        scanf("%d %d %d", &proc[i].at, &proc[i].bt, &proc[i].priority);
    }

    // Sort processes by priority (and by arrival time if priority is the same)
    sortByPriority(proc, n);

    // Calculate average waiting time and turnaround time
    findAvgTime(proc, n);

    return 0;
}