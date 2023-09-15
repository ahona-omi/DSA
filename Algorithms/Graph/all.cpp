#include <bits/stdc++.h>
using namespace std;

int Min_Distance(const std::vector<int> &dist, const std::vector<bool> &visit)
{
    int minimum = INT_MAX;
    int minVertex = 0;
    for (size_t vertex = 0; vertex < dist.size(); ++vertex)
    {
        if (minimum > dist[vertex] && !visit[vertex])
        {
            minimum = dist[vertex];
            minVertex = vertex;
        }
    }
    return minVertex;
}

void Dijkstra_Algorithm(const std::vector<std::vector<int>> &graph,
                        const std::vector<std::vector<int>> &Altered_Graph,
                        int source)
{
    int tot_vertices = graph.size();

    std::vector<bool> sptSet(tot_vertices, false);
    std::vector<int> dist(tot_vertices, INT_MAX);

    dist[source] = 0;

    for (int count = 0; count < tot_vertices; ++count)
    {
        int curVertex = Min_Distance(dist, sptSet);
        sptSet[curVertex] = true;

        for (int vertex = 0; vertex < tot_vertices; ++vertex)
        {
            if (!sptSet[vertex] && dist[vertex] > (dist[curVertex] + Altered_Graph[curVertex][vertex]) && graph[curVertex][vertex] != 0)
            {
                dist[vertex] = dist[curVertex] + Altered_Graph[curVertex][vertex];
            }
        }
    }

    for (int vertex = 0; vertex < tot_vertices; ++vertex)
    {
        std::cout << "Vertex " << vertex << ": " << dist[vertex] << std::endl;
    }
}

std::vector<int> BellmanFord_Algorithm(std::vector<std::vector<int>> &edges,
                                       const std::vector<std::vector<int>> &graph,
                                       int tot_vertices)
{
    std::vector<int> dist(tot_vertices + 1, INT_MAX);
    dist[tot_vertices] = 0;

    for (int i = 0; i < tot_vertices; ++i)
    {
        edges.push_back({tot_vertices, i, 0});
    }

    for (int i = 0; i < tot_vertices; ++i)
    {
        for (const auto &edge : edges)
        {
            int source = edge[0];
            int destn = edge[1];
            int weight = edge[2];
            if (dist[source] != INT_MAX && dist[source] + weight < dist[destn])
            {
                dist[destn] = dist[source] + weight;
            }
        }
    }

    return std::vector<int>(dist.begin(), dist.begin() + tot_vertices);
}

void JohnsonAlgorithm(std::vector<std::vector<int>> &graph)
{
    std::vector<std::vector<int>> edges;

    for (size_t i = 0; i < graph.size(); ++i)
    {
        for (size_t j = 0; j < graph[i].size(); ++j)
        {
            if (graph[i][j] != 0)
            {
                edges.push_back({static_cast<int>(i), static_cast<int>(j), graph[i][j]});
            }
        }
    }

    std::vector<int> Alter_weigts = BellmanFord_Algorithm(edges, graph, graph.size());

    std::vector<std::vector<int>> Altered_Graph(graph.size(), std::vector<int>(graph.size(), 0));

    for (size_t i = 0; i < graph.size(); ++i)
    {
        for (size_t j = 0; j < graph[i].size(); ++j)
        {
            if (graph[i][j] != 0)
            {
                Altered_Graph[i][j] = graph[i][j] + Alter_weigts[i] - Alter_weigts[j];
            }
        }
    }

    std::cout << "Modified Graph:" << std::endl;
    for (size_t i = 0; i < Altered_Graph.size(); ++i)
    {
        for (size_t j = 0; j < Altered_Graph[i].size(); ++j)
        {
            std::cout << Altered_Graph[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (size_t source = 0; source < graph.size(); ++source)
    {
        std::cout << "\nShortest Distance with vertex " << source << " as the source:\n";
        Dijkstra_Algorithm(graph, Altered_Graph, static_cast<int>(source));
    }
}

int main()
{
    std::vector<std::vector<int>> graph = {
        {0, -5, 2, 3},
        {0, 0, 4, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};

    JohnsonAlgorithm(graph);

    return 0;
}