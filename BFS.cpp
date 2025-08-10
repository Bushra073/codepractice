#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
bool visited[100] = {0};

void bfs(int start)
{
    queue<int>q;
    q.push(start);
    visited[start]=true;

    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for(int neighbour : adj[current])
        {
            if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}
int main()
{
    int n,m;
    cout << "Enter number of nodes and edges:";
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cout << "Enter the edges:";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
    cout << "Enter the starting node:";
    cin >> start;
    cout << "BFS Result:";
    bfs(start);
    cout << endl;
}
