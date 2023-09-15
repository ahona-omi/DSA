#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int V) {
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
    }

    int size() const {
        return adjList.size();
    }

    vector<int> bellmanFord(int src) {
        vector<int> dist(size(), INT_MAX);
        dist[src] = 0;

        for (int i = 0; i < size() - 1; ++i) {
            for (int u = 0; u < size(); ++u) {
                for (const auto& neighbor : adjList[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        return dist;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Graph graph(N);

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    int Q;
    cin >> Q;

    vector<int> dist;

    for (int i = 0; i < Q; ++i) {
        int X, Y;
        cin >> X >> Y;

        dist = graph.bellmanFord(X);

        if (dist[Y] == INT_MAX) {
            cout << "Impossible" << endl;
        } else {
            cout << dist[Y] << endl;
        }
    }

    return 0;
}
