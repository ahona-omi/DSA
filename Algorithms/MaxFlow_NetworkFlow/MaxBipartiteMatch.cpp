//Maximum Bipartite matching by Edmonds-Karp algorithm

#include <bits/stdc++.h>
using namespace std;

// Edge of a flow network
struct Edge {
    int u, v;
    int capacity;
    int flow;
};

// Edmonds-Karp algorithm to find the maximum flow
int Edmonds_Karp(vector<vector<Edge>>& G, int s, int t) {
    int V = G.size();
    vector<vector<int>> res_capacity(V, vector<int>(V, 0)); // Residual capacity

    // Initialize the residual capacity graph
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            res_capacity[u][v] = G[u][v].capacity;
        }
    }

    int max_flow = 0;

    // Perform BFS to find augmenting paths in the residual network
    while (true) {
        vector<int> parent(V, -1);
        queue<int> q;
        q.push(s);
        parent[s] = s;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < V; v++) {
                if (parent[v] == -1 && res_capacity[u][v] > 0) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        // If there is no augmenting path, break out of the loop
        if (parent[t] == -1) {
            break;
        }

        int path_flow = INT_MAX;
        int curr = t;

        // Find the minimum capacity on the augmenting path
        while (curr != s) {
            int u = parent[curr];
            path_flow = min(path_flow, res_capacity[u][curr]);
            curr = u;
        }

        // Update the residual capacities and reverse edges along the augmenting path
        curr = t;
        while (curr != s) {
            int u = parent[curr];
            res_capacity[u][curr] -= path_flow;
            res_capacity[curr][u] += path_flow;
            curr = u;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int V, E;  // Number of vertices, number of edges
    cin >> V >> E;

    // Create a graph with V and initialize edges
    vector<vector<Edge>> G(V, vector<Edge>(V, {0, 0, 0}));

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        // Set the capacity to 1 for unweighted bipartite matching
        G[u][v] = {u, v, 1, 0};
    }

    // In a bipartite graph, you have two disjoint sets, let's assume one set is [0, n1) and the other [n1, V)
    int s = 0;
    int t = V - 1;

    int max_matching = Edmonds_Karp(G, s, t);
    cout << "\nMaximum Bipartite Matching: " << max_matching << endl<<endl;

    return 0;
}


/*


8 12

0 1
0 2
0 3
1 4
1 5
1 6
2 5   
3 5
3 6
4 7
5 7
6 7


Maximum Bipartite Matching: 3

*/
