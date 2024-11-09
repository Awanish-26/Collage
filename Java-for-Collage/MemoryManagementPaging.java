/*
 * Implementation of Memory Management using Paging by Ayush Pal
 *
 * Objective: Simulate memory management in an operating system using paging.
 *
 * Description:
 * Paging is a memory management scheme that eliminates the need for contiguous allocation 
 * of physical memory by dividing logical memory into blocks of the same size called pages 
 * and physical memory into blocks of the same size called frames. This program simulates 
 * paging by taking user input for physical and logical memory sizes, partition size, 
 * and manually assigning pages to frames. It calculates the physical address of a logical 
 * address entered by the user based on page table mapping.
 */

 import java.util.Scanner;

 class PageTableEntry {
     int frameNumber; // Frame number where page is stored
     int presenceBit; // Indicates if page is present in memory (1 if present, -1 if not)
 
     public PageTableEntry() {
         frameNumber = -1;
         presenceBit = -1;
     }
 }
 
 public class MemoryManagementPaging {
 
     static PageTableEntry[] pageTable = new PageTableEntry[10]; // Page table to track frames
     static int[] frameTable = new int[20]; // Frame table for mapping pages to frames
     static int physicalMemorySize, logicalMemorySize, partitionSize, frameCount, pageCount;
 
     // Method to gather memory information from user
     static void info() {
         Scanner scanner = new Scanner(System.in);
 
         System.out.println("MEMORY MANAGEMENT USING PAGING");
 
         System.out.print("Enter the Size of Physical memory: ");
         physicalMemorySize = scanner.nextInt();
 
         System.out.print("Enter the size of Logical memory: ");
         logicalMemorySize = scanner.nextInt();
 
         System.out.print("Enter the partition size: ");
         partitionSize = scanner.nextInt();
 
         // Calculate number of frames and pages
         frameCount = physicalMemorySize / partitionSize;
         pageCount = logicalMemorySize / partitionSize;
 
         System.out.println("The physical memory is divided into " + frameCount + " frames.");
         System.out.println("The Logical memory is divided into " + pageCount + " pages.");
     }
 
     // Method to assign pages to frames based on user input
     static void assign() {
         Scanner scanner = new Scanner(System.in);
 
         // Initialize page table entries with -1 (meaning not assigned)
         for (int i = 0; i < pageCount; i++) {
             pageTable[i] = new PageTableEntry();
         }
 
         // Initialize frame table with a default value
         for (int i = 0; i < frameCount; i++) {
             frameTable[i] = 32555;
         }
 
         // Prompt user to specify frame for each page
         for (int i = 0; i < pageCount; i++) {
             System.out.print("\nEnter the Frame number where page " + i + " must be placed: ");
             int frameNumber = scanner.nextInt();
             frameTable[frameNumber] = i;
 
             // Update page table entry if the page is not yet assigned
             if (pageTable[i].presenceBit == -1) {
                 pageTable[i].frameNumber = frameNumber;
                 pageTable[i].presenceBit = 1;
             }
         }
 
         // Display Page Table
         System.out.println("\n\nPAGE TABLE\n");
         System.out.println("PageAddress\tFrameNo.\tPresenceBit");
         for (int i = 0; i < pageCount; i++) {
             System.out.println(i + "\t\t" + pageTable[i].frameNumber + "\t\t" + pageTable[i].presenceBit);
         }
 
         // Display Frame Table
         System.out.println("\nFRAME TABLE\n");
         System.out.println("FrameAddress\tPageNo");
         for (int i = 0; i < frameCount; i++) {
             System.out.println(i + "\t\t" + frameTable[i]);
         }
     }
 
     // Method to calculate physical address based on logical address
     static void calculatePhysicalAddress() {
         Scanner scanner = new Scanner(System.in);
 
         System.out.println("\n\nProcess to create the Physical Address\n");
 
         System.out.print("Enter the Base Address: ");
         int baseAddress = scanner.nextInt();
 
         System.out.print("Enter the Logical Address: ");
         int logicalAddress = scanner.nextInt();
 
         // Calculate page index and displacement
         int pageIndex = logicalAddress / partitionSize;
         int displacement = logicalAddress % partitionSize;
         int physicalAddress = -1;
 
         // Check if page is present in memory, then calculate physical address
         if (pageTable[pageIndex].presenceBit == 1) {
             physicalAddress = baseAddress + (pageTable[pageIndex].frameNumber * partitionSize) + displacement;
         }
 
         System.out.println("The Physical Address where the instruction is present: " + physicalAddress);
     }
 
     public static void main(String[] args) {
         info();
         assign();
         calculatePhysicalAddress();
     }
 }
 