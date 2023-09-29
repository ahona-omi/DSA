#include <bits/stdc++.h>
using namespace std;

const int N= 1e7+10;
int dp[N];

//.........exponential-->O(n).........
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

int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)    cin >> a[i]; 
    cout << ans(a) << endl;

    return 0;
}

