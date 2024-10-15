#include <stdio.h>

// Function to calculate waiting time of each process
void waitingTime(int processes[], int n, int bt[], int at[], int wt[])
{
    int service_time[n]; // To store the cumulative service time
    service_time[0] = at[0];
    wt[0] = 0; // Waiting time for first process is 0

    // Calculating waiting time for each process
    for (int i = 1; i < n; i++)
    {
        // Add burst time of the previous process to its service time
        service_time[i] = service_time[i - 1] + bt[i - 1];

        // Calculate waiting time as the difference between service time and arrival time
        wt[i] = service_time[i] - at[i];

        // If the waiting time is negative, set it to 0 (since process arrived after previous one finished)
        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
    }
}

// Function to calculate turnaround time for each process
void TurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i]; // Turnaround time = burst time + waiting time
    }
}

// Function to calculate average waiting time
void AvgwaitingTime(int processes[], int n, int wt[])
{
    int total_wt = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
    }
    printf("Average Waiting Time = %.2f\n" , (float)total_wt / n);
}

// Function to calculate average turnaround time
void AverageTAT(int processes[], int n, int tat[])
{
    int total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_tat += tat[i];
    }
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processes[n], bt[n], at[n], wt[n], tat[n];

    // Input burst times and arrival times
    printf("Enter burst time and arrival time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d:Arrival Time and Burst Time ", i + 1);
        scanf("%d %d", &at[i] ,&bt[i]);
        processes[i] = i + 1;
    }

    // Calculate waiting time and turnaround time
    waitingTime(processes, n, bt, at, wt);
    TurnaroundTime(processes, n, bt, wt, tat);

    // Display process information
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], at[i], bt[i], wt[i], tat[i]);
    }

    // Calculate and display average waiting time and turnaround time
    AvgwaitingTime(processes, n, wt);
    AverageTAT(processes, n, tat);

    return 0;
}