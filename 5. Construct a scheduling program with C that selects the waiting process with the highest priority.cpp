#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void calculateWaitingTurnaroundTime(struct Process processes[], int n) {
    int total_waiting_time = 0;
    processes[0].waiting_time = 0;

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void displayResults(struct Process processes[], int n) {
    printf("PID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time,
               processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

void sortByPriority(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority for Process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    sortByPriority(processes, n);
    calculateWaitingTurnaroundTime(processes, n);
    displayResults(processes, n);

    return 0;
}

