/*
 * Implementation of FIFO Page Replacement Algorithm by Ayush Pal
 *
 * Objective: Simulate the FIFO page replacement algorithm in an operating system.
 *
 * Description:
 * The FIFO (First-In-First-Out) page replacement algorithm is a memory management 
 * strategy for managing page faults. When a new page needs to be loaded and the memory 
 * is full, the oldest page is removed to make space for the new one. The program takes 
 * input from the user for the sequence of pages to be accessed and the number of frames 
 * (capacity). It then calculates the number of page faults using FIFO strategy.
 */

import java.util.Arrays;
import java.util.HashSet; 
import java.util.LinkedList; 
import java.util.Queue;
import java.util.Scanner; 


public class fifo
{ 
	// Method to find page faults using FIFO 
	static int pageFaults(int pages[], int n, int capacity) 
	{ 
		// To represent set of current pages. We use 
		// an unordered_set so that we quickly check 
		// if a page is present in set or not 
		HashSet<Integer> s = new HashSet<>(capacity); 
	
		// To store the pages in FIFO manner 
		Queue<Integer> indexes = new LinkedList<>() ; 
	
		// Start from initial page 
		int page_faults = 0; 
		for (int i=0; i<n; i++) 
		{ 
			// Check if the set can hold more pages 
			if (s.size() < capacity) 
			{ 
				// Insert it into set if not present 
				// already which represents page fault 
				if (!s.contains(pages[i])) 
				{ 
					s.add(pages[i]); 
	
					// increment page fault 
					page_faults++; 
	
					// Push the current page into the queue 
					indexes.add(pages[i]); 
				} 
			} 
	
			// If the set is full then need to perform FIFO 
			// i.e. remove the first page of the queue from 
			// set and queue both and insert the current page 
			else
			{ 
				// Check if current page is not already 
				// present in the set 
				if (!s.contains(pages[i])) 
				{ 
					//Pop the first page from the queue 
					int val = indexes.peek(); 
	
					indexes.poll(); 
	
					// Remove the indexes page 
					s.remove(val); 
	
					// insert the current page 
					s.add(pages[i]); 
	
					// push the current page into 
					// the queue 
					indexes.add(pages[i]); 
	
					// Increment page faults 
					page_faults++; 
				} 
			} 
		} 
	
		return page_faults; 
	} 
	
	// Driver method 
	public static void main(String args[]) 
	{ 
        Scanner r = new Scanner(System.in);
        //sequenece enter by user
        System.out.println("Please enter sequence of pages ");
        int[] pages = Arrays.stream(r.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        //number of page frame
        System.out.println("Please enter page frame");
        int capacity = r.nextInt();
		System.out.println("Number of Page faults are: "+pageFaults(pages, pages.length, capacity)); 
        r.close();

	} 
} 
