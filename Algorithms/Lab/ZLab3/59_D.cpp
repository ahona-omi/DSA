#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int V)
    {
        this->V = V;
        adjList = vector<vector<pair<int, int>>>(V);
    }

    void addEdge(int u, int v, int weight)
    {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }

    int primMaxMST()
    {
        vector<bool> vis(V, false);
        vector<int> key(V, -1);
        priority_queue<pair<int, int>> pq;

        pq.push(make_pair(0, 0));
        key[0] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            vis[u] = true;

            for (auto edge : adjList[u])
            {
                int v = edge.first;
                int weight = edge.second;

                if (!vis[v] && weight > key[v])
                {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                }
            }
        }

        int maxMSTWeight = 0;
        for (int i = 0; i < V; ++i)
        {
            maxMSTWeight += key[i];
        }

        return maxMSTWeight;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    Graph g(N);
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int maxMSTWeight = g.primMaxMST();
    cout << maxMSTWeight << endl;

    return 0;
}
