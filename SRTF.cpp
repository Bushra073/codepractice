#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter no of processes: ";
    cin >> n;

        int rt[100], p[100], at[100], bt[100];
    int ct[100], tat[100], wt[100];

    for(int i=0; i<n; i++)
    {

        p[i] = i+1;
        cout << "Proocess p" << p[i] << endl;

        cout << "Arrival Time: ";
             cin >> at[i];
        cout << "Burst Time: ";
             cin >> bt[i];
        rt[i] = bt[i];

    }

    int time = 0;
    int completed = 0;

    while(completed < n)
    {
        int idx = -1;
        int min_rt = INT_MAX;

        for(int i=0; i<n; i++)
        {

            if(at[i] <= time && rt[i] > 0)
            {

                if(rt[i] < min_rt)
                {

                    min_rt = rt[i];
                    idx = i;
                }

            }

        }
        if(idx == -1)
        {
            time++;
        }
        else
        {
            time++ ;
            rt[idx]-- ;

            if(rt[idx] == 0)
            {
                ct[idx] = time;
                completed++ ;
            }
        }


    }
    for(int i=0; i<n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n" ;

    for(int i=0; i<n; i++)
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




#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Number of processes
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    // Arrays
    // p[]  = Process Number
    // at[] = Arrival Time
    // bt[] = Original Burst Time
    // rt[] = Remaining Time (changes every second)
    // ct[] = Completion Time
    // tat[]= Turnaround Time
    // wt[] = Waiting Time
    int p[100], at[100], bt[100], rt[100];
    int ct[100], tat[100], wt[100];

    // Take input
    for(int i = 0; i < n; i++)
    {
        p[i] = i + 1;

        cout << "\nProcess P" << p[i] << endl;

        cout << "Arrival Time: ";
        cin >> at[i];

        cout << "Burst Time: ";
        cin >> bt[i];

        // Initially Remaining Time = Burst Time
        rt[i] = bt[i];
    }

    // Current CPU time
    int time = 0;

    // Counts how many processes have finished
    int completed = 0;

    // Keep running until every process finishes
    while(completed < n)
    {
        // Index of the selected process
        // -1 means no process has been selected yet
        int idx = -1;

        // Assume the smallest remaining time is a very large number
        int min_rt = INT_MAX;

        // Check every process
        for(int i = 0; i < n; i++)
        {
            // We can only choose a process if:
            // 1. It has already arrived.
            // 2. It still has some remaining time.
            if(at[i] <= time && rt[i] > 0)
            {
                // If this process has a smaller Remaining Time,
                // make it the new selected process.
                                             //[if(rt[i] < min_rt || (rt[i] == min_rt && at[i] < at[idx]))
                                             //Choose this process if:
                                             //it has a smaller Remaining Time,
                                            //OR
                                        //its Remaining Time is the same, but it arrived earlier]
                if(rt[i] < min_rt)
                {
                    min_rt = rt[i];
                    idx = i;
                }
            }
        }

        // If no process has arrived yet,
        // CPU stays idle for one unit of time.
        if(idx == -1)
        {
            time++;
        }
        else
        {
            // Run the selected process for ONLY ONE SECOND.
            time++;

            // One second of work is completed.
            rt[idx]--;

            // If Remaining Time becomes zero,
            // the process has finished.
            if(rt[idx] == 0)
            {
                completed++;

                // Current time becomes Completion Time.
                ct[idx] = time;
            }
        }
    }

    // Calculate Turnaround Time and Waiting Time
    for(int i = 0; i < n; i++)
    {
        // TAT = CT - AT
        tat[i] = ct[i] - at[i];

        // WT = TAT - BT
        wt[i] = tat[i] - bt[i];
    }

    // Display the final table
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
