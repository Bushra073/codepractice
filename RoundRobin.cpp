#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes: " ;
    cin >> n;

    int tq;
    cout << "Enter Time Quantum: ";
    cin >> tq;

    int p[100], at[100], bt[100], rt[100];
    int ct[100], tat[100], wt[100];

    for(int i=0; i<n; i++)
    {

        p[i] = i+1;
        cout << "Process p" << p[i] << endl;

        cout << "Arrival Time: ";
        cin >> at[i];
        cout << "Burst Time: " ;
        cin >> bt[i];
        rt[i] = bt[i];
    }

    queue<int>q;
    int time = 0;
    int completed =0;
    int next = 0;
    q.push(0);
    next =1;

    while(!q.empty())
    {

        int i = q.front();
        q.pop();
        if(rt[i] > 0 )
        {
            time += tq;
            rt[i] -= tq;
        }
        else
        {
            time += rt[i];
            rt[i] = 0;
            ct[i] = time;
            completed++ ;
            tat[i] = ct[i]-at[i];
            wt[i] = tat[i]-bt[i];
        }

        while(next < n && at[next] <= time)
        {
            q.push(next);
            next++ ;
        }
        if(rt[i]>0)
        {
            q.push(i);
        }
        if(q.empty() && next < n)
        {
            time = at[next];
            q.push(next);
            next++ ;
        }
    }



    double avgTAT =0, avgWT = 0;
    for(int i=0; i<n; i++)
    {

        avgTAT += tat[i];
        avgWT += wt[i];
    }
    avgTAT = avgTAT/n;
    avgWT = avgWT/n;
    cout << "Average TAT = " << avgTAT << endl;
    cout << "Average WT = " << avgWT << endl;

    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i =0; i<n; i++)
    {

        cout << "P" << p[i] << "\t"
             <<at[i] << "\t"
             <<bt[i] << "\t"
             <<ct[i] << "\t"
             <<tat[i] << "\t"
             <<wt[i] << endl;
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Take the number of processes from the user.
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    // Take the Time Quantum.
    int tq;
    cout << "Enter Time Quantum: ";
    cin >> tq;

    // Declare all necessary arrays.
    int p[100], at[100], bt[100];
    int rt[100], ct[100], tat[100], wt[100];

    // Take Arrival Time and Burst Time of every process.
    for(int i = 0; i < n; i++)
    {
        p[i] = i + 1;

        cout << "\nProcess P" << p[i] << endl;

        cout << "Arrival Time: ";
        cin >> at[i];

        cout << "Burst Time: ";
        cin >> bt[i];

        // Initially Remaining Time = Burst Time.
        rt[i] = bt[i];
    }

    // Create a queue to store the indexes of processes.
    queue<int> q;

    // Current CPU time.
    int time = 0;

    // Counts how many processes have finished.
    int completed = 0;

    // Stores the index of the next process that has not yet been added to the queue.
    int next = 0;

    // Put the first process into the queue.
    q.push(0);

    // The next process to check is P2 (index 1).
    next = 1;

    // Keep running until the queue becomes empty.
    while(!q.empty())
    {
        // Take the process from the front of the queue.
        int i = q.front();

        // Remove it from the queue because it is now using the CPU.
        q.pop();

        // If the process cannot finish within one Time Quantum.
        if(rt[i] > tq)
        {
            // CPU runs for one Time Quantum.
            time += tq;

            // Reduce the Remaining Time.
            rt[i] -= tq;
        }

        // Otherwise, the process finishes.
        else
        {
            // CPU runs for the remaining time only.
            time += rt[i];

            // No work is left.
            rt[i] = 0;

            // Store Completion Time.
            ct[i] = time;

            // Calculate Turnaround Time.
            tat[i] = ct[i] - at[i];

            // Calculate Waiting Time.
            wt[i] = tat[i] - bt[i];

            // One more process has finished.
            completed++;
        }

        // Add all newly arrived processes into the queue.
        while(next < n && at[next] <= time)
        {
            q.push(next);
            next++;
        }

        // If the current process is not finished,
        // send it to the back of the queue.
        if(rt[i] > 0)
        {
            q.push(i);
        }

        // If the queue becomes empty but there are still
        // processes that have not arrived yet,
        // jump the CPU time to the next arrival.
        if(q.empty() && next < n)
        {
            time = at[next];

            q.push(next);

            next++;
        }
    }

    // Print the final scheduling table.
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

    // Calculate average Turnaround Time and Waiting Time.
    double avgTAT = 0, avgWT = 0;

    for(int i = 0; i < n; i++)
    {
        avgTAT += tat[i];
        avgWT += wt[i];
    }

    avgTAT = avgTAT / n;
    avgWT = avgWT / n;

    cout << "\nAverage Turnaround Time = " << avgTAT << endl;
    cout << "Average Waiting Time = " << avgWT << endl;

    return 0;
}
