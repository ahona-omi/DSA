#include <bits/stdc++.h>
using namespace std;

int mat[100][100], dp[100][100];
int r, c;
int call(int i, int j)
{
    if (i >= 0 && i < r and j >= 0 && j < c)
    { /// If inside array
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MIN;
        /// Moving to three default direction, also add current cell's point
        res = max(res, call(i + 1, j) + mat[i][j]);
        res = max(res, call(i + 1, j - 1) + mat[i][j]);
        res = max(res, call(i + 1, j + 1) + mat[i][j]);
        return dp[i][j] = res;
    }
    else
        return 0; /// If outside array
}
int maxPoints(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // Create a DP table of the same size as the grid
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the first cell of the DP table
    dp[0][0] = grid[0][0];

    // Initialize the first row of the DP table
    for (int j = 1; j < n; j++)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Initialize the first column of the DP table
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill in the DP table
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            // Use the maximum of the two possible moves (from left or from above)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    // The result will be in the bottom-right cell of the DP table
    return dp[m - 1][n - 1];
}

int main()
{
    int res = 0;
    memset(dp, -1, sizeof(dp));
    cout << "Please Enter Matrix size: ";
    cin >> r >> c;
    cout << "Now Enter Matrix:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
    res = call(0, 0);
    cout << "Maximum Point is: " << res << endl;

    // int m, n;
    // cout << "Enter the number of rows and columns: ";
    // cin >> m >> n;

    // vector<vector<int>> grid(m, vector<int>(n));

    // cout << "Enter the grid values:" << endl;
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cin >> grid[i][j];
    //     }
    // }

    // int maxScore = maxPoints(grid);
    // cout << "The maximum score you can achieve is: " << maxScore << endl;

    return 0;
}