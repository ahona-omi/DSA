#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

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

    void floydWarshall(vector<vector<int>> &dist) {
        int V = adjList.size();
        
        for (int i = 0; i < V; ++i) {
            dist[i][i] = 0;
            for (const auto& neighbor : adjList[i]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                dist[i][v] = weight;
                dist[v][i] = weight;
            }
        }
        
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
    
};

int main() {
    int N, M;
    cin >> N >> M;

    Graph graph(N);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    int R;
    cin >> R;

    vector<int> order(R);
    for (int i = 0; i < R; i++) {
        cin >> order[i];
    }

    vector<vector<int>> dist(N, vector<int>(N, INF));
    graph.floydWarshall(dist);

    int totalDistance = 0;

    for (int i = 1; i < R; i++) {
        int start = order[i - 1];
        int end = order[i];
        int distance = dist[start][end];

        if (distance == INF) {
            cout << "infinity\n";
            return 0;
        }

        totalDistance += distance;
    }

    cout << totalDistance << endl;

    return 0;
}
