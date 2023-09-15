#include <bits/stdc++.h>
using namespace std;
class Graph{
    int time;
    vector<vector<int>> adjList;
    vector<int> disco;
    vector<int> lowT;
    stack<pair<int, int>> st;

public:
    Graph(int V){
        time = 0;
        adjList.resize(V);
        disco.resize(V, -1);
        lowT.resize(V, -1);
    }
    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void dfs(int work, int parent) {
    disco[work] = lowT[work] = ++time;

    for (int curr : adjList[work]) {
        if (curr == parent)
            continue;

        if (disco[curr] == -1) {
            st.push({work, curr});
            dfs(curr, work);
            lowT[work] = min(lowT[work], lowT[curr]);

            if (lowT[curr] >= disco[work]) {
                cout << "Biconnected component: ";
                while (st.top() != make_pair(work, curr)) {
                    cout << st.top().first << " --> " << st.top().second << "       ";
                    st.pop();
                }
                cout << st.top().first << " --> " << st.top().second << endl;
                st.pop();
            }
        } else if (disco[curr] < disco[work]) {
            st.push({work, curr});
            lowT[work] = min(lowT[work], disco[curr]);
        }
    }
}

void findBiconnectComp() {
    int V = adjList.size();

    for (int i = 0; i < V; ++i) {
        if (disco[i] == -1)
            dfs(i, -1);
        while (!st.empty()) {
            cout << "Biconnected component: " << st.top().first << " --> " << st.top().second << endl;
            st.pop();
        }
    }
}
};

int main(){
    int V = 7;
    Graph g(V);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(1,6);
    g.addEdge(3,5);
    g.addEdge(4,5);

    g.findBiconnectComp();

    return 0;
}
