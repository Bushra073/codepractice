#include<bits/stdc++.h>
using namespace std;

int main()

{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int p[100], at[100], bt[100];
    int ct[100], tat[100], wt[100];

    for (int i=0; i<n; i++)
    {

        p[i] =i+1;
        cout << "\nProcess p" << p[i] << endl;

        cout << "Arrival Time: ";
        cin >> at[i];
        cout << "Burst Time: ";
        cin >> bt[i];

    }

    int done [100] = {0};
    int time = 0;
    int completed = 0;

    while(completed < n)
    {

        int idx = -1;
        int min_bt = INT_MAX;

        for(int i=0; i<n; i++)
        {

            if(at[i] <= time && done[i] == 0)
            {

                if(bt[i]< min_bt)
                {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1)
        {
            time ++
        }
        else
        {
            time += bt[idx];
            ct[idx] = time;
            done[idx] = 1;
            completed++;
        }
    }

    for(int i=0; i<n; i++)
    {

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    return 0;
}



#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

int main()
{
    // ==========================
    // INPUT
    // ==========================

    int n;   // Number of processes

    cout << "Enter number of processes: ";
    cin >> n;

    // Arrays
    int p[100], at[100], bt[100];
    int ct[100], tat[100], wt[100];

    // Take input for every process
    for(int i = 0; i < n; i++)
    {
        p[i] = i + 1;   // Automatically create Process IDs (P1, P2...)

        cout << "\nProcess P" << p[i] << endl;

        cout << "Arrival Time: ";
        cin >> at[i];

        cout << "Burst Time: ";
        cin >> bt[i];
    }

    // ==========================
    // SJF LOGIC
    // ==========================

    // done[] keeps track of whether a process has finished.
    // 0 = Not completed
    // 1 = Completed
    int done[100] = {0};

    // Current CPU time.
    // Starts from 0 because no process has run yet.
    int time = 0;

    // Number of completed processes.
    // Program ends when completed == n.
    int completed = 0;

    // Keep running until every process has finished.
    while(completed < n)
    {
        // idx stores the index of the selected process.
        // -1 means no process has been selected yet.
        int idx = -1;

        // Start with a very large burst time.
        // We will keep replacing it with smaller ones.
        int min_bt = INT_MAX;

        // Check every process one by one.
        for(int i = 0; i < n; i++)
        {
            // We can only choose a process if:
            // 1. It has already arrived.
            // 2. It has not been completed yet.
            if(at[i] <= time && done[i] == 0)
            {
                // If this process has a smaller Burst Time
                // than the current minimum,
                // make it the new shortest process.
                if(bt[i] < min_bt)
                {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        // If no process was selected,
        // CPU stays idle for one unit of time.
        if(idx == -1)
        {
            time++;
        }
        else
        {
            // Run the selected process.

            // Increase current time by its Burst Time.
            time += bt[idx];

            // Current time becomes its Completion Time.
            ct[idx] = time;

            // Mark this process as completed.
            done[idx] = 1;

            // One more process has finished.
            completed++;
        }
    }

    // ==========================
    // TAT & WT
    // ==========================

    for(int i = 0; i < n; i++)
    {
        // Turnaround Time
        // Formula:
        // TAT = CT - AT
        tat[i] = ct[i] - at[i];

        // Waiting Time
        // Formula:
        // WT = TAT - BT
        wt[i] = tat[i] - bt[i];
    }

    // ==========================
    // OUTPUT
    // ==========================

    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }

    return 0;
}