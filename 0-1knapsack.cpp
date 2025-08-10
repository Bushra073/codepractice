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
