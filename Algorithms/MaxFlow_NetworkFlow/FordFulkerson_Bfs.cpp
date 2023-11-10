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

        while (bfs(rGraph, s, t, parent)) {
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

    bool bfs(const vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
        vector<bool> visited(V, false);

        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < V; v++) {
                if (!visited[v] && rGraph[u][v] > 0) {
                    if (v == t) {
                        parent[v] = u;
                        return true;
                    }
                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
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
