#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[100][100];
    int max[100][100];
    int need[100][100];
    int avail[100];

    cout <<"Enter Allocation Matrix: " << endl;
    for(int i=0; i<n; i++){
        cout << "P" << i << ": ";

        for(int j=0; j<m; j++){
            cin >> alloc[i][j];
        }
    }
    cout << "Enter Maximum Matrix: " << endl;
    for(int i=0; i<n; i++){
        cout << "P" << i << ": ";
        for(int j=0; j<m; j++){
            cin >> max[i][j];
        }
    }
    cout << "Enter Available Resources: " << endl;
    for(int j=0; j<m; j++){
        cin >> avail[j];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            need[i][j] = max[i][j]- alloc[i][j];
        }
    }
    bool finish[100] = {false};
    int safeSequence[100];
    int count = 0;

    while(count<n){
        bool found = false;

        for(int i=0; i<n; i++){

            if(ifinish[i] == false){
                bool possible = true;

                for(int j=0; j<m; j++){
                    if(need[i][j] > avail[j]){
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
                    count ++ ;
                    found = true;
                }
            }
        }
    }














}
