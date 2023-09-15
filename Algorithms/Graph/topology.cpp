#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
    stack<int> topoStack;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void topologicalSort() {
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                DFS(i);
            }
        }

        // Print the topological order
        cout << "Topological Sort: ";
        while (!topoStack.empty()) {
            cout << topoStack.top() << " ";
            topoStack.pop();
        }
        cout << endl;
    }

    void DFS(int vertex) {
        visited[vertex] = true;

        for (int i = 0; i < adj[vertex].size(); ++i) {
            int adjacentVertex = adj[vertex][i];
            if (!visited[adjacentVertex]) {
                DFS(adjacentVertex);
            }
        }

        // Push the current vertex onto the stack when all its neighbors are visited
        topoStack.push(vertex);
    }
};

int main() {
    int n = 6, m;
    // cin >> n >> m;

    Graph g(n);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 1);
    g.addEdge(5, 2);

    cout << "Topological Sort: ";
    g.topologicalSort();

    return 0;
}
