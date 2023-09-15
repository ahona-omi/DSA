#include <bits/stdc++.h>
using namespace std;

class Grid {
private:
    int N, M;
    vector<vector<char>> grid;
    vector<vector<bool>> visited;
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};

public:
    Grid(int N, int M) : N(N), M(M) {
        grid.resize(N, vector<char>(M));
        visited.resize(N, vector<bool>(M, false));
    }

    void readGrid() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
            }
        }
    }

    bool isValid(int row, int col) {
        return (row >= 0 && row < N && col >= 0 && col < M && grid[row][col] == '.');
    }

    void dfs(int row, int col) {
        visited[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (isValid(newRow, newCol) && !visited[newRow][newCol]) {
                dfs(newRow, newCol);
            }
        }
    }

    int countConnectedAreas() {
        int connectedAreas = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '.' && !visited[i][j]) {
                    dfs(i, j);
                    connectedAreas++;
                }
            }
        }

        return connectedAreas;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Grid grid(N, M);
    grid.readGrid();

    int connectedAreas = grid.countConnectedAreas();
    cout << connectedAreas << endl;

    return 0;
}
