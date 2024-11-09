/*
 * Implementation of Optimal Page Replacement Algorithm by Ayush Pal
 *
 * Objective: Simulate the Optimal page replacement algorithm in an operating system.
 *
 * Description:
 * The Optimal page replacement algorithm is a theoretical memory management technique 
 * that minimizes the number of page faults by replacing the page that will not be used 
 * for the longest period of time in the future. When a new page needs to be loaded and 
 * memory is full, the page that will not be used soonest is replaced with the new one. 
 * This program takes input from the user for the sequence of pages to be accessed and 
 * the number of frames (capacity). It then calculates the number of page faults using 
 * the Optimal strategy.
 */

import java.util.*;

public class optimal {
	// Function to check whether a page exists
	// in a frame or not
	static boolean search(int key, int[] fr)
	{
		for (int i = 0; i < fr.length; i++)
			if (fr[i] == key)
				return true;
		return false;
	}

	// Function to find the frame that will not be used
	// recently in future after given index in pg[0..pn-1]
	static int predict(int pg[], int[] fr, int pn,
					int index)
	{
		// Store the index of pages which are going
		// to be used recently in future
		int res = -1, farthest = index;
		for (int i = 0; i < fr.length; i++) {
			int j;
			for (j = index; j < pn; j++) {
				if (fr[i] == pg[j]) {
					if (j > farthest) {
						farthest = j;
						res = i;
					}
					break;
				}
			}

			// If a page is never referenced in future,
			// return it.
			if (j == pn)
				return i;
		}

		// If all of the frames were not in future,
		// return any of them, we return 0. Otherwise
		// we return res.
		return (res == -1) ? 0 : res;
	}

	static int optimalPage(int pg[], int pn, int fn)
	{
		// Create an array for given number of
		// frames and initialize it as empty.
		int[] fr = new int[fn];

		// Traverse through page reference array
		// and check for miss and hit.
		int hit = 0;
		int index = 0;
		for (int i = 0; i < pn; i++) {

			// Page found in a frame : HIT
			if (search(pg[i], fr)) {
				hit++;
				continue;
			}

			// Page not found in a frame : MISS

			// If there is space available in frames.
			if (index < fn)
				fr[index++] = pg[i];

			// Find the page to be replaced.
			else {
				int j = predict(pg, fr, pn, i + 1);
				fr[j] = pg[i];
			}
		}
		return pn-hit;
    	}

	// driver function
    public static void main(String args[]) 
	{ 
        Scanner r = new Scanner(System.in);
        //sequenece enter by user
        System.out.println("Please enter sequence of pages ");
        int[] pages = Arrays.stream(r.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        //number of page frame
        int pn=pages.length;
        System.out.println("Please enter page frame");
        int capacity = r.nextInt();
		System.out.println("Number of page fault: "+ optimalPage(pages, pn, capacity));		
        r.close();

	} 
}
