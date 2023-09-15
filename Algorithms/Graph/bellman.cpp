#include <bits/stdc++.h>
using namespace std;
//O(V.E)
class Graph {
private:
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int V) {
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }

    int size() const {
        return adjList.size();
    }

    vector<int> bellmanFord(int src) {
        vector<int> dist(size(), INT_MAX);
        dist[src] = 0;

        for (int i = 0; i < size() - 1; ++i) {
            for (int u = 0; u < size(); ++u) {      //all nodes
                for (const auto& neighbor : adjList[u]) {       //nodes' neighbor
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        // Check for negative cycles-distance negetaive hotei thakbe for each loop
        for (int u = 0; u < size(); ++u) {
            for (const auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    cout << "Graph contains negative weight cycle." << endl;
                    exit(0);
                }
            }
        }

        return dist;
    }
};

int main() {
    int V = 9;
    Graph graph(V);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(1, 2, 8);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 3, 9);
    graph.addEdge(4, 5, 10);
    graph.addEdge(6, 5, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);

    int src = 0;
    vector<int> dist = graph.bellmanFord(src);

    cout << "Output:" << endl;
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "0 to " << i << " is unreachable" << endl;
        } else {
            cout << "0 to " << i << " is " << dist[i] << endl;
        }
    }

    return 0;
}
