#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of processes:";
    cin >> n;

    int p[100], at[100], bt[100];
    int ct[100], tat[100], wt[100];

    for(int i=0; i<n; i++){

        p[i] = i+1;
        cout << "Process P " << p[i] << endl;

        cout << "Arrival Time: ";
        cin >> at[i];
        cout << "Burst Time:";
        cin >> bt[i];
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(at[j] > at[j+1]){
                swap(at[j],at[j+1]);
                swap(bt[j],bt[j+1]);
                swap(p[j],p[j+1]);
            }
        }
    }

    ct[0] = at[0] + bt[0];
    for(int i=0; i<n; i++){
        if(ct[i-1] < at[i]){
            ct[i] = at[i] + bt[i];
        }
        else{
            ct[i] = ct[i-1] + bt[i];
        }
    }

    for(int i=0; i<n; i++){
        tat[i] = ct[i]- at[i];
        wt[i] = tat[i] - bt[i];
    }
    double avgTAT, avgWT;
    for(int i=0; i<n; i++){
        avgTAT += tat[i];
        avgWT += wt[i];
    }
    avgTAT = avgTAT/n;
    avgWT = avgWT/n;

    cout << "Average Turn Around Time: " << avgTAT << endl;
    cout << "Average Waiting Time: " << avgWT << endl;

    cout << "\nP\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0; i<n; i++){
        cout << "P" << p[i] << "\t"
                    << at[i] << "\t"
                    << bt[i] << "\t"
                    << ct[i] << "\t"
                    << tat[i] << "\t"
                    << wt[i] << endl;
    }
    return 0;
}
