#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
const int INF = 1e9;
int dp[10010];

int minCoinCng(vector<int>& coins, int amount){
    if(amount==0)       return 0;
    if(dp[amount]!= -1)  return dp[amount];
    int cnt = INF; // Initialize to infinity
    for(int cn: coins){
        if(amount - cn >= 0){
            int subproblem = minCoinCng(coins, amount - cn);
            if (subproblem != -1) {
                cnt = min(cnt, subproblem + 1);
            }
        }
    }
    return dp[amount] = (cnt == INF) ? -1 : cnt;
}

void printCoins(vector<int>& coins, int amount) {
    if (amount == 0) {
        return;
    }
    for (int cn : coins) {
        if (amount - cn >= 0 && dp[amount - cn] != -1 && dp[amount] == dp[amount - cn] + 1) {
            cout << cn << " ";
            printCoins(coins, amount - cn);
            break;
        }
    }
}

int coinChange(vector<int>& coins, int amount) {
    memset(dp, -1, sizeof(dp));
    int ans = minCoinCng(coins, amount);

    if (ans == -1) {
        cout << "No combination of coins can make up this amount." << endl;
    } else {
        cout << "Minimum coins required: " << ans << endl;
        cout << "Coins used: ";
        printCoins(coins, amount);
        cout << endl;
    }

    return ans;
}

int coinChangeBottomUp(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INF); // Rename dp to avoid conflict
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    int ans = dp[amount];

    if (ans == INF) {
        cout << "No combination of coins can make up this amount." << endl;
    } else {
        cout << "Minimum coins required: " << ans << endl;
        cout << "Coins used: ";
        printCoins(coins, amount);
        cout << endl;
    }

    return ans == INF ? -1 : ans;
}


int main(){
    int n, x;
    cin >> n >> x;
    vector<int> denomination(n);
    for (int i = 0; i < n; i++) {
        cin >> denomination[i];
    }

    cout << "Top-Down Approach:" << endl;
    int ansTopDown = coinChange(denomination, x);

    cout << "Bottom-Up Approach:" << endl;
    int ansBottomUp = coinChangeBottomUp(denomination, x);

    return 0;
}
