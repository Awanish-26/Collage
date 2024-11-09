/*
 * Implementation of LRU Page Replacement Algorithm
 * The LRU (Least Recently Used) page replacement algorithm is a memory management 
 * technique used to reduce page faults by keeping track of the pages recently accessed.
 * When a new page needs to be loaded and memory is full, the least recently used page 
 * is replaced with the new one. 
    Argumnets /Inputs
        1 - Frames
        2- Pages
     Output9
        1 - Page Faults
 */

 #include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames, n, page_faults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    int pages[30], temp[frames], time[frames];
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < frames; ++i) {
        temp[i] = -1; // Initialize frames to -1 (indicating empty)
    }

    for (int i = 0; i < n; ++i) {
        int flag1 = 0, flag2 = 0;

        // Check if page is already in one of the frames
        for (int j = 0; j < frames; ++j) {
            if (temp[j] == pages[i]) {
                flag1 = flag2 = 1;
                time[j] = i; // Update last used time
                break;
            }
        }

        if (!flag1) {
            for (int j = 0; j < frames; ++j) {
                if (temp[j] == -1) {
                    page_faults++;
                    temp[j] = pages[i];
                    time[j] = i; // Save the time of insertion
                    flag2 = 1;
                    break;
                }
            }
        }

        if (!flag2) {
            int pos = findLRU(time, frames);
            temp[pos] = pages[i];
            time[pos] = i;
            page_faults++;
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}
