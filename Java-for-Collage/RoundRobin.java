/* 
 * Implementation of Round Robin by Ayush Pal
 * 
 * Objective: Implementing the Round Robin CPU Scheduling Algorithm.
 * 
 * Description: 
 * Round Robin (RR) is a preemptive CPU scheduling algorithm. Each process is assigned a fixed time slice or time quanta.
 * The CPU executes each process for the given time quanta, then switches to the next process in the queue, 
 * repeating this cycle until all processes are complete. If a process doesn't finish during its time slice, 
 * it is put back into the queue for the next round. The program takes input from the user: the number of processes, 
 * their arrival times, burst times, and the time quanta. The output displays a table of process details such as 
 * arrival time, burst time, completion time, wait time, and turnaround time. Additionally, it calculates and displays 
 * the average waiting time and average turnaround time.
 */

 import java.util.*;

 public class RoundRobin {
	 private static Scanner inp = new Scanner(System.in);
 
	 // Main method (Driver Code)
	 public static void main(String[] args) {
		 // Variable declarations
		 int n, tq, timer = 0, maxProccessIndex = 0;
		 float avgWait = 0, avgTT = 0;
 
		 // Input the time quanta for Round Robin scheduling
		 System.out.print("\nEnter the time quanta : ");
		 tq = inp.nextInt();
 
		 // Input the number of processes
		 System.out.print("\nEnter the number of processes : ");
		 n = inp.nextInt();
 
		 // Arrays to store arrival time, burst time, waiting time, etc. for each process
		 int arrival[] = new int[n];
		 int burst[] = new int[n];
		 int wait[] = new int[n];
		 int turn[] = new int[n];
		 int completion[] = new int[n];  // Array to store completion time
		 int queue[] = new int[n];  // Ready queue to handle process scheduling
		 int temp_burst[] = new int[n];  // Copy of burst times to update during execution
		 boolean complete[] = new boolean[n];  // Boolean array to check process completion
		 for (int i = 0; i < n; i++) {
		 // Input the arrival time for each process
		 System.out.print("\nEnter the arrival time of the process : ");
			 arrival[i] = inp.nextInt();
		 // Input the burst time for each process
		 System.out.print("\nEnter the burst time of the process : ");
			 burst[i] = inp.nextInt();
			 temp_burst[i] = burst[i];  // Initialize temp_burst with original burst times
		}
		 // Initialize the queue and complete array
		 for (int i = 0; i < n; i++) {
			 complete[i] = false;  // Mark all processes as incomplete initially
			 queue[i] = 0;  // Initialize the queue to empty
		 }
 
		 // Start the timer and wait until the first process arrives
		 while (timer < arrival[0]) {
			 timer++;  // Increment the timer until the first process arrives
		 }
		 queue[0] = 1;  // Put the first process into the queue
 
		 // Main loop for scheduling processes
		 while (true) {
			 boolean allProcessesComplete = true;
 
			 // Check if all processes are completed
			 for (int i = 0; i < n; i++) {
				 if (temp_burst[i] != 0) {  // If burst time is not 0, process is incomplete
					 allProcessesComplete = false;
					 break;
				 }
			 }
 
			 if (allProcessesComplete)  // Exit the loop when all processes are done
				 break;
 
			 // Process each task in the ready queue
			 for (int i = 0; (i < n) && (queue[i] != 0); i++) {
				 int timeCounter = 0;
 
				 // Execute the process for either the time quanta or until completion
				 while ((timeCounter < tq) && (temp_burst[queue[0] - 1] > 0)) {
					 temp_burst[queue[0] - 1] -= 1;  // Decrease the remaining burst time
					 timer += 1;  // Increment the timer
					 timeCounter++;  // Count the time spent on the current process
 
					 // Check if a new process has arrived and update the queue
					 checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
				 }
 
				 // If a process is completed, update its completion time and mark it complete
				 if ((temp_burst[queue[0] - 1] == 0) && (complete[queue[0] - 1] == false)) {
					 completion[queue[0] - 1] = timer;  // Record the completion time
					 turn[queue[0] - 1] = timer;  // Turnaround time stores the completion time initially
					 complete[queue[0] - 1] = true;  // Mark the process as complete
				 }
 
				 // Check if the CPU is idle (all processes in the queue are complete)
				 boolean cpuIdle = true;
				 if (queue[n - 1] == 0) {  // If last slot in queue is empty
					 for (int k = 0; k < n && queue[k] != 0; k++) {
						 if (!complete[queue[k] - 1]) {
							 cpuIdle = false;
						 }
					 }
				 } else {
					 cpuIdle = false;  // CPU is not idle if there are active processes
				 }
 
				 // If CPU is idle, increment the timer and check for new arrivals
				 if (cpuIdle) {
					 timer++;
					 checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
				 }
 
				 // Maintain the queue order after preemption or process completion
				 queueMaintainence(queue, n);
			 }
		 }
 
		 // Calculate turnaround time and waiting time for each process
		 for (int i = 0; i < n; i++) {
			 turn[i] = turn[i] - arrival[i];  // Turnaround time = Completion time - Arrival time
			 wait[i] = turn[i] - burst[i];  // Waiting time = Turnaround time - Burst time
		 }
 
		 // Output the process details table
		 System.out.print("\nProgram No.\tArrival Time\tBurst Time\tCompletion Time\tWait Time\tTurnAround Time\n");
		 for (int i = 0; i < n; i++) {
			 System.out.print(i + 1 + "\t\t" + arrival[i] + "\t\t" + burst[i] + "\t\t" + completion[i] + "\t\t"
					 + wait[i] + "\t\t" + turn[i] + "\n");
		 }
 
		 // Calculate and display average waiting time and turnaround time
		 for (int i = 0; i < n; i++) {
			 avgWait += wait[i];
			 avgTT += turn[i];
		 }
		 System.out.print("\nAverage wait time : " + (avgWait / n)+" unit time" + "\nAverage Turn Around Time : " + (avgTT / n)+" unit time");
	 }
 
	 // Function to update the queue when a new process arrives
	 public static void queueUpdation(int queue[], int timer, int arrival[], int n, int maxProccessIndex) {
		 int zeroIndex = -1;
		 // Find the first empty slot in the queue
		 for (int i = 0; i < n; i++) {
			 if (queue[i] == 0) {
				 zeroIndex = i;
				 break;
			 }
		 }
		 if (zeroIndex == -1)  // No empty slot found
			 return;
		 queue[zeroIndex] = maxProccessIndex + 1;  // Add the new process to the queue
	 }
 
	 // Function to check if new processes have arrived and update the queue accordingly
	 public static void checkNewArrival(int timer, int arrival[], int n, int maxProccessIndex, int queue[]) {
		 if (timer <= arrival[n - 1]) {  // If timer is within the arrival times of processes
			 boolean newArrival = false;
			 for (int j = (maxProccessIndex + 1); j < n; j++) {
				 if (arrival[j] <= timer){
					if(maxProccessIndex < j){
						maxProccessIndex = j;
						newArrival = true;
					}
				}
			}
			if(newArrival) // Adds the index of the arriving process (if any)
				queueUpdation(queue,timer,arrival,n, maxProccessIndex);	 
		}
	}

	public static void queueMaintainence(int queue[], int n){

		for(int i = 0; (i < n-1) && (queue[i+1] != 0) ; i++){
			int temp = queue[i];
			queue[i] = queue[i+1];
			queue[i+1] = temp; 
		}
	}
 }
 