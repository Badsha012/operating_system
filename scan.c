#include <stdio.h>
#include <stdlib.h>

void scanAlgorithm(int requests[], int numRequests, int head, int diskSize, int direction) {
    int totalSeekTime = 0, currentPosition = head;
    int i, j;
    
    // Sort the requests in ascending order
    for (i = 0; i < numRequests - 1; i++) {
        for (j = 0; j < numRequests - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }
    
    printf("Processing order: ");
    
    // SCAN to the right (increasing cylinder numbers)
    if (direction == 1) {
        for (i = 0; i < numRequests; i++) {
            if (requests[i] >= head) {
                printf("%d ", requests[i]);
                totalSeekTime += abs(requests[i] - currentPosition);
                currentPosition = requests[i];
            }
        }
        
        // If the head reaches the end, simulate reversal (to left)
        printf("%d ", diskSize - 1);
        totalSeekTime += abs(diskSize - 1 - currentPosition);
        currentPosition = diskSize - 1;
        
        for (i = numRequests - 1; i >= 0; i--) {
            if (requests[i] < head) {
                printf("%d ", requests[i]);
                totalSeekTime += abs(requests[i] - currentPosition);
                currentPosition = requests[i];
            }
        }
    } 
    
    // SCAN to the left (decreasing cylinder numbers)
    else {
        for (i = numRequests - 1; i >= 0; i--) {
            if (requests[i] <= head) {
                printf("%d ", requests[i]);
                totalSeekTime += abs(requests[i] - currentPosition);
                currentPosition = requests[i];
            }
        }
        
        // If the head reaches the start, simulate reversal (to right)
        printf("0 ");
        totalSeekTime += abs(0 - currentPosition);
        currentPosition = 0;
        
        for (i = 0; i < numRequests; i++) {
            if (requests[i] > head) {
                printf("%d ", requests[i]);
                totalSeekTime += abs(requests[i] - currentPosition);
                currentPosition = requests[i];
            }
        }
    }
    
    printf("\nTotal seek time: %d\n", totalSeekTime);
}

int main() {
    int requests[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int numRequests = sizeof(requests) / sizeof(requests[0]);
    int head = 53;
    int diskSize = 200; // Assume the disk has 200 cylinders
    int direction = 1;  // 1 for right, 0 for left
    
    printf("Initial head position: %d\n", head);
    scanAlgorithm(requests, numRequests, head, diskSize, direction);
    
    return 0;
}
