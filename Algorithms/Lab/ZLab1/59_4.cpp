#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    vector<bool> visited;
    bool hasCycle = false;

public:
    Graph(int V) {
        adjList.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(int node, int parent) {
        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor])
                dfs(neighbor, node);
            else if (neighbor != parent)
                hasCycle = true; 
        }
    }

    void runDFS() {
        int V = adjList.size();
        for (int i = 0; i < V; i++) {
            if (!visited[i])    dfs(i, -1);
        }
    }

    void printResults() {
        if (hasCycle)     cout << "Yes\n";
        else     cout << "No\n";
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.runDFS();
    g.printResults();

    return 0;
}
