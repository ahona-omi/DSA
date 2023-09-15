#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> path;
    set<vector<int>> cycles;

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
        path.push_back(node);

        for (int neighbor : adjList[node]) {
            if (neighbor == parent) {
                continue; // Skip the edge that leads back to the parent
            }
            if (!visited[neighbor]) {
                dfs(neighbor, node);
            } else if (find(path.begin(), path.end(), neighbor) != path.end()) {
                // Found a cycle
                vector<int> cycle;
                auto it = find(path.begin(), path.end(), neighbor);
                for (auto iter = it; iter != path.end(); ++iter) {
                    cycle.push_back(*iter);
                }
                cycle.push_back(neighbor); // Add the last node to complete the cycle
                cycles.insert(cycle);
            }
        }

        visited[node] = false;
        path.pop_back();
    }

    void findCycles() {
        int V = adjList.size();
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }
    }

    void printCycles() {
        for (const vector<int>& cycle : cycles) {
            cout << "Cycle: ";
            for (int node : cycle) {
                cout << node << " ";
            }
            cout << endl;
        }
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

    g.findCycles();
    g.printCycles();

    return 0;
}
