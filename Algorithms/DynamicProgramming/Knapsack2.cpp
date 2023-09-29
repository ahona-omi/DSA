#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<pair<int, int>> items;
ll dp[105][100005];

// N[select no. of items] -> sum == weight -> min weight
ll knapSack(int ind, int valLeft) {
    if (valLeft == 0) return 0;         // no space in bag
    if (ind < 0) return 1e15;           // no items left in house
    if (dp[ind][valLeft] != -1) return dp[ind][valLeft];

// Don't choose item at ind
    ll ans = knapSack(ind - 1, valLeft);

// Choose item at ind
    if (valLeft - items[ind].second >= 0)
        ans = min(ans, knapSack(ind - 1, valLeft - items[ind].second) + items[ind].first);

    return dp[ind][valLeft] = ans;
}

void ksAns(int n, int w) {
    int maxVal = 1e5;
    for (int i = maxVal; i >= 0; --i) {
        if (knapSack(n - 1, i) <= w) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    items.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }
    ksAns(n, w);
    return 0;
}
