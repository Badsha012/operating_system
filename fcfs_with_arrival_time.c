#include <stdio.h>

struct Process {
    int pid;            // Process ID
    int arrival_time;   // Arrival time
    int burst_time;     // Burst time
    int waiting_time;   // Waiting time
    int turnaround_time;// Turnaround time
};

void calculate_times(struct Process processes[], int n) {
    int current_time = 0;
    
    // Sorting processes by arrival time (FCFS)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    for (int i = 0; i < n; i++) {
        // If the process arrives after the current time, the CPU waits until the process arrives
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        // Waiting time = Current time - Arrival time
        processes[i].waiting_time = current_time - processes[i].arrival_time;

        // Turnaround time = Waiting time + Burst time
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        // Update current time for the next process
        current_time += processes[i].burst_time;
    }
}

void print_processes(struct Process processes[], int n) {
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", 
                processes[i].pid, 
                processes[i].arrival_time, 
                processes[i].burst_time, 
                processes[i].waiting_time, 
                processes[i].turnaround_time);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", processes[i].pid);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    calculate_times(processes, n);
    print_processes(processes, n);

    return 0;
}
