#include <bits/stdc++.h>
using namespace std;

string printBottomup(vector<vector<int>> &bracket, int i, int j){
    if (i == j)    return string(1, char('A' + i - 1));
    string lft = printBottomup(bracket, i, bracket[i][j]);
    string rgt = printBottomup(bracket, bracket[i][j] + 1, j);
    return "(" + lft + rgt + ")";
}
void matrixChainMulBottomUp(vector<int> &dimen){
    int n = dimen.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++){
        for (int i = 1; i < n - len + 1; i++){
            int j = i + len - 1;
            dp[i][j] = 1e9;
            for (int k = i; k < j; k++){
                int cost = dp[i][k] + dp[k + 1][j] + dimen[i - 1] * dimen[k] * dimen[j];
                if (cost < dp[i][j]){
                    dp[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }
    string ans = printBottomup(bracket, 1, n - 1);
    cout << ans << endl;
    cout << "Optimal Cost is: " << dp[1][n - 1] << endl;

    // Print the DP table
    cout << "DP Table:\n";
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cout << dp[i][j] << '\t';
        }
        cout << endl;
    }

    // Print the bracket table
    cout << "Bracket Table:\n";
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cout << bracket[i][j] << '\t';
        }
        cout << endl;
    }
}

//Using Memoization...
string printMemoization(vector<vector<int>> &bracket, int i, int j){
    if (i == j)    return string(1, char('A' + i - 1));
    string lft = printMemoization(bracket, i, bracket[i][j]);
    string rgt = printMemoization(bracket, bracket[i][j] + 1, j);
    return "(" + lft + rgt + ")";
}
int matrixChainMulMemoization(vector<int> &P, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &bracket){
    if (i == j)    return 0;
    if (dp[i][j] != -1)    return dp[i][j];

    dp[i][j] = INT_MAX;
    int minCost = INT_MAX;
    for (int k = i; k < j; k++){
        int cost = matrixChainMulMemoization(P, i, k, dp, bracket) + matrixChainMulMemoization(P, k + 1, j, dp, bracket) + P[i - 1] * P[k] * P[j];
        if (cost < minCost){
            minCost = cost;
            bracket[i][j] = k;
        }
    }
    dp[i][j] = minCost;
    return minCost;
}
void mcmMemoizationWrapper(vector<int> &P){
    int n = P.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<int>> bracket(n, vector<int>(n, 0));
    int optCost = matrixChainMulMemoization(P, 1, n - 1, dp, bracket);
    string optimalParen = printMemoization(bracket, 1, n - 1);

    cout << optimalParen << endl;
    cout << "Optimal Cost is: " << optCost << endl;
}

int main(){
    vector<int> dimensions;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        dimensions.push_back(num);
    }
    matrixChainMulBottomUp(dimensions);
    cout<<endl<<"Using Memoization..."<<endl;
    mcmMemoizationWrapper(dimensions);
    return 0;
}
