#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
};

void roundRobinScheduling(vector<Process>& processes, int timeQuantum) {
    queue<Process> readyQueue;
    int currentTime = 0;
    int totalProcesses = processes.size();

    // Push all processes to the ready queue
    for (auto& process : processes) {
        readyQueue.push(process);
    }

    cout << "Time\t| Process ID\t| Execution Time\n";
    cout << "---------------------------------------\n";

    while (!readyQueue.empty()) {
        Process currentProcess = readyQueue.front();
        readyQueue.pop();

        int executionTime = min(timeQuantum, currentProcess.remainingTime);
        currentTime += executionTime;
        currentProcess.remainingTime -= executionTime;

        cout << currentTime << "\t| " << currentProcess.id << "\t\t| " << executionTime << endl;

        // If the process is not yet completed, push it back to the queue
        if (currentProcess.remainingTime > 0) {
            readyQueue.push(currentProcess);
        } else {
            cout << "\t| Process " << currentProcess.id << " completed." << endl;
        }
    }

    cout << "All processes completed." << endl;
}

int main() {
    // Example processes
    vector<Process> processes = {
        {1, 0, 10, 10}, // Process ID, Arrival Time, Burst Time, Remaining Time
        {2, 0, 5, 5},
        {3, 0, 8, 8}
    };

    int timeQuantum = 2; // Time quantum for round-robin scheduling

    roundRobinScheduling(processes, timeQuantum);

    return 0;
}
