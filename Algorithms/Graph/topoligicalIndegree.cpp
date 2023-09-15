#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V; 
    list<int> *adj;
    vector<int> indegree;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
        for (int i = 0; i < V; i++)
            indegree.push_back(0);
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w); 
        indegree[w]++;
    }

    vector<int> topologicalSort()
    {
        vector<int> result;
        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            result.push_back(curr);

            for (int neighbor : adj[curr])
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return result;
    }
};

int main()
{
    int n = 6, m;
    // cin >> n >> m;

    Graph g(n);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 1);
    g.addEdge(5, 2);

    cout << "Topological Sort:\n";

    vector<int> sorted = g.topologicalSort();

    for (int node : sorted)
        cout << node << " ";

    return 0;
}
