#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of processes: " ;
    cin >> n;

    int p[100],at[100],bt[100];
    int ct[100], tat[100], wt[100];

    for(int i=0; i<n; i++){

        p[i]= i+1;
      cout << "\nProcess P" << p[i] << endl;

        cout << "Arrival Time: ";
        cin >> at[i];
        cout << "Burst Time: ";
        cin >> bt[i];
    }

    ct[0] = at[0] + bt[0];

    for(int i=1; i<n; i++){

        if(ct[i-1] < at[i]){

            ct[i] = at[i] + bt[i];
            }
        else{
            ct[i] = ct[i-1] + bt[i];
        }
    }

    for(int i=0; i<n; i++){
        tat[i] = ct[i] -at[i];
        wt [i]= tat[i]-bt[i];
    }

    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i=0; i<n; i++){

        cout << "p" << p[i] << "\t"
             << at[i] << "\t"
              << bt[i] << "\t"
               << ct[i] << "\t"
                << tat[i] << "\t"
                 << wt[i] << endl;

    }

    return 0;



}



#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Take the number of processes.
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    // Declare arrays.
    int p[100], at[100], bt[100];
    int ct[100], tat[100], wt[100];

    // Take process information.
    for(int i = 0; i < n; i++)
    {
        p[i] = i + 1;

        cout << "\nProcess P" << p[i] << endl;

        cout << "Arrival Time: ";
        cin >> at[i];

        cout << "Burst Time: ";
        cin >> bt[i];
    }

    // Arrange processes according to Arrival Time.
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(at[j] > at[j + 1])
            {
                swap(at[j], at[j + 1]);
                swap(bt[j], bt[j + 1]);
                swap(p[j], p[j + 1]);
            }
        }
    }

    // Calculate Completion Time.
    ct[0] = at[0] + bt[0];

    for(int i = 1; i < n; i++)
    {
        // If CPU is idle until this process arrives.
        if(ct[i - 1] < at[i])
        {
            ct[i] = at[i] + bt[i];
        }
        else
        {
            ct[i] = ct[i - 1] + bt[i];
        }
    }

    // Calculate TAT and WT.
    for(int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Print the final table.
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

    // Calculate average TAT and WT.
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