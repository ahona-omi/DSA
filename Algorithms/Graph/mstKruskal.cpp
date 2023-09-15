#include <bits/stdc++.h>
using namespace std;

class disjointSet {
private:
    vector<int> parent, rank;

public:
    disjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int find(int v) {
        if (parent[v] == v) return v;
        // path compression->O(log n)
        return parent[v] = find(parent[v]);
    }
    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;

            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};

class Graph {
private:
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int V) {
        adjList.resize(V);
    }

    // function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight)); // For an undirected graph, add the reverse edge as well.
    }

    void kruskalMST() {
        vector<pair<int, pair<int, int>>> edges; // (weight, (u, v))
        int V = adjList.size();

        for (int u = 0; u < V; ++u) {
            for (auto edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                edges.push_back({weight, {u, v}});
            }
        }

        sort(edges.begin(), edges.end());

        disjointSet ds(V);
        int totalWeight = 0;
        for (auto edge : edges) {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            if (ds.find(u) != ds.find(v)) {
                ds.Union(u, v);
                totalWeight += weight;
                cout << "Edge: " << u << " --> " << v << " : " << weight << endl;
            }
        }

        cout << "Total MST Weight: " << totalWeight << endl;
    }
};

int main() {
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1, 10);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}
