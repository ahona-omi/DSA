#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjList; 

public:
    Graph(int V) {
        this->V = V;
        adjList = vector<vector<int>>(V);
    }

    // function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << i << " : ";
            for (int j : adjList[i])     cout << j << " ";
            cout << endl;
        }
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    Graph g(n);
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    cout<<"Adjacent list->\n";
    g.printAdjList();

    return 0;
}
