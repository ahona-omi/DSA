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

int solve(int* nums, int n, int sum) {
    return isSubsetSum(n - 1, sum, nums);
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
