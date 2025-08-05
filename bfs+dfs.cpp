#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
bool visited[100]={0};

 void bfs(int start)
 {
     queue<int>q;
     q.push(start);
     visited[start]=true;
     cout << "BFS Result: ";


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
                 visited[neighbour]=true;
             }
         }
     }
     cout << endl;
 }
 void dfs(int start)
 {
     stack<int>s;
     s.push(start);
     visited[start]=true;
     cout << "DFS Result: ";


     while(!s.empty())
     {
         int current = s.top();
         s.pop();
         cout << current << " ";

         for(int neighbour : adj[current])
         {
             if(!visited[neighbour])
             {
                 s.push(neighbour);
                 visited[neighbour]=true;
             }
         }
     }
     cout << endl;
 }
 int main()
 {
     int n,m;
     cout << "Enter number of nodes and edges: ";
     cin >> n >> m;

     cout << "Enter the edges: ";
     for(int i=0; i<m; i++)
     {
         int u,v;
         cin >> u >> v;
         adj[u].push_back(v);
         adj[v].push_back(u);
     }
     int start;
     cout << "Enter the starting node: ";
     cin >> start;
     bfs(start);
     fill(visited, visited+100, false);
     dfs(start);
 }
