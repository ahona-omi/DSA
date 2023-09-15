#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
	vector<int> path;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void getPaths(int src, int dest) {
        path.push_back(src);
        DFS(src, dest);
    }

    void DFS(int vertex, int dest) {
        visited[vertex] = true;
        if (vertex == dest) {
            // Print the path
            for (int v : path) {
                cout << v << " ";
            }
            cout << endl;
        } else {
            for (int i = 0; i < adj[vertex].size(); ++i) {
                int x = adj[vertex][i];
                if (!visited[x]) {
                    path.push_back(x);
                    DFS(x, dest);
                    path.pop_back(); // Backtrack
                }
            }
        }

        visited[vertex] = false; // Reset visited for backtracking
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(5, 4);
    g.addEdge(3, 5);
    g.addEdge(5, 6);

    int source = 0;
    int destination =5;

    cout << "All Paths from " << source << " to " << destination << ":\n";
    g.getPaths(source, destination);

    return 0;
}
