#include <bits/stdc++.h>
using namespace std;

const int N= 1e7+10;
int dp[N];

//O(2^n)
int LIS(int i,vector<int>& a){
    if(dp[i]!= -1)  return dp[i];
    int len=1;
    for(int j=0;j<i;j++){
        if(a[i]>a[j])
            len=max(len,LIS(j,a)+1);
    }
    return dp[i]=len;
}
int ans(vector<int>& nums){
    int n=nums.size();
    int maxLen=0;
    for(int i=0;i<n;i++)
        maxLen=max(maxLen,LIS(i,nums));
    return maxLen;
}

//O(n^2)--->Bottom-up
int LIS1(vector<int>& nums) {
    int n = nums.size();
    int maxLen = 0;
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1; // Initialize dp[i] to 1 since the minimum length is 1 (the element itself)
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    
    return maxLen;
}

//O(n*log n)
int LIS2(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
        int index = it - dp.begin();
        dp[index] = nums[i];
    }
    
    int maxLen = lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin();
    
    return maxLen;
}
int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)    cin >> a[i]; 
    // cout << ans(a) << endl;
    // cout << LIS1(a) << endl;
    cout << LIS2(a) << endl;

    return 0;
}

