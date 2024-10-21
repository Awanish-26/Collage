                            /*Implementation of Priortiy Scheduling algorithm by Ayush Pal */   /*27-09-2024 */
/*Objective:-Implementaion of Priority CPU Scheduling algorithm */
/*Description:-In priority CPU Scheduling algorithm the process with highest priority will the get the CPU first till it completely 
executes until next process with highest priority comes.The program consist of three things to input given by the use that is arrival 
time,priority of process and burst time of process.The ouput of program displays a table that consist of coloumn of process number, arrival time
 * burst time,Priority, completion time, turnaround time, waiting time. The program also displays average waiting time and  
 * average turnaround time of processes */
import java.util.Scanner;

public class priority {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // Input number of processes
        System.out.print("Please enter the number of processes: ");
        int numberOfProcesses = in.nextInt();

        // Arrays to store process information
        int pid[] = new int[numberOfProcesses];  // Process IDs
        int bt[] = new int[numberOfProcesses];   // Burst Time
        int ar[] = new int[numberOfProcesses];   // Arrival Time
        int pt[] = new int[numberOfProcesses];   // Priority
        int ct[] = new int[numberOfProcesses];   // Completion Time
        int ta[] = new int[numberOfProcesses];   // Turnaround Time
        int wt[] = new int[numberOfProcesses];   // Waiting Time

        // Input arrival time, burst time, and priority for each process
        for (int i = 0; i < numberOfProcesses; i++) {
            System.out.println("Please enter process " + (i+1) + " arrival time: ");
            ar[i] = in.nextInt();
            System.out.println("Please enter process " + (i+1) + " burst time: ");
            bt[i] = in.nextInt();
            System.out.println("Please enter process " + (i+1) + " priority: ");
            pt[i] = in.nextInt();
            pid[i] = i + 1;  // Assigning process ID
        }

        // Sorting processes by priority and arrival time (if priorities are equal)
        for (int i = 0; i < numberOfProcesses; i++) {
            for (int j = i + 1; j < numberOfProcesses; j++) {
                if (pt[i] > pt[j] || (pt[i] == pt[j] && ar[i] > ar[j])) {
                    // Swap based on priority and arrival time
                    int temp = pt[i];
                    pt[i] = pt[j];
                    pt[j] = temp;

                    temp = ar[i];
                    ar[i] = ar[j];
                    ar[j] = temp;

                    temp = bt[i];
                    bt[i] = bt[j];
                    bt[j] = temp;

                    temp = pid[i];
                    pid[i] = pid[j];
                    pid[j] = temp;
                }
            }
        }

        // Calculate Completion Time (CT)
        int currentTime = 0;
        for (int i = 0; i < numberOfProcesses; i++) {
            // If the process arrives after the current time, the CPU remains idle
            if (currentTime < ar[i]) {
                currentTime = ar[i];
            }
            currentTime += bt[i];  // Process the current job
            ct[i] = currentTime;    // Set completion time for the process
        }

        // Calculate Turnaround Time (TAT) and Waiting Time (WT)
        for (int i = 0; i < numberOfProcesses; i++) {
            ta[i] = ct[i] - ar[i];  // Turnaround time = Completion time - Arrival time
            wt[i] = ta[i] - bt[i];  // Waiting time = Turnaround time - Burst time
        }

        // Output process details
        System.out.println("Process\tAT\tBT\tPriority\tCT\tTAT\tWT");
        for (int i = 0; i < numberOfProcesses; i++) {
            System.out.println(pid[i] + "\t" + ar[i] + "\t" + bt[i] + "\t" + pt[i] + "\t\t" + ct[i] + "\t" + ta[i] + "\t" + wt[i]);
        }

        // Calculate and print average Turnaround Time and Waiting Time
        double sumWT = 0, sumTAT = 0;
        for (int i = 0; i < numberOfProcesses; i++) {
            sumWT += wt[i];
            sumTAT += ta[i];
        }
        System.out.println("Average Waiting Time: " + (sumWT / numberOfProcesses));
        System.out.println("Average Turnaround Time: " + (sumTAT / numberOfProcesses));

        in.close();
    }
}

