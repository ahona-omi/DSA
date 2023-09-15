#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    vector<bool> vis;
    vector<bool> stack;

public:
    Graph(int V) {
        adjList.resize(V);
        vis.resize(V, false);
        stack.resize(V, false);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    bool isCyclicUtil(int curr) {
        vis[curr] = true;
        stack[curr] = true;

        for (int neighbor : adjList[curr]) {
            if (stack[neighbor]) { // cycle exists
                return true;
            } else if (!vis[neighbor] && isCyclicUtil(neighbor)) {
                return true;
            }
        }

        stack[curr] = false;
        return false;
    }

    // O(V + E)
    bool isCyclic() {
        int V=adjList.size();
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                bool cycle = isCyclicUtil(i);
                if (cycle) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int V = 4;
    Graph g(V);
    g.addEdge(0, 2);
    g.addEdge(3, 0);
    g.addEdge(1, 0);
    g.addEdge(2, 3);

    cout << (g.isCyclic() ? "True" : "False") << endl;

    return 0;
}
