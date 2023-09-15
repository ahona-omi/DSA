#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    vector<int> indegree;
    vector<bool> visited;
    int count = 0;

public:
    Graph(int V) {
        adjList.resize(V);
        indegree.resize(V, 0);
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        indegree[v]++;
    }

    void dfs() {
        int V = adjList.size();
        bool allVisited = true;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && indegree[i] == 0) {
                allVisited = false;
                visited[i] = true;
                for (int neighbor : adjList[i])    indegree[neighbor]--;
                dfs();
                visited[i] = false;
                for (int neighbor : adjList[i])    indegree[neighbor]++;
            }
        }

        if (allVisited)    count++;
    }

    int countTopologicalOrders() {
        dfs();
        return count;
    }
};

int main() {
    // int n = 4, m = 4;
    int n, m;
    cin >> n >> m;

    Graph g(n);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    // g.addEdge(3,1);
    // g.addEdge(3, 2);
    // g.addEdge(1,0);
    // g.addEdge(2,0);

    int numTopologicalOrders = g.countTopologicalOrders();
    cout << numTopologicalOrders << endl;

    return 0;
}