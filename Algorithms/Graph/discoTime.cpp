#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    vector<bool> visited;
    vector<int> discoTime;
    vector<int> deadTime;
    vector<int> component;
    int timeCnt = 0;
    int currCmpt = 0;

public:
    Graph(int V) {
        adjList.resize(V);
        visited.resize(V, false);
        discoTime.resize(V, 0);
        deadTime.resize(V, 0);
        component.resize(V, -1);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void sortedAdjList()
    {
        for(int i=0;i<adjList.size();i++)
            sort(adjList[i].begin(), adjList[i].end());
    }

    void dfs(int node) {
        visited[node] = true;
        component[node] = currCmpt;
        timeCnt++;
        discoTime[node] = timeCnt;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor])     dfs(neighbor);
        }

        timeCnt++;
        deadTime[node] = timeCnt;
    }

    void runDFS() {
        int V = adjList.size();
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                currCmpt++;
                dfs(i);
            }
        }
    }

    void printResults() {
        int V = adjList.size();
        for (int i = 0; i < V; i++)
            cout << i << ": " << component[i] << " " << discoTime[i] << " " << deadTime[i] << endl;
    }
};

int main() {
    int n,m;
    cin >> n >> m;

    Graph g(n);
    cout<<"Components, Discovery and Fininshing Time of Unweighted Undirected Graph->\n";
    for (int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.sortedAdjList();
    g.runDFS();
    g.printResults();

    return 0;
}
