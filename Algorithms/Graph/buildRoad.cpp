#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
    vector<vector<int>> adj;
    vector<bool> visited;

public:
    Graph(int n){
        adj.resize(n + 1);
        visited.resize(n + 1, false);
    }

    // function to add an edge to the graph
    void addEdge(int m){
        cout<<"Add Roads\n";
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a); // Assuming roads are bidirectional
        }
    }
    void dfs(int v){
        visited[v] = true;
        for (int u : adj[v]){
            if (!visited[u])    dfs(u);
        }
    }
    void buildRoad(int n){
        vector<int> discoCmpnts;

        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                discoCmpnts.push_back(i);
                dfs(i);
            }
        }
        int noRds = discoCmpnts.size() - 1;
        cout <<"No. of minimum roads: " <<noRds << endl;
        for (int i = 1; i < discoCmpnts.size(); i++)
            cout << discoCmpnts[i - 1] << " " << discoCmpnts[i] << endl;
    }
};
int main(){
    int n, m;
    cout<<"Cities & Roads : ";
    cin >> n >>m;
    Graph g(n);
    g.addEdge(m);
    g.buildRoad(n);

    return 0;
}