#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cout << "Enter no. of processes: ";
    cin >> n;
     cout << "Enter no. of resources: ";
    cin >> m;

    int alloc[100][100];
    int max[100][100];
    int need [100][100];
    int avail[100];

    cout << "\nEnter Allocation Matrix:\n " ;
    for(int i=0; i<n; i++){
        cout << "P" << i << ": ";
        for(int j=0; j<m; j++){
            cin >> alloc[i][j];
        }
    }
    cout << "\nEnter Maximum Matrix:\n " ;

    for(int i=0; i<n; i++)
        {
        cout << "P" << i << ": ";

        for(int j=0; j<m; j++)
            {
            cin >> max [i][j];
        }
    }
    cout << "\nEnter Available Resources:\n " ;
    for(int j=0; j<m; j++){
        cin >> avail[j];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    bool finish[100] = {false};
    int safeSequence[100];
    int count = 0;

    while(count < n){

        bool found = false;
        for(int i=0; i<n; i++){

            if (finish[i] == false){
                bool possible = true;
                for(int j=0; j<m; j++){
                    if(need[i][j]>avail[j]){
                        possible = false;
                        break;
                    }
                }
                if(possible == true){

                    for(int j=0; j<m; j++){
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = true;
                    safeSequence[count] = i;
                    found = true;
                    count ++;
                }
            }
        }
        if(found == false){
            break;
        }
    }

    if(count == n){

        cout << "System is safe" << endl;

        cout << "Safe Sequence: ";

        for(int i=0; i<n; i++){
            cout << "P" << safeSequence[i];
        }
    }

    else {
        cout << "System is UNSAFE " << endl;
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Take the number of processes.
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    // Take the number of resource types.
    int m;
    cout << "Enter number of resources: ";
    cin >> m;

    // Declare the required arrays.
    // alloc = resources currently allocated to each process.
    // max = maximum resources each process may need.
    // need = remaining resources each process needs.
    // avail = resources currently available.
    int alloc[100][100];
    int max[100][100];
    int need[100][100];
    int avail[100];

    // Take the Allocation Matrix.
    cout << "\nEnter Allocation Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << i << ": ";

        for(int j = 0; j < m; j++)
        {
            cin >> alloc[i][j];
        }
    }

    // Take the Maximum Matrix.
    cout << "\nEnter Maximum Matrix:\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << i << ": ";

        for(int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }

    // Take the Available Resources.
    cout << "\nEnter Available Resources:\n";

    for(int j = 0; j < m; j++)
    {
        cin >> avail[j];
    }

    // Calculate Need.
    // Need = Maximum - Allocation.
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // finish[i] tells whether process i has finished.
    // Initially, no process has finished.
    bool finish[100] = {false};

    // Stores the order in which processes can safely finish.
    int safeSequence[100];

    // Counts how many processes have finished.
    int count = 0;

    // Keep checking until all processes are finished.
    while(count < n)
    {
        // At the beginning of each round,
        // we have not found any process yet.
        bool found = false;

        // Check every process.
        for(int i = 0; i < n; i++)
        {
            // Only check processes that have not finished.
            if(finish[i] == false)
            {
                // Assume this process can finish.
                bool possible = true;

                // Check every resource for this process.
                for(int j = 0; j < m; j++)
                {
                    // If the process needs more resources
                    // than are currently available,
                    // it cannot finish right now.
                    if(need[i][j] > avail[j])
                    {
                        possible = false;

                        // No need to check the remaining resources.
                        break;
                    }
                }

                // If the process can get all the resources it needs.
                if(possible == true)
                {
                    // The process finishes and returns
                    // the resources it was holding.
                    for(int j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j];
                    }

                    // Mark this process as finished.
                    finish[i] = true;

                    // Store this process in the safe sequence.
                    safeSequence[count] = i;

                    // Increase the number of completed processes.
                    count++;

                    // We found a process that could finish.
                    found = true;
                }
            }
        }

        // If no process could finish in this round,
        // the remaining processes cannot proceed.
        if(found == false)
        {
            break;
        }
    }

    // If all processes finished, the system is safe.
    if(count == n)
    {
        cout << "\nSystem is SAFE.\n";

        // Print the safe sequence.
        cout << "Safe Sequence: ";

        for(int i = 0; i < n; i++)
        {
            cout << "P" << safeSequence[i];

            // Print an arrow between processes,
            // but not after the last process.
            if(i != n - 1)
            {
                cout << " -> ";
            }
        }

        cout << endl;
    }

    // If all processes did not finish,
    // the system is unsafe.
    else
    {
        cout << "\nSystem is UNSAFE.\n";
    }

    return 0;
}