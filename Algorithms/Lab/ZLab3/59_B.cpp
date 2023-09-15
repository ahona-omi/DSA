#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<pair<int, int>> a, vector<pair<int, int>> b)
{
    return a < b;
}

class Graph
{
    int time;
    vector<vector<int>> adjList;
    vector<int> disco;
    vector<int> lowT;
    stack<pair<int, int>> st;
    vector<pair<int, int>> comp;
    pair<int, int> ans;

public:
    Graph(int V)
    {
        time = 0;
        adjList.resize(V);
        disco.resize(V, -1);
        lowT.resize(V, -1);
    }
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void dfs(int work, int parent)
    {
        disco[work] = lowT[work] = ++time;

        for (int curr : adjList[work])
        {
            if (curr == parent)
                continue;

            if (disco[curr] == -1)
            {
                st.push({work, curr});
                dfs(curr, work);
                lowT[work] = min(lowT[work], lowT[curr]);

                if (lowT[curr] >= disco[work])
                {

                    while (st.top() != make_pair(work, curr))
                    {
                        if (st.top().first > st.top().second)
                        {
                            ans = {st.top().second, st.top().first};
                        }
                        else
                        {

                            ans = {st.top().first, st.top().second};
                        }
                        comp.push_back(ans);

                        st.pop();
                    }
                    if (st.top().first > st.top().second)
                    {
                        ans = {st.top().second, st.top().first};
                    }
                    else
                    {

                        ans = {st.top().first, st.top().second};
                    }
                    comp.push_back(ans);

                    st.pop();
                    sort(comp.begin(), comp.end());
                }
            }
            else if (disco[curr] < disco[work])
            {
                st.push({min(work, curr), max(work, curr)});
                lowT[work] = min(lowT[work], disco[curr]);
            }
        }
    }

    void findBiconnectComp()
    {
        int V = adjList.size();

        for (int i = 0; i < V; i++)
        {
            if (disco[i] == -1)
            {
                dfs(i, -1);
            }
        }
        sort(comp.begin(), comp.end());
        for (const auto &bridge : comp)
        {
            if (bridge.first == -5)
            {
                cout << "-" << endl;
            }
            else
            {
                cout << bridge.first << "  " << bridge.second << endl;
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g.addEdge(v1, v2);
    }

    g.findBiconnectComp();

    return 0;
}
