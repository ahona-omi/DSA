#include <bits/stdc++.h>
using namespace std;

int dp[205][20005];

int isSubsetSum(int i, int sum, int* nums) {
    if (sum == 0) return 1;
    if (i < 0 || sum < 0) return 0;
    if (dp[i][sum] != -1) return dp[i][sum];

// Exclude the current element
    int exclude = isSubsetSum(i - 1, sum, nums);

// Include the current element
    int include = isSubsetSum(i - 1, sum - nums[i], nums);

    return dp[i][sum] = (exclude || include);
}

int isSubsetSumBottomUp(int* nums, int n, int sum) {
    int dp[n + 1][sum + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j == 0) {
                dp[i][j] = 1; // Subset sum 0 is always possible
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // Fill the DP table bottom-up
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int solve(int* nums, int n, int sum) {
    return isSubsetSum(n - 1, sum, nums);
    //return isSubsetSumBottomUp(nums, n, sum);
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, s;
    cin >> n >> s;
    int nums[n];
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << solve(nums, n, s) << endl;

    return 0;
}
