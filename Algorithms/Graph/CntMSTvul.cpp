#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) {
        this->V = V;
        adjMatrix = vector<vector<int>>(V, vector<int>(V, 0));
    }

    // function to add an edge to the graph
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // Calculate the Laplacian matrix of the graph
    vector<vector<int>> laplacianMatrix() {
        vector<vector<int>> degreeMatrix(V, vector<int>(V, 0));

        for (int i = 0; i < V; ++i) {
            int degree = accumulate(adjMatrix[i].begin(), adjMatrix[i].end(), 0);
            degreeMatrix[i][i] = degree;
        }

        vector<vector<int>> laplacian(V, vector<int>(V, 0));
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                laplacian[i][j] = degreeMatrix[i][j] - adjMatrix[i][j];
            }
        }

        return laplacian;
    }

    // Calculate the number of spanning trees using Kirchhoff's Theorem
    long long int numberOfSpanningTrees() {
        vector<vector<int>> laplacian = laplacianMatrix();

        // Removing the first row and column to get the Laplacian matrix of the spanning tree
        laplacian.erase(laplacian.begin());
        for (auto& row : laplacian) {
            row.erase(row.begin());
        }

        int n = V - 1;
        long long int determinant = 1;
        for (int i = 0; i < n; ++i) {
            if (laplacian[i][i] == 0) {
                return 0; // Laplacian matrix is singular, no spanning trees
            }

            for (int j = i + 1; j < n; ++j) {
                int factor = laplacian[j][i] / laplacian[i][i];
                for (int k = i; k < n; ++k) {
                    laplacian[j][k] -= factor * laplacian[i][k];
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            determinant *= laplacian[i][i];
        }

        return determinant;
    }
};

int main() {
    int V = 4;
    Graph g(V);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 1);
    g.addEdge(2, 3);

    long long int numSpanningTrees = g.numberOfSpanningTrees();
    cout << "Number of spanning trees: " << numSpanningTrees << endl;

    return 0;
}
