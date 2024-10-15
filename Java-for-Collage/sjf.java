                                    /*Implementation of SJF by Ayush Pal */  /* */
/*Objective:-Implementation of Shortest job first Cpu scheduling algorithum */
/*Description:-In shortest job first the process which has shortest job will get cpu first.The program consist of two things to input given by the use that is arrival time and burst 
 * time of process.The ouput of program displays a table that consist of coloumn of process number, arrival time
 * burst time, completion time, turnaround time, waiting time. The program also displays average waiting time and 
 * average turnaround time of processes */

import java.util.Scanner;

public class SJF {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        /*use of scanner class to enter data */
        System.out.println ("Please enter no of process:");
        //tell number of process
        int n = sc.nextInt();
        //process id array
        int pid[] = new int[n];
        //process burst time array
        int at[] = new int[n];
        //process arrival time array
        int bt[] = new int[n];
        //process completion time
        int ct[] = new int[n];
        //process turnaround time array
        int ta[] = new int[n];
        //process waiting time array
        int wt[] = new int[n];
        /*this array acts a flag that consist of 0,1 in which 0 is for incomplete and 1 for complete  */
        int f[] = new int[n];
        /*st stands for start time if the process starts from one the it will be 1 or same as arrival time but intilization
         * is 0
         * tot variable to use check if we have finished all the process 
        */
        int st=0, tot=0;
        /*intilize of average waiting and turnaround time to 0 */
        float avgwt=0, avgta=0;
        //taking input from the user
        for(int i=0;i<n;i++)
        {
            System.out.println ("Please enter process " + (i+1) + " arrival time:");
            at[i] = sc.nextInt();
            System.out.println ("Please enter process " + (i+1) + " brust time:");
            bt[i] = sc.nextInt();
            pid[i] = i+1;
            f[i] = 0;
        }


        while(true)
        {
            int c=n, min = 999;

            /*if the tot is equal to n that is number of process then we have done our job and it is finshed so we break out of while
             * loop
             */
            if (tot == n){
                break;}
            /*If not equal to number of process */    

            for (int i=0; i<n; i++)
            {
              /*We will check which process has least burst time and has arrived first */
                if ((at[i] <= st) && (f[i] == 0) && (bt[i]<min))
                {
                /*if statement will execute only if arrival time is less than starting time 
                 * and flag is 0 that is it is not complete and burst time must be min we can take any number in 
                 * place of min as first process must be smallest
                 */
                    min=bt[i];
                    c=i;
                }
            }
            /*what if we dont have any process arrived at time 0 we should increase the start time */
            if (c==n){
                st++;}
            else
            {
                //calculation of completion time
                ct[c]=st+bt[c];
                //we will increase the stop time by burst time
                st+=bt[c];
                //calculation of turnaround time
                ta[c]=ct[c]-at[c];
                //calculation of waiting time
                wt[c]=ta[c]-bt[c];
                //raising the flag to one
                f[c]=1;
                //getting the new process id
                pid[tot] = c + 1;
                //increase the tot value to 1 and it will work until tot=number of process
                tot++;
            }
        }

        System.out.println("Process\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT");
        /* Calculation of average waiting time and turnaround time*/
        for(int i=0;i<n;i++)
        {
            avgwt+= wt[i];
            avgta+= ta[i];
            System.out.println(pid[i]+"\t\t"+at[i]+"\t\t"+bt[i]+"\t\t"+ct[i]+"\t\t"+ta[i]+"\t\t"+wt[i]);
        }
        System.out.println ("\naverage tat is "+ (float)(avgta/n)+"unit time");
        System.out.println ("average wt is "+ (float)(avgwt/n)+"unit time");
        System.out.println("Where AT is arrival time,BT is burst time, CT is compltion time, TAT is turnaround time, WT is waiting time in above table");
        sc.close();
    }
}