#include <bits/stdc++.h>
using namespace std;

const int N= 1e7+10;
int dp[10010];

int minCoinCng(vector<int>& coins, int amount){
    if(amount==0)       return 0;
    if(dp[amount]!= -1)  return dp[amount];
    int cnt=INT_MAX;
    for(int cn: coins){
        if(amount-cn>=0)
            cnt=min(cnt+0LL, minCoinCng(coins,amount-cn)+1LL);  //avoid overflow if "ans=INT_MAX" go through the loop-> int to long long
    }
    return dp[amount]=cnt;
}
int coinChange(vector<int>& coins, int amount) {
    memset(dp, -1, sizeof(dp));
    int ans= minCoinCng(coins,amount);

    return ans== INT_MAX ? -1: ans;
}

int main(){
    int n,x;
    cin >>n;
    vector<int> denomination(n);
    for (int i = 0; i < n; i++)   cin>> denomination[i];
    cin >> x;

	cout<<coinChange(denomination,x)<<endl;
	return 0;
}
