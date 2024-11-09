/*
 * Implementation of LRU Page Replacement Algorithm by Ayush Pal
 *
 * Objective: Simulate the LRU page replacement algorithm in an operating system.
 *
 * Description:
 * The LRU (Least Recently Used) page replacement algorithm is a memory management 
 * technique used to reduce page faults by keeping track of the pages recently accessed.
 * When a new page needs to be loaded and memory is full, the least recently used page 
 * is replaced with the new one. This program takes input from the user for the sequence 
 * of pages to be accessed and the number of frames (capacity). It then calculates the 
 * number of page faults using the LRU strategy.
 */

import java.util.Arrays;
import java.util.HashMap; 
import java.util.HashSet; 
import java.util.Iterator;
import java.util.Scanner; 

class LRU 
{ 
	// Method to find page faults using indexes 
	static int pageFaults(int pages[], int n, int capacity) 
	{ 
		// To represent set of current pages. We use 
		// an unordered_set so that we quickly check 
		// if a page is present in set or not 
		HashSet<Integer> s = new HashSet<>(capacity); 
	
		// To store least recently used indexes 
		// of pages. 
		HashMap<Integer, Integer> indexes = new HashMap<>(); 
	
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
				} 
	
				// Store the recently used index of 
				// each page 
				indexes.put(pages[i], i); 
			} 
	
			// If the set is full then need to perform lru 
			// i.e. remove the least recently used page 
			// and insert the current page 
			else
			{ 
				// Check if current page is not already 
				// present in the set 
				if (!s.contains(pages[i])) 
				{ 
					// Find the least recently used pages 
					// that is present in the set 
					int lru = Integer.MAX_VALUE, val=Integer.MIN_VALUE; 
					
					Iterator<Integer> itr = s.iterator(); 
					
					while (itr.hasNext()) { 
						int temp = itr.next(); 
						if (indexes.get(temp) < lru) 
						{ 
							lru = indexes.get(temp); 
							val = temp; 
						} 
					} 
				
					// Remove the indexes page 
					s.remove(val); 
				//remove lru from hashmap 
				indexes.remove(val); 
					// insert the current page 
					s.add(pages[i]); 
	
					// Increment page faults 
					page_faults++; 
				} 
	
				// Update the current page index 
				indexes.put(pages[i], i); 
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

