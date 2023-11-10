#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<int> cuts;

int memoization(int len, vector<int>& prices) {
    if (len == 0) return 0;
    if (dp[len] != -1) return dp[len];

    int maxProfit = INT_MIN;
    int bestCut = -1;

    for (int i = 1; i <= len; ++i) {  // Iterate up to 'len' instead of 'prices.size()'
        int profit = prices[i - 1] + memoization(len - i, prices);
        if (profit > maxProfit) {
            maxProfit = profit;
            bestCut = i;
        }
    }

    cuts[len] = bestCut;

    return dp[len] = maxProfit;
}

int main() {
    int length;  // Length of the rod
    cin >> length;
    vector<int> prices(length);
    for (int i = 0; i < length; i++) cin >> prices[i];
    dp.assign(length + 1, -1);
    cuts.assign(length + 1, -1);

    int maxProfit = memoization(length, prices);
    cout << "Maximum Profit: " << maxProfit << endl;

    cout << "Optimal Cuts: ";
    int remainingLength = length;
    while (remainingLength > 0) {
        int cut = cuts[remainingLength];
        cout << cut << " ";
        remainingLength -= cut;
    }
    cout << endl;

    return 0;
}
