#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int time;
    vector<vector<int>> adjList;
    vector<bool> vis; 
    vector<int> discoTime; 
    vector<int> lowDT;
    vector<bool> isArticulation;

public:
    Graph(int V) {
        time = 0;
        adjList.resize(V);
        vis.resize(V,false);
        discoTime.resize(V,0);
        lowDT.resize(V,0);
        isArticulation.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(int curr, int par) {
        vis[curr] = true;
        discoTime[curr] = lowDT[curr] = ++time;
        int child=0;

        for (int neighbor : adjList[curr]) {
            if (neighbor == par)
                continue;

            if (vis[neighbor]) {
                lowDT[curr] = min(lowDT[curr], discoTime[neighbor]);
            } else {
                dfs(neighbor, curr);
                lowDT[curr] = min(lowDT[curr], lowDT[neighbor]);
                if (discoTime[curr] <= lowDT[neighbor] && par!=-1) {
                    isArticulation[curr] =true;
                } child++;
            }
        } if(par== -1&&child>1)
            isArticulation[curr] =true;
    }

    void getArticulation() {
        int V=adjList.size();

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1);
            }
        }
        for(int i=0;i<V;i++) {
            if(isArticulation[i]) {
                cout<<i<<endl;
            }
        }
    }
};

int main() {
    int V = 5;
    Graph g(V);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);

    g.getArticulation();

    return 0;
}
