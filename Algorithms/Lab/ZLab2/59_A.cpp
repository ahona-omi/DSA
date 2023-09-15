#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    vector<vector<int>> adjList;
    vector<bool> visited;
    stack<int> topologicalSort;
    bool hasCycle = false;

public:
    Graph(int V){
        adjList.resize(V);
        visited.resize(V, false);
    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
    }

    void dfs(int node){
        visited[node] = true;

        for (int neighbor : adjList[node]){
            if (!visited[neighbor])    dfs(neighbor);
        }
        topologicalSort.push(node);
    }

    void runDFS(){
        int V = adjList.size();
        for (int i = 0; i < V; i++){
            if (!visited[i])    dfs(i);
        }
    }

    void printSort(){
        while (!topologicalSort.empty()){
            cout << topologicalSort.top() << endl;
            topologicalSort.pop();
        }
    }
};

int main(){
    //int n = 6, m = 5;
    int n, m;
    cin >> n >> m;

    Graph g(n);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    // g.addEdge(1, 3);
    // g.addEdge(1, 2);
    // g.addEdge(0, 1);
    // g.addEdge(3, 4);
    // g.addEdge(2, 5);

    g.runDFS();
    g.printSort();

    return 0;
}
