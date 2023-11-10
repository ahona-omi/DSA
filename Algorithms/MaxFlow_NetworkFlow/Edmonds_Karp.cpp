#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Graph {
private:
    int n;
    vector<vector<int>> capacity;
    vector<vector<int>> adj;

public:
    Graph(int numNodes) : n(numNodes) {
        capacity = vector<vector<int>>(n, vector<int>(n, 0));
        adj = vector<vector<int>>(n, vector<int>());
    }

    void addEdge(int from, int to, int cap) {
        adj[from].push_back(to);
        capacity[from][to] = cap;
    }

    int bfs(int s, int t, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, INF});

        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int next : adj[cur]) {
                if (parent[next] == -1 && capacity[cur][next]) {
                    parent[next] = cur;
                    int new_flow = min(flow, capacity[cur][next]);
                    if (next == t)
                        return new_flow;
                    q.push({next, new_flow});
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t) {
        int flow = 0;
        vector<int> parent(n);
        int new_flow;

        while ((new_flow = bfs(s, t, parent)) != 0) {
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                capacity[prev][cur] -= new_flow;
                capacity[cur][prev] += new_flow;
                cur = prev;
            }
        }
        return flow;
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u < V && v < V) g.addEdge(u, v, w);
    }
    int source = 0;
    int sink = 5;
    int maxFlow = g.maxflow(source, sink);
    cout << "Maximum flow from source to sink is: " << maxFlow << endl;

    return 0;
}


//time complexity- O(VE^2)
//space complexity- O(E+V)