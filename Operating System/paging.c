/*
    Implementation of Memory Management using Paging
    Paging is a memory management scheme that eliminates the need for contiguous allocation 
    of physical memory by dividing logical memory into blocks of the same size called pages 
    and physical memory into blocks of the same size called frames. 
    This program simulates paging by taking user input for physical and logical memory sizes,
    partition size, and manually assigning pages to frames. It calculates the physical address
    of a logical address entered by the user based on page table mapping.
    Inputs - 
       - Physical Memeory Size
       - Logical Memoery Size
       - Partition Size
    Outputs - 
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int logical_address_space, page_size, frame_size, num_pages, num_frames;
    
    // Input logical address space size, page size, and frame size
    printf("Enter the size of the logical address space (in KB): ");
    scanf("%d", &logical_address_space);
    printf("Enter the page size (in KB): ");
    scanf("%d", &page_size);
    printf("Enter the frame size (in KB): ");
    scanf("%d", &frame_size);
    
    // Calculate the number of pages and frames
    num_pages = logical_address_space / page_size;
    num_frames = logical_address_space / frame_size;

    int page_table[num_pages];
    int frames[num_frames];

    // Initialize frames to -1 (indicating they are free)
    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    // Simulate page table mapping each page to a frame
    printf("\nMapping pages to frames:\n");
    for (int i = 0; i < num_pages; i++) {
        int frame;
        do {
            frame = rand() % num_frames;  // Randomly assign frames to pages
        } while (frames[frame] != -1);   // Check if the frame is already occupied

        frames[frame] = i;  // Map the page to this frame
        page_table[i] = frame;  // Update page table

        printf("Page %d -> Frame %d\n", i, frame);
    }

    // Simulate translating logical addresses to physical addresses
    int logical_address;
    printf("\nEnter a logical address (in KB) to translate (-1 to quit): ");
    while (scanf("%d", &logical_address) && logical_address != -1) {
        int page_number = logical_address / page_size;
        int offset = logical_address % page_size;

        if (page_number < num_pages) {
            int frame_number = page_table[page_number];
            int physical_address = frame_number * frame_size + offset;
            printf("Logical address %d -> Physical address %d\n", logical_address, physical_address);
        } else {
            printf("Invalid logical address!\n");
        }

        printf("Enter another logical address to translate (-1 to quit): ");
    }

    printf("Exiting program.\n");
    return 0;
}
