#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void topSort(int curr, vector<bool>& vis, stack<int>& st) {
        vis[curr] = true;
        for (const int i : adjList[curr]) {
            if (!vis[i]) {
                topSort(i, vis, st);
            }
        }
        st.push(curr);
    }

    void dfs(int curr, vector<bool>& vis) {
        vis[curr] = true;
        cout << curr << " ";
        for (const int i : adjList[curr]) {
            if (!vis[i]) {
                dfs(i, vis);
            }
        }
    }

    void kosaraju() {
        stack<int> s;
        vector<bool> vis(V, false);

        // Step 1: Perform DFS and store vertices in stack based on their finish time
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topSort(i, vis,s);
            }
        }

        // Step 2: Create the transpose of the graph
        Graph transpose(V);
        for (int i = 0; i < V; i++) {
            vis[i] = false;
            for (const int j : adjList[i]) {
                transpose.addEdge(j,i);
            }
        }

        // Step 3: Perform DFS on the transpose and print SCCs
        cout << "Strongly Connected Components:" << endl;
        while (!s.empty()) {
            int curr = s.top();
            s.pop();
            if (!vis[curr]) {
                cout << "SCC : ";
                transpose.dfs(curr, vis);
                cout << endl;
            }
        }
    }
};

int main() {
    int V = 8;
    Graph g(V);
    g.addEdge(0, 1);
    g.addEdge(3, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(6, 4);

    g.kosaraju();

    return 0;
}
