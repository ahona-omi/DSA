#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    vector<bool> visited;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        visited.resize(V,false);
        
    }
    ~Graph() { delete[] adj; }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void dfs(int v) {
        visited[v] = true;

        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])    dfs(*i);
    }

    bool isConnected() {
        //bool visited[V];
        int i;


        for (i = 0; i < V; i++)
            if (adj[i].size() != 0) break;

        if (i == V) return true;

        dfs(i);

        for (i = 0; i < V; i++)
            if (visited[i] == false && adj[i].size() > 0) return false;

        return true;
    }

    int isEulerian(int& startVertex) {
        if (isConnected() == false) return 0;

        int odd = 0;
        for (int i = 0; i < V; i++)
            if (adj[i].size() & 1) odd++;

        if (odd > 2) return 0;
        
        startVertex = (odd == 0) ? 0 : findOddDegreeVertex();

        return (odd) ? 1 : 2;
    }

    int findOddDegreeVertex() {
        for (int i = 0; i < V; i++)
            if (adj[i].size() & 1) return i;
        return -1;
    }

    void printEulerPath(int startVertex) {
        stack<int> circuit;
        int curr = startVertex;

        while (!circuit.empty() || adj[curr].size() > 0) {
            if (adj[curr].size() == 0) {
                cout << curr << " ";
                curr = circuit.top();
                circuit.pop();
            } else {
                circuit.push(curr);
                int nextVertex = adj[curr].front();
                adj[curr].pop_front();
                for (int v : adj[nextVertex]) {
                    if (v == curr) {
                        adj[nextVertex].remove(v);
                        break;
                    }
                }
                curr = nextVertex;
            }
        }
        cout << curr << endl;
    }

    void test() {
        int startVertex;
        int res = isEulerian(startVertex);
        if (res == 0)
            cout << "Graph is not Eulerian\n";
        else if (res == 1) {
            cout << "Graph has an Euler path:\n";
            printEulerPath(startVertex);
        } else {
            cout << "Graph has an Euler cycle:\n";
            printEulerPath(startVertex);
        }
    }
};

int main() {
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.test();

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    g2.test();

    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    g3.test();

    Graph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    g4.test();

    Graph g5(3);
    g5.test();

    return 0;
}
