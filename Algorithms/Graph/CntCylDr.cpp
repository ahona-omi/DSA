#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;

public:
    Graph(int V) {
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    vector<vector<int>> getAdjList() {
        return adjList;
    }
};

void findCyclesDFS(int current, int start, const vector<vector<int>> &graph, vector<int> &path, vector<bool> &visited, set<vector<int>> &cycles) {
    path.push_back(current);
    visited[current] = true;

    for (int neighbor : graph[current]) {
        if (neighbor == start) {
            path.push_back(start);
            cycles.insert(path);
        } else if (!visited[neighbor]) {
            findCyclesDFS(neighbor, start, graph, path, visited, cycles);
        }
    }

    visited[current] = false;
    path.pop_back();
}

void printAllCycles(const vector<vector<int>> &graph) {
    int V = graph.size();
    vector<bool> visited(V, false);
    set<vector<int>> cycles;

    for (int start = 0; start < V; ++start) {
        vector<int> path;
        findCyclesDFS(start, start, graph, path, visited, cycles);
    }

    for (const vector<int> &cycle : cycles) {
        for (int vertex : cycle) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;

    Graph graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    vector<vector<int>> adjList = graph.getAdjList();

    printAllCycles(adjList);

    return 0;
}
