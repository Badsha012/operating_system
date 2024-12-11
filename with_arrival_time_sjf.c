#include <stdio.h>

typedef struct {
    int process_id;    // Process ID
    int burst_time;    // Burst Time
    int waiting_time;  // Waiting Time
    int turnaround_time; // Turnaround Time
} Process;

void calculateWaitingTime(Process processes[], int n) {
    processes[0].waiting_time = 0;  // First process always has zero waiting time
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void sortByBurstTime(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void printProcesses(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].process_id,
               processes[i].burst_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        processes[i].process_id = i + 1;
        scanf("%d", &processes[i].burst_time);
    }

    // Sort processes by burst time
    sortByBurstTime(processes, n);

    // Calculate waiting time and turnaround time
    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);

    // Print the processes and their details
    printProcesses(processes, n);

    // Calculate and print average waiting and turnaround time
    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);

    return 0;
}
