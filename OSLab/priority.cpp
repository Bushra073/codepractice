#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Take the number of processes.
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    // Declare all necessary arrays.
    int p[100], at[100], bt[100], pr[100];
    int rt[100], ct[100], tat[100], wt[100];

    // Take process information.
    for(int i = 0; i < n; i++)
    {
        // Process numbers will be P1, P2, P3...
        p[i] = i + 1;

        cout << "\nProcess P" << p[i] << endl;

        cout << "Arrival Time: ";
        cin >> at[i];

        cout << "Burst Time: ";
        cin >> bt[i];

        cout << "Priority: ";
        cin >> pr[i];

        // Initially Remaining Time = Burst Time.
        rt[i] = bt[i];
    }

    // Current CPU time.
    int time = 0;

    // Counts completed processes.
    int completed = 0;

    // Keep running until all processes finish.
    while(completed < n)
    {
        // Assume no process is selected.
        int idx = -1;

        // Stores the Highest Priority found so far.
        // Smaller number = Higher Priority.
        int Hpriority = 100000;

        // Check every process.
        for(int i = 0; i < n; i++)
        {
            // Consider only arrived and unfinished processes.
            if(at[i] <= time && rt[i] > 0)
            {
                // Select the process with the highest priority.
                if(pr[i] < Hpriority)
                {
                    Hpriority = pr[i];
                    idx = i;
                }
            }
        }

        // If no process is ready,
        // move CPU time forward.
        if(idx == -1)
        {
            time++;
        }

        // Otherwise execute the selected process.
        else
        {
            // Execute for one time unit.
            time++;

            // Decrease Remaining Time.
            rt[idx]--;

            // If the process has finished.
            if(rt[idx] == 0)
            {
                // Store Completion Time.
                ct[idx] = time;

                // Calculate Turnaround Time.
                tat[idx] = ct[idx] - at[idx];

                // Calculate Waiting Time.
                wt[idx] = tat[idx] - bt[idx];

                // Increase completed count.
                completed++;
            }
        }
    }

    // Print the scheduling table.
    cout << "\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << pr[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    // Calculate average TAT and WT.
    double avgTAT = 0, avgWT = 0;

    for(int i = 0; i < n; i++)
    {
        avgTAT += tat[i];
        avgWT += wt[i];
    }

    avgTAT = avgTAT / n;
    avgWT = avgWT / n;

    // Print averages.
    cout << "\nAverage Turnaround Time = " << avgTAT << endl;
    cout << "Average Waiting Time = " << avgWT << endl;

    return 0;
}
