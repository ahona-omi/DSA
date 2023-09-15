#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	vector<vector<int>> adj;
	vector<bool> visited;
public:
	Graph(int V){
        this->V = V;
        adj.resize(V);
        visited.resize(V, false);
    }

	void addEdge(int v, int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
	void BFS(int s){
		queue<int> queue;
		visited[s] = true;
		queue.push(s);

		while (!queue.empty()) {
			s = queue.front();
			cout << s << " ";
			queue.pop();

			for (auto adjacent : adj[s]) {
				if (!visited[adjacent]) {
					visited[adjacent] = true;
					queue.push(adjacent);
				}
			}
		}
	}
}; 

int main(){
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}
