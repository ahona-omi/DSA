#include <bits/stdc++.h>
using namespace std;

const int N = 310; // Update the array size
int dp[N][10010];
vector<vector<int>> combinations; // Store all combinations

void findCombinations(vector<int>& coins, int amount, int indx, vector<int>& currentCombination) {
    if (amount == 0) {
        combinations.push_back(currentCombination);
        return;
    }
    if (amount < 0 || indx < 0) return;

    // Include the current coin in the combination
    if (amount >= coins[indx]) {
        currentCombination.push_back(coins[indx]);
        findCombinations(coins, amount - coins[indx], indx, currentCombination);
        currentCombination.pop_back(); // Backtrack
    }

    // Skip the current coin
    findCombinations(coins, amount, indx - 1, currentCombination);
}

int coinChange(vector<int>& coins, int amount) {
    memset(dp, -1, sizeof(dp));
    vector<int> currentCombination;
    findCombinations(coins, amount, coins.size() - 1, currentCombination);
    return combinations.size(); // Return the number of combinations
}

int main() {
    int n, x;
    cin >> n;
    vector<int> denomination(n);
    for (int i = 0; i < n; i++) cin >> denomination[i];
    cin >> x;

    int numCombinations = coinChange(denomination, x);
    cout << "Number of combinations: " << numCombinations << endl;

    if (numCombinations > 0) {
        cout << "Combinations:" << endl;
        for (const vector<int>& combo : combinations) {
            for (int coin : combo) {
                cout << coin << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
