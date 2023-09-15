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
        //adjList[v].emplace_back(u, weight);
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
                dist[i][v] = weight;
                //dist[v][i] = weight;
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

    void printResult(){
        vector<vector<int>> allShortestPaths = floydWarshall();
        int V=adjList.size();
        cout << "Shortest paths between vertices:" << endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (allShortestPaths[i][j] == INF)    cout << "INF";
                else    cout << allShortestPaths[i][j];
                if (j != V - 1)    cout << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    int V = 4;
    Graph graph(V);

    graph.addEdge(0, 1, 3);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 0, 2);
    graph.addEdge(1, 3, 4);
    graph.addEdge(3, 2, 2);
    graph.addEdge(2, 1, 1);

    graph.printResult();

    return 0;
}
