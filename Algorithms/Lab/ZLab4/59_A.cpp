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
        adjList[v].emplace_back(u, weight); // For an undirected graph, add the reverse edge as well.
    }

    vector<pair<int, int>>& getAdjList(int u) { return adjList[u]; }

    int size() const { return adjList.size(); }

    vector<int> dijkstra(int src, vector<int>& parent) {
        vector<int> dist(size(), -1); // Initialize distances to -1 (unreachable)
        dist[src] = 0;
        parent[src] = -1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, src);

        while (!pq.empty()) {
            int u = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            if (distance > dist[u]) continue; // Skip outdated entries in the priority queue

            for (const auto& neighbor : getAdjList(u)) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v] || dist[v] == -1) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u; // Update parent
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    }
    void print(int src) {
        int V = adjList.size();
        vector<int> parent(V, -1); // To store parent nodes
        vector<int> dist = dijkstra(src, parent);

        for (int i = 0; i < parent.size(); ++i)
            cout << i << " : " << dist[i] << endl;
    }
};

int main() {
    // int n,m;
    // cin>>n>>m;
    int n = 7;
    Graph g(n);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 2, 5);
    g.addEdge(3, 2, 1);
    g.addEdge(3, 4, 50);
    g.addEdge(2, 5, 10);

    // for(int i=0;i<m;i++){
    //     int x,y,w;
    //     g.addEdge(x,y,w);
    // }
    int src = 0;
    g.print(src);

    return 0;
}
