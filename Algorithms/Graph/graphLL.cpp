#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Kosaraju {
public:
    struct Edge {
        int dest;
        Edge(int d) : dest(d) {}
    };

    static void createGraph(vector<vector<Edge>>& graph, int V) {
        graph.resize(V);
        graph[0].emplace_back(1);
        graph[0].emplace_back(3);
        graph[1].emplace_back(2);
        graph[2].emplace_back(3);
        graph[2].emplace_back(4);
        graph[2].emplace_back(4);
        graph[2].emplace_back(4);
        graph[2].emplace_back(4);
        graph[2].emplace_back(4);
    }

    static void topSort(vector<vector<Edge>>& graph, int curr, stack<int>& s, bool vis[]) {
        vis[curr] = true;
        for (const Edge& e : graph[curr]) {
            if (!vis[e.dest]) {
                topSort(graph, e.dest, s, vis);
            }
        }
        s.push(curr);
    }

    static void dfs(vector<vector<Edge>>& graph, bool vis[], int curr) {
        vis[curr] = true;
        cout << curr << " ";
        for (const Edge& e : graph[curr]) {
            if (!vis[e.dest]) {
                dfs(graph, vis, e.dest);
            }
        }
    }

    static void kosaraju(vector<vector<Edge>>& graph, int V) {
        stack<int> s;
        bool* vis = new bool[V]();
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topSort(graph, i, s, vis);
            }
        }

        vector<vector<Edge>> transpose(V);
        for (int i = 0; i < V; i++) {
            vis[i] = false;
            for (const Edge& e : graph[i]) {
                transpose[e.dest].emplace_back(i);
            }
        }

        while (!s.empty()) {
            int curr = s.top();
            s.pop();
            if (!vis[curr]) {
                cout << "SCC : ";
                dfs(transpose, vis, curr);
                cout << endl;
            }
        }

        delete[] vis;
    }
};

int main() {
    int V = 5;
    vector<vector<Kosaraju::Edge>> graph(V);
    Kosaraju::createGraph(graph, V);
    Kosaraju::kosaraju(graph, V);
    return 0;
}
