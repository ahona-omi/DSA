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

    // BFS to find the shortest path from node 0 to all other nodes
    vector<int> BFS(int start) {
        vector<int> distance(V, -1);
        queue<int> q;

        distance[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int currVertex = q.front();
            q.pop();

            for (int nextVertex : adjList[currVertex]) {
                if (distance[nextVertex] == -1) { 
                    distance[nextVertex] = distance[currVertex] + 1;
                    q.push(nextVertex);
                }
            }
        }

        return distance;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Graph g(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    vector<int> shortestPath = g.BFS(0); // BFS from node 0
    cout<<"Shortest Path Length->\n";
    // Print the shortest path of each node from the source node (node 0)
    for (int i = 0; i < N; i++) {
        cout << i << ": ";
        if (shortestPath[i] != -1)
            cout << shortestPath[i] << endl;
        else
            cout << "Not Reachable" << endl;
    }

    return 0;
}
