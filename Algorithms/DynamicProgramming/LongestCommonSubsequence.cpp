#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int lcs(int i, int j, string &s1, string &s2) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

// Remove character from s1 (don't match char)
    int ans = lcs(i - 1, j, s1, s2);
// Remove character from s2 (don't match char)
    ans = max(ans, lcs(i, j - 1, s1, s2));
// Remove character from s1 & s2 (do or don't match char)
    ans = max(ans, lcs(i - 1, j - 1, s1, s2) + (s1[i] == s2[j])); // if match +1, else +0

    return dp[i][j] = ans;
}
//O(n^2)
int longestCommonSubsequence(string text1, string text2) {
    return lcs(text1.size() - 1, text2.size() - 1, text1, text2);
}

int main() {
    memset(dp, -1, sizeof(dp));
    string s1, s2;
    cin >> s1 >> s2;

    cout << longestCommonSubsequence(s1, s2) << endl;

    return 0;
}
