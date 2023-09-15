#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int V) {
        this->V = V;
        adjList = vector<vector<pair<int, int>>>(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight)); // For an undirected graph, add the reverse edge as well.
    }

    int primAlgo() {
        vector<bool> vis(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));
        int cost = 0;

        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            int vertex = curr.second;
            int weight = curr.first;

            if (!vis[vertex]) {
                vis[vertex] = true;
                cost += weight;

                for (const auto& neighbor : adjList[vertex]) {
                    int dest = neighbor.first;
                    int wt = neighbor.second;
                    if (!vis[dest]) {
                        pq.push(make_pair(wt, dest));
                    }
                }
            }
        }
        return cost;
    }
};

int main() {
    int V = 4;
    Graph graph(V);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    int mstCost = graph.primAlgo();
    cout << "Minimum Spanning Tree Cost: " << mstCost << endl;
    return 0;
}
