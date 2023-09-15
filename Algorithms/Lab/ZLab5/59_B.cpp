#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define INF 999

class Graph {
private:
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int V) {
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // Add this line for undirected graph
    }

    vector<vector<int>> floydWarshall() {
        int V = adjList.size();
        vector<vector<int>> dist(V, vector<int>(V, INF));

        // Initialize direct edge weights
        for (int i = 0; i < V; ++i) {
            dist[i][i] = 0;
            for (const auto& neighbor : adjList[i]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                dist[i][v] = min(dist[i][v], weight); // Store the minimum weight
            }
        }
        // Floyd-Warshall algorithm
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        return dist;
    }

    void printResult() {
        vector<vector<int>> allShortestPaths = floydWarshall();
        int V = adjList.size();
        int sum = 0;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (allShortestPaths[i][j] != INF) {
                    sum += allShortestPaths[i][j];
                } 
            } cout << sum << endl;
        }
        
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    Graph graph(N);

    for (int i = 0; i < M; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    graph.printResult();

    return 0;
}
