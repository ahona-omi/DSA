#include <bits/stdc++.h>
using namespace std;

const int N= 1e7+10;
int dp[310][10010];

//...............combination repeat(1,1,2 | 1,2,1 | 2,1,1...)................
// int minCoinCng(vector<int>& coins, int amount){
//     if(amount==0)       return 1;
//     if(dp[amount]!= -1)  return dp[amount];
//     int cnt=0;
//     for(int cn: coins){
//         if(amount-cn>=0)
//             cnt+=minCoinCng(coins,amount-cn);
//     }
//     return dp[amount]=cnt;
// }

int minCoinCng(vector<int>& coins, int amount,int indx){
    if(amount==0)       return 1;
    if(indx<0)       return 0;
    if(dp[indx][amount]!= -1)   return dp[indx][amount];

    int cnt=0;
    for(int cnAmnt=0; cnAmnt<= amount; cnAmnt+=coins[indx]){
        cnt+=minCoinCng(coins,amount-cnAmnt,indx-1);
    }
    return dp[indx][amount]=cnt;
}

int coinChange(vector<int>& coins, int amount) {
    memset(dp, -1, sizeof(dp));
    return minCoinCng(coins,amount,coins.size()-1);

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
