#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);
    int v1, v2;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        inDegree[v2]++;
    }
    // Topological Sort using Kahn's Algorithm
    vector<int> order;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int next : adj[node]) {
            inDegree[next]--; //remove edge
            if (inDegree[next] == 0) { //if v has zero in degree
                q.push(next);
            }
        }
    }
    // DP to find the maximum difference
    int maxi = 0;
    vector<int> minCost(n, 1e9);

    for (int u : order) {
        minCost[u] = min(minCost[u], c[u]);
        for (int v : adj[u]) {
            // อัพเดตค่า minCost ในการเดินทางไป node ถัดไป
            minCost[v] = min(minCost[v], minCost[u]);
            maxi = max(maxi, c[v] - minCost[v]);
        }
    }

    cout << maxi << endl;
}
