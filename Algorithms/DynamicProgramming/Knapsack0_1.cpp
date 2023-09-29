#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<pair<int, int>> items;
vector<vector<ll>> dp;

// 0-1 knapsack(N[select no. of items] -> sum less than weight -> More value)
ll knapSack(int ind, int wtLeft) {
    if (wtLeft == 0) return 0;   // no space in bag
    if (ind < 0) return 0;       // no items left in house
    if (dp[ind][wtLeft] != -1) return dp[ind][wtLeft];

// Don't choose item at ind
    ll ans = knapSack(ind - 1, wtLeft);

// Choose item at ind
    if (wtLeft - items[ind].first >= 0)
        ans = max(ans, knapSack(ind - 1, wtLeft - items[ind].first) + items[ind].second);

    return dp[ind][wtLeft] = ans;
}

int main() {
    int n, w;
    cin >> n >> w;
    items.resize(n);
    dp.resize(n, vector<ll>(w + 1, -1));

    for (int i = 0; i < n; i++)
        cin >> items[i].first >> items[i].second;

    cout << knapSack(n - 1, w) << endl;

    return 0;
}
