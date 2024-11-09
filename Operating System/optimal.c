/*
    Implementation of Optimal Page Replacement Algorithm b
    The Optimal page replacement algorithm is a theoretical memory management technique 
    that minimizes the number of page faults by replacing the page that will not be used 
    for the longest period of time in the future. When a new page needs to be loaded and 
    memory is full, the page that will not be used soonest is replaced with the new one. 
    Inputs:-
        1 - Pages
    Output:-
        2 - Page Faults
 */

#include <stdio.h>

// Function to find the page that will not be used for the longest period in the future
int findOptimal(int pages[], int temp[], int n, int index, int frames) {
    int farthest = index, pos = -1;
    for (int i = 0; i < frames; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (temp[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        // If a page is never referenced in future, return its index
        if (j == n) return i;
    }
    return pos == -1 ? 0 : pos;
}

int main() {
    int frames, n, page_faults = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n], temp[frames];
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < frames; i++) {
        temp[i] = -1; // Initialize frames to -1 (indicating empty)
    }

    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < frames; j++) {
            if (temp[j] == pages[i]) {
                found = 1; // Page hit
                break;
            }
        }

        // If the page is not found in frames, use optimal replacement
        if (!found) {
            page_faults++;

            int empty_found = 0;
            for (int j = 0; j < frames; j++) {
                if (temp[j] == -1) {
                    temp[j] = pages[i];
                    empty_found = 1;
                    break;
                }
            }

            // If no empty frame is available, replace the optimal page
            if (!empty_found) {
                int pos = findOptimal(pages, temp, n, i + 1, frames);
                temp[pos] = pages[i];
            }
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}
