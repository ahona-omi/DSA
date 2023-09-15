#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Graph
{
private:
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int V)
    {
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight)
    {
        adjList[u].emplace_back(v, weight);
    }

    vector<vector<int>> convertToAdjMatrix()
    {
        int V = adjList.size();
        vector<vector<int>> graph(V, vector<int>(V, INT_MAX));

        for (int u = 0; u < V; ++u)
        {
            for (const auto &edge : adjList[u])
            {
                int v = edge.first;
                int weight = edge.second;
                graph[u][v] = min(graph[u][v], weight); // Store the minimum weight
            }
        }

        for (int u = 0; u < V; ++u)
        {
            graph[u][u] = 0;
        }

        return graph;
    }
};

void bellmanFord(const vector<vector<int>> &graph, int source, vector<int> &dist)
{
    int V = graph.size();

    dist.assign(V, INT_MAX);
    dist[source] = 0;

    for (int i = 0; i < V - 1; ++i)
    {
        for (int u = 0; u < V; ++u)
        {
            for (int v = 0; v < V; ++v)
            {
                if (graph[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
}

void reweightGraph(vector<vector<int>> &graph, const vector<int> &h)
{
    int V = graph.size();
    for (int u = 0; u < V; ++u)
    {
        for (int v = 0; v < V; ++v)
        {
            if (graph[u][v] != INT_MAX)
            {
                graph[u][v] += h[u] - h[v];
            }
        }
    }
}

void print(const vector<vector<int>> &graph)
{
    int V = graph.size();
    for (int u = 0; u < V; ++u)
    {
        for (int v = 0; v < V; ++v)
        {
            if (u == v)
                continue;
            if (graph[u][v] == INT_MAX)
            {
                cout << u << " to " << v << ": infinity" << endl;
            }
            else
            {
                cout << u << " to " << v << ": " << graph[u][v] << endl;
            }
        }
    }
}

void johnsonsAlgorithm(const vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> h(V, 0);

    vector<vector<int>> modifiedGraph(V + 1, vector<int>(V + 1, INT_MAX));
    for (int u = 0; u < V; ++u)
    {
        modifiedGraph[V][u] = 0;
    }
    for (int u = 0; u < V; ++u)
    {
        for (int v = 0; v < V; ++v)
        {
            if (graph[u][v] != INT_MAX)
            {
                modifiedGraph[u][v] = graph[u][v];
            }
        }
    }

    bellmanFord(modifiedGraph, V, h);

    reweightGraph(modifiedGraph, h);

    vector<vector<int>> shortestDistances(V, vector<int>(V, INT_MAX));

    for (int u = 0; u < V; ++u)
    {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, u});
        vector<int> dist(V, INT_MAX);
        dist[u] = 0;

        while (!pq.empty())
        {
            int du = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if (du > dist[curr])
                continue;

            for (int v = 0; v < V; ++v)
            {
                if (modifiedGraph[curr][v] != INT_MAX && dist[curr] + modifiedGraph[curr][v] < dist[v])
                {
                    dist[v] = dist[curr] + modifiedGraph[curr][v];
                    pq.push({dist[v], v});
                }
            }
        }

        for (int v = 0; v < V; ++v)
        {
            shortestDistances[u][v] = dist[v];
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < V; ++i)
    {
        if (shortestDistances[i][i] < 0)
        {
            cout << "not possible" << endl;
            return;
        }
    }

    print(shortestDistances);
}

int main()
{
    int V, E;
    cin >> V >> E;

    Graph graph(V);

    for (int i = 0; i < E; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    vector<vector<int>> adjMatrix = graph.convertToAdjMatrix();

    johnsonsAlgorithm(adjMatrix);

    return 0;
}
