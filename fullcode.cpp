#include <bits/stdc++.h>
using namespace std;

//Graph storing
#define sz 2000000
vector<int> adj[sz], cost[sz];
int visited[sz];//visited is a fixed-size array (like a checklist) that keeps track of which nodes have already been added to the MST.

//priority queue for smallest edge
// priority_queue<
//     T [1: Type of elements stored]
//     Container[2: How we store them internally]
//     Compare [3: How we compare them]
// > name;
//priority_queue<int, vector<int>, greater<int>> pq;
//A pair is a simple container in C++ that holds two values of possibly different types.
// pair<int, pair<int,int>> bigPair;
// bigPair.first → an int (the cost)
// bigPair.second → another pair<int,int> (two nodes)

priority_queue<
    pair<int, pair<int,int>>,//elements..cost,(fromNode,toNode)
    vector<pair<int, pair<int,int>>>,//storing inside a container using vector
    greater<pair<int, pair<int,int>>>//pop the smallest one(min-heap)
> pq;

//prims Algo
int prims(int start)
{
    //pushing all edges from starting node priority

    // Use a loop with an index i to go through adj[start].
    // Use the same index i to access the corresponding cost in cost[start].
    // Push the edge (cost, start, neighbor) into the priority queue.
    for(int i=0; i< (int)adj[start].size(); i++)
    {
        int neighbour = adj[start][i];
        int edgecost = cost[start][i];
        pq.push({edgecost,{start,neighbour}});
    }
    visited[start]=1;
    vector<pair<int,pair<int,int>>> mstEdges; //mstEdges is a dynamic array (vector) that stores the edges selected in the MST along with their costs and the two nodes they connect.
    int totalCost=0;

    while(!pq.empty())
    {
        //declaring a variable named topElement and assigning it a value from the priority queue's top element.pair<int, pair<int,int>> is the data type (a pair whose first element is an int, and second element is another pair of two ints)
        //declaring a variable named topElement of type pair<int, pair<int,int>> and initializing it with the value returned by pq.top().
        pair<int,pair<int,int>> topElement = pq.top();
        int edgecost = topElement.first;
        pair<int,int> nodes = topElement.second;
        int u = nodes.first;
        int v = nodes.second;
        pq.pop();

        //  The condition if (!visited[u] || !visited[v]) ensures the edge connects the MST to at least one new node.
        // Then int newNode = visited[u] ? v : u; picks the node not yet visited (not yet in MST).
        // We add newNode to MST by marking it visited (visited[newNode] = 1;).
        if(!visited[u] || !visited[v])
        {
            mstEdges.push_back({edgecost,{u,v}});
            totalCost += edgecost;
            int newNode = visited[u] ? v : u;
            visited[newNode] = 1;
            for(int i=0; i < (int) adj[newNode].size(); i++)
            {
                int neighbour = adj[newNode][i];
                int edgecost = cost[newNode][i];
                if(!visited[neighbour])
                {
                    pq.push({edgecost,{newNode,neighbour}});
                }
            }
        }
        cout << "\nEdges in MST:\n";
        for (size_t i = 0; i < mstEdges.size(); i++) {
            pair<int, pair<int,int>> edgeInfo = mstEdges[i];
            int costVal = edgeInfo.first;
            int u = edgeInfo.second.first;
            int v = edgeInfo.second.second;

            cout << u << " - " << v << "  (cost: " << costVal << ")\n";
        }
    }
    return totalCost;
}
int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back(y);
        cost[x].push_back(w);
        adj[y].push_back(x);
        cost[y].push_back(w);
    }

    int start;
    cin >> start;

    cout << "\nTotal Cost of MST = " << prims(start) << "\n";
    return 0;
}


//0-1 knapsack
#include <bits/stdc++.h>
using namespace std;

// Define an item with name, weight, and price
struct item {
    string name;
    int weight;
    int price;
};

int main() {
    int n, cap;
    cout << "Enter number of items and capacity:";
    cin >> n >> cap;  // Number of items and knapsack capacity
    cout << "Enter name,weight,price:" << endl;
    vector<item> a(n); // Vector to store items

    // Input each item's name, weight, and price
    for (int i = 0; i < n; i++) {
        cin >> a[i].name >> a[i].weight >> a[i].price;
    }

    // Create DP table: rows = items (0 to n), columns = capacities (0 to cap)
    vector<vector<int>> arr(n + 1, vector<int>(cap + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cap; j++) {
            if (j >= a[i - 1].weight) {
                // Item fits: max of skipping or taking the item
                arr[i][j] = max(
                    arr[i - 1][j],                                  // Skip current item
                    arr[i - 1][j - a[i - 1].weight] + a[i - 1].price  // Take current item
                );
            } else {
                // Item doesn't fit: skip it
                arr[i][j] = arr[i - 1][j];
            }
        }
    }

    // Output the maximum price achievable with all items and full capacity
    cout << arr[n][cap] << endl;

    // Backtrack to find which items were selected
    int val = arr[n][cap];
    int i = n, j = cap;

    cout << "Selected items:" << endl;

    while (i > 0 && val > 0) {
        if (val == arr[i - 1][j]) {
            // Item i-1 not taken, move to previous item
            i--;
        } else {
            // Item i-1 taken
            cout << a[i - 1].name << endl;
            val -= a[i - 1].price;       // Decrease remaining value
            j -= a[i - 1].weight;        // Decrease remaining capacity
            i--;
        }
    }

    return 0;
}
