#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int time;
    vector<vector<int>> adjList;
    vector<bool> vis;
    vector<int> discoTime;
    vector<int> lowDT;
    vector<pair<int, int>> bridges;

public:
    Graph(int V)
    {
        time = 0;
        adjList.resize(V);
        vis.resize(V, false);
        discoTime.resize(V, 0);
        lowDT.resize(V, 0);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(int curr, int par)
    {
        vis[curr] = true;
        discoTime[curr] = lowDT[curr] = ++time;

        for (int neighbor : adjList[curr])
        {
            if (neighbor == par)
                continue;

            if (vis[neighbor])
            {
                lowDT[curr] = min(lowDT[curr], discoTime[neighbor]);
            }
            else
            {
                dfs(neighbor, curr);
                lowDT[curr] = min(lowDT[curr], lowDT[neighbor]);
                if (discoTime[curr] < lowDT[neighbor])
                {
                    bridges.push_back(make_pair(min(curr, neighbor), max(curr, neighbor)));
                }
            }
        }
    }

    void findBridges()
    {
        int V = adjList.size();

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1);
            }
        }
        sort(bridges.begin(), bridges.end());
        for (const auto &bridge : bridges)
        {
            cout << bridge.first << "     " << bridge.second << endl;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g.addEdge(v1, v2);
    }
    cout << "Bridges\n";
    g.findBridges();

    return 0;
}
