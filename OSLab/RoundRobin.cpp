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
        // Give process numbers P1, P2, P3...
        p[i] = i + 1;

        cout << "\nProcess P" << p[i] << endl;

        cout << "Arrival Time: ";
        cin >> at[i];

        cout << "Burst Time: ";
        cin >> bt[i];

        // Initially Remaining Time is equal to Burst Time.
        rt[i] = bt[i];
    }

    // Arrange the processes according to Arrival Time.
    // This allows the code to work even if the question
    // gives the processes in a random order.
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            // If the current process arrives later
            // than the next process, swap them.
            if(at[j] > at[j + 1])
            {
                // Swap Arrival Time.
                swap(at[j], at[j + 1]);

                // Swap Burst Time so it stays with its process.
                swap(bt[j], bt[j + 1]);

                // Swap Process Number.
                swap(p[j], p[j + 1]);

                // Swap Remaining Time as well.
                swap(rt[j], rt[j + 1]);
            }
        }
    }

    // Create a queue to store the indexes of processes.
    queue<int> q;

    // Current CPU time.
    int time = 0;

    // Counts how many processes have finished.
    int completed = 0;

    // Stores the index of the next process
    // that has not yet been added to the queue.
    int next = 0;

    // If the first process does not arrive at time 0,
    // move the CPU time to its arrival time.
    if(at[0] > time)
    {
        time = at[0];
    }

    // Put the first process into the queue.
    q.push(0);

    // The next process to check is index 1.
    next = 1;

    // Keep running while there are processes in the queue.
    while(!q.empty())
    {
        // Take the process from the front of the queue.
        int i = q.front();

        // Remove it from the queue because it is now using the CPU.
        q.pop();

        // If the process needs more than one Time Quantum.
        if(rt[i] > tq)
        {
            // CPU runs for one Time Quantum.
            time += tq;

            // Reduce the Remaining Time by Time Quantum.
            rt[i] -= tq;
        }

        // Otherwise, the process can finish in this turn.
        else
        {
            // CPU runs only for the remaining time.
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

        // Check for processes that have arrived while
        // the current process was running.
        while(next < n && at[next] <= time)
        {
            // Add the newly arrived process to the queue.
            q.push(next);

            // Move to the next process.
            next++;
        }

        // If the current process is not finished,
        // send it to the back of the queue.
        if(rt[i] > 0)
        {
            q.push(i);
        }

        // If the queue is empty but there are still
        // processes that have not arrived yet.
        if(q.empty() && next < n)
        {
            // Move CPU time to the next arrival time.
            time = at[next];

            // Put that process into the queue.
            q.push(next);

            // Move to the next process.
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

    // Variables for average Turnaround Time and Waiting Time.
    double avgTAT = 0, avgWT = 0;

    // Add all TAT and WT values.
    for(int i = 0; i < n; i++)
    {
        avgTAT += tat[i];
        avgWT += wt[i];
    }

    // Calculate the averages.
    avgTAT = avgTAT / n;
    avgWT = avgWT / n;

    // Print the average values.
    cout << "\nAverage Turnaround Time = " << avgTAT << endl;
    cout << "Average Waiting Time = " << avgWT << endl;

    return 0;
}