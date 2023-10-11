#include <iostream>
#include <vector>

using namespace std;

// Function to find the minimum number of scalar multiplications needed to
// compute the matrix chain product.
int matrixChainMultiplication(vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Number of matrices

    // Create a 2D DP table to store the minimum number of multiplications
    // needed for each subproblem.
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the DP table bottom-up.
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = 1e9;

            // Try all possible splits to find the minimum cost
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] +
                           dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // The result is stored in dp[0][n-1], which represents the optimal
    // cost to multiply all matrices from 1 to n.
    return dp[0][n - 1];
}

int main() {
    vector<int> dimensions = {30, 35, 15, 5, 10, 20, 25};

    int minMultiplications = matrixChainMultiplication(dimensions);

    cout << "Minimum number of scalar multiplications: " << minMultiplications << endl;

    return 0;
}
