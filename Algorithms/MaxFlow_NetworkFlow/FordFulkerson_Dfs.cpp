#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> graph;

public:
    Graph(int V) {
        this->V = V;
        graph = vector<vector<int>>(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int weight) {
        graph[u][v] = weight;
    }

    int fordFulkerson(int s, int t) {
        vector<vector<int>> rGraph = graph;

        vector<int> parent(V);
        int max_flow = 0;

        while (dfs(rGraph, s, t, parent)) {
            int path_flow = INT_MAX;
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                path_flow = min(path_flow, rGraph[u][v]);
            }

            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                rGraph[u][v] -= path_flow;
                rGraph[v][u] += path_flow;
            }

            max_flow += path_flow;
        }

        return max_flow;
    }

    bool dfs(const vector<vector<int>>& rGraph, int u, int t, vector<int>& parent) {
        vector<bool> visited(V, false);
        return dfsHelper(rGraph, u, t, parent, visited);
    }

    bool dfsHelper(const vector<vector<int>>& rGraph, int u, int t, vector<int>& parent, vector<bool>& visited) {
        visited[u] = true;

        if (u == t) {
            return true;
        }

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                parent[v] = u;
                if (dfsHelper(rGraph, v, t, parent, visited)) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u < V && v < V) g.addEdge(u, v, w);
    }

    cout << "The maximum possible flow is " << g.fordFulkerson(0, 5);

    return 0;
}


//time complexity- O(f*E)
//space complexity- O(E+V)