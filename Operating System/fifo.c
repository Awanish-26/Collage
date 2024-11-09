/*
     Implementation of FIFO Page Replacement Algorithm 
     The FIFO (First-In-First-Out) page replacement algorithm is a memory management 
     strategy for managing page faults. When a new page needs to be loaded and the memory 
     is full, the oldest page is removed to make space for the new one. 
     Arguments/Inputs:
        1 - Number of Pages,Pages
        2 -Number of Frames
     Output:
        1 - Page Faults
 */
#include <stdio.h>

int main() {
    int n, frames, page_faults = 0, front = 0;
    
    // Get the number of page references
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    int pages[n];
    printf("Enter the pages : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Get the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    
    int memory[frames];
    for (int i = 0; i < frames; i++) {
        memory[i] = -1; // Initialize frames to -1 (indicating empty)
    }

    printf("\nPage Replacement Process:\n");
    for (int i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < frames; j++) {
            if (memory[j] == page) {
                found = 1; // Page hit
                break;
            }
        }

        // If the page is not found in frames, replace using FIFO
        if (!found) {
            memory[front] = page;             // Replace the oldest page in front
            front = (front + 1) % frames;     // Update front to point to next frame
            page_faults++;                    // Increase page fault count

            // Display the frames' state after each replacement
            printf("Page %d loaded -> ", page);
            for (int j = 0; j < frames; j++) {
                if (memory[j] != -1)
                    printf("%d ", memory[j]);
                else
                    printf("E "); // Indicate empty frame with 'E'
            }
            printf("\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}
