#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> path;

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void printCycles() {
        for (int i = 0; i < V; ++i) {
            dfs(i, i, 0);
            visited[i] = true;
            path.pop_back();
        }
    }

    void dfs(int start, int curr, int depth) {
        if (depth != 0 && curr == start) {
            // A cycle is found
            cout << "Cycle: ";
            for (int node : path) {
                cout << node << " ";
            }
            cout << start << endl;
            return;
        }

        if (visited[curr] || depth >= V) {
            return;
        }

        visited[curr] = true;
        path.push_back(curr);

        for (int neighbor : adjList[curr]) {
            dfs(start, neighbor, depth + 1);
        }

        visited[curr] = false;
        path.pop_back();
    }
    
};

int main() {
    int V = 4;
    Graph g(V);
    g.addEdge(0, 2);
    g.addEdge(3, 0);
    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    g.printCycles();

    return 0;
}
