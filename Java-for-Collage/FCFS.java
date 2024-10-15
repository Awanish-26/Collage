                                /*Implementation of FCFS by Ayush Pal*/           /*Date:-06/09/2024 */
/*Objection:-Implemenataion of First Come First Serve using array */
/*Description:-In first come first serve the process that arrive first in ready queue will be get the cpu first 
 * to complete its action.The program consist of two things to input given by the use that is arrival time and burst 
 * time of process.The ouput of program displays a table that consist of coloumn of process number, arrival time
 * burst time, completion time, turnaround time, waiting time. The program also displays average waiting time and 
 * average turnaround time of processes
 */
import java.util.Scanner;

public class FCFS {
public static void main(String[] args) {
    System.out.println("Please enter the number of process: ");
    /*use of scanner class to enter data */
    Scanner in = new Scanner(System.in);
    //tell number of process
    int numberOfProcesses=in.nextInt();
    //process id array
    int pid[]=new int[numberOfProcesses];
    //process burst time array
    int bt[]=new int[numberOfProcesses];
    //process arrival time array
    int ar[]=new int[numberOfProcesses];
    //process completion time
    int ct[]=new int[numberOfProcesses];
    //process turnaround time array
    int ta[]=new int[numberOfProcesses];
    //process waiting time array
    int wt[]=new int[numberOfProcesses];
    //Entry of arrival and burst time by the user
    for (int i = 0; i < numberOfProcesses; i++) {
        System.out.println("Please enter process"+(i+1)+" arrival time: ");
        ar[i]=in.nextInt();
        System.out.println("Please enter process "+(i+1)+" burst time: ");
        bt[i]=in.nextInt();
        pid[i]=i+1;
    }
    int temp;
    //sorting of array by bubble sort according to arrival time
    for (int i = 0; i < numberOfProcesses; i++) {
        for (int j = i+1; j < numberOfProcesses; j++) {
            if (ar[i]>ar[j]) {
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;

                temp = pid[i];
                pid[i]=pid[j];
                pid[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }
    System.out.println();
    /*Computation of completion time= */
    ct[0]=bt[0]-ar[0];
    for (int i = 1; i < numberOfProcesses; i++) {
        ct[i]=ct[i-1]+bt[i];
    }
    for(int i=0;i<numberOfProcesses;i++){
        ta[i]=ct[i] - ar[i];
        wt[i]=ta[i] - bt[i];
    }
    System.out.println("Process\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT");
    for (int i = 0; i < numberOfProcesses; i++) {
        System.out.println(pid[i]+"\t\t"+ar[i]+"\t\t"+bt[i]+"\t\t"+ct[i]+"\t\t"+ta[i]+"\t\t"+wt[i]);
    }
    /*Intializing the value of sum of waiting time and turaround time to zero for average  */
    int sumwt=0;
    int sumtat=0;
    for (int i = 0; i < numberOfProcesses; i++) {
        sumwt=sumwt+wt[i];
        sumtat=sumtat+ta[i];
    }
    System.out.println();
    /*Computation of Average waiting time */
    System.out.println("Average waiting time "+ (sumwt/numberOfProcesses));
    /*Computation of Average turnaround time*/
    System.out.println("Average turnaround time "+(sumtat/numberOfProcesses));

    System.out.println("Where AT is arrival time,BT is burst time, CT is compltion time, TAT is turnaround time, WT is waiting time in above table");
}
}