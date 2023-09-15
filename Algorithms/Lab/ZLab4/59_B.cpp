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
        adjList[v].emplace_back(u, weight);
    }

    vector<pair<int, int>>& getAdjList(int u) { 
        return adjList[u]; 
    }

    int size() const { 
        return adjList.size(); 
    }

    vector<int> dijkstra(int src, vector<int>& parent) {
        vector<int> dist(size(), numeric_limits<int>::max());
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

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u; // Update parent
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    }
    
    void printShortestPath(int src, int dest) {
        int V = adjList.size();
        vector<int> parent(V, -1); // To store parent nodes
        vector<int> dist = dijkstra(src, parent);
        
        if (dist[dest] == numeric_limits<int>::max()) {
            cout << "NOT REACHABLE" << endl;
            return;
        }
        
        vector<int> path;
        int curr = dest;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        
        reverse(path.begin(), path.end());
        
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " ";
            }cout << endl;
        }
        
    }
};

int main() {
    
    // int n,m;
    // cin>>n>>m;
    int n = 7;
    Graph g(n);
    g.addEdge(4,3,2);
    g.addEdge(4,3,5);
    g.addEdge(0,4,3);
    g.addEdge(3,2,1);
    g.addEdge(3,6,50);
    g.addEdge(2,1,10);

    // for(int i=0;i<m;i++){
    //     int x,y,w;
    //     g.addEdge(x,y,w);
    // }

    int src = 0;
    int dest = 1;
    g.printShortestPath(src, dest);

    return 0;
}
