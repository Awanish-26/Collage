/*
    Objective: Implementing the Round Robin CPU Scheduling Algorithm.
    Round Robin (RR) is a preemptive CPU scheduling algorithm. Each process is assigned a fixed time slice or time quanta.
    The CPU executes each process for the given time quanta, then switches to the next process in the queue, 
    repeating this cycle until all processes are complete. If a process doesn't finish during its time slice, 
    it is put back into the queue for the next round.
    Arguments:
        1 - Arrival TIme
        2 - Burst Time
        3 - Prority
    Output:
        1 - Average Waiting TIme
        2 - Average Turnaround TIme
*/
     

#include<stdio.h>
 
int main()
{
    //Input no of processed
    int  n;
    printf("Enter Total Number of Processes for Round Robin:");
    scanf("%d", &n);
    int wt = 0, tat = 0, at[n], bt[n], temp_bt[n];
    int x = n;
 
    //Input details of processes
    for(int i = 0; i < n; i++)
    {
        printf("Process %d Arrival Time|Burst Time : ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        temp_bt[i] = bt[i];
    }
 
    //Input time slot
    int time_slot;
    printf("Enter Time Slot:");
    scanf("%d", &time_slot);
 
    //Total indicates total time
    //counter indicates which process is executed
    int total = 0,  counter = 0,i;
    printf("Process ID\tArrival Time\tBurst Time\tTurnaround Time\t Waiting Time\n");
    for(total=0, i = 0; x!=0; )  
    {  
        // define the conditions
        if(temp_bt[i] <= time_slot && temp_bt[i] > 0)    
        {  
            total = total + temp_bt[i];  
            temp_bt[i] = 0;  
            counter=1;  
        }     
        else if(temp_bt[i] > 0)  
        {  
            temp_bt[i] = temp_bt[i] - time_slot;  
            total  += time_slot;    
        }  
        if(temp_bt[i]==0 && counter==1)  
        {  
            x--; //decrement the process no.  
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1,at[i], bt[i],total-at[i], total-at[i]-bt[i]);  
            wt = wt+total-at[i]-bt[i];  
            tat += total -at[i];  
            counter =0;     
        }  
        if(i==n-1)  
        {  
            i=0;  
        }  
        else if(at[i+1]<=total)  
        {  
            i++;  
        }  
        else  
        {  
            i=0;  
        }  
    }  
    float average_wt = wt * 1.0 / n;
    float average_turnaround_time = tat * 1.0 / n;
    printf("\nAverage Waiting Time:%.2f", average_wt);
    printf("\nAvg Turnaround Time:%.2f", average_turnaround_time);
    return 0;
}