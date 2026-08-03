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

