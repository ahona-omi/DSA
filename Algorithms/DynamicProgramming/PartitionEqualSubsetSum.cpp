#include <bits/stdc++.h>
using namespace std;

int dp[205][20005];

bool partition(int i, int sum, vector<int>& nums){
    if (sum == 0)            return true;
    if (i < 0 || sum < 0)    return false;
    if (dp[i][sum] != -1)    return dp[i][sum];
//not consider i th index
    bool isPossible = partition(i - 1, sum, nums);
//consider i th index
    if (sum - nums[i] >= 0)
        isPossible |= partition(i - 1, sum - nums[i], nums);

    return dp[i][sum] = isPossible;
}

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    sum = sum / 2;
    return partition(nums.size() - 1, sum, nums);
}

bool canPartitionBottomUp(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    int target = sum / 2;
    
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    
    // Base case: If the target sum is 0, we can always achieve it by taking no elements.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    return dp[n][target];
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n ;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];

    cout <<"Partition Equal Subset Sum: " <<canPartition(nums) << endl;
    cout <<"Partition Equal Subset Sum(Bottom-up): " <<canPartitionBottomUp(nums) << endl;

    return 0;
}
