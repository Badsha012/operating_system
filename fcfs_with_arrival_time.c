#include <stdio.h>

// Structure to hold process information
struct Process {
    int pid;          // Process ID
    int arrivalTime;  // Arrival time
    int burstTime;    // Burst time
    int completionTime; // Completion time
    int turnaroundTime; // Turnaround time
    int waitingTime;    // Waiting time
};

void calculateTimes(struct Process processes[], int n, float *avgTurnaroundTime, float *avgWaitingTime) {
    int currentTime = 0;
    int totalTurnaroundTime = 0;
    int totalWaitingTime = 0;

    for (int i = 0; i < n; i++) {
        // If the CPU is idle, advance to the arrival time of the next process
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        // Calculate completion time
        processes[i].completionTime = currentTime + processes[i].burstTime;

        // Calculate turnaround time
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;

        // Calculate waiting time
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        // Update totals
        totalTurnaroundTime += processes[i].turnaroundTime;
        totalWaitingTime += processes[i].waitingTime;

        // Update current time
        currentTime = processes[i].completionTime;
    }

    // Calculate averages
    *avgTurnaroundTime = (float)totalTurnaroundTime / n;
    *avgWaitingTime = (float)totalWaitingTime / n;
}

void printTable(struct Process processes[], int n, float avgTurnaroundTime, float avgWaitingTime) {
    printf("\nFCFS Scheduling\n");
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", 
               processes[i].pid, 
               processes[i].arrivalTime, 
               processes[i].burstTime, 
               processes[i].completionTime, 
               processes[i].turnaroundTime, 
               processes[i].waitingTime);
    }

    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        processes[i].pid = i + 1;
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
    }

    // Sort processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    float avgTurnaroundTime, avgWaitingTime;

    // Calculate completion, turnaround, and waiting times
    calculateTimes(processes, n, &avgTurnaroundTime, &avgWaitingTime);

    // Print the result
    printTable(processes, n, avgTurnaroundTime, avgWaitingTime);

    return 0;
}
