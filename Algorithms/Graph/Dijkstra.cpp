#include <bits/stdc++.h>
using namespace std;
//O(E+E.logV)
class Graph {
private:
    vector<vector<pair<int, int>>> adjList;
    vector<int> parent;

public:
    Graph(int V) {
        adjList.resize(V);
        parent.resize(V, -1);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight); // For an undirected graph, add the reverse edge as well.
    }

    vector<pair<int, int>>& getAdjList(int u)       {return adjList[u];}

    int size() const    {return adjList.size();}

    vector<int> dijkstra(int src) {
        vector<int> dist(size(), numeric_limits<int>::max());
        dist[src] = 0;
        parent[src] = -1;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, src);

        while (!pq.empty()) {
            int u = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            if (distance > dist[u])     continue; // Skip outdated entries in the priority queue

            for (const auto& neighbor : getAdjList(u)) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u; // Update parent
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    }
    void print(int src){
        int V=adjList.size();
        vector<int> dist = dijkstra(src);

        for (int i = 1; i < parent.size(); ++i)
            cout << "The minimum distance from 0 to " << i << " = " << dist[i] << endl;
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
    graph.print(src);

    return 0;
}
