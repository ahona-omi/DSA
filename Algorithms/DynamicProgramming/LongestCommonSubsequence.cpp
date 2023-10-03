#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int lcs(int i, int j, string &s1, string &s2) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;
//Remove character from s1 & s2 (match char)
    if (s1[i] == s2[j])
        ans = 1 + lcs(i - 1, j - 1, s1, s2);
    else       //Remove character from s1 or s2(don't match char)
        ans = max(lcs(i - 1, j, s1, s2), lcs(i, j - 1, s1, s2));
    return dp[i][j] = ans;
}
//O(n^2)
int longestCommonSubsequence(string text1, string text2) {
    return lcs(text1.size() - 1, text2.size() - 1, text1, text2);
}

void printLCS(int i, int j, string &s1, string &s2) {
    if (i < 0 || j < 0) return;

    if (s1[i] == s2[j]) {
        printLCS(i - 1, j - 1, s1, s2);
        cout << s1[i];  // Print the common character
    } else if (dp[i - 1][j] > dp[i][j - 1])
        printLCS(i - 1, j, s1, s2);
    else
        printLCS(i, j - 1, s1, s2);
}


//Bottom-up
int lcsBottomUp(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
//O(n^2)
string printLCSBottomUp(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int length = dp[m][n];
    string lcs(length, ' ');

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs[length - 1] = text1[i - 1];
            i--;
            j--;
            length--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else    j--;
    }
    return lcs;
}
int main() {
    memset(dp, -1, sizeof(dp));
    string s1, s2;
    cin >> s1 >> s2;

    int length = longestCommonSubsequence(s1, s2);
    cout <<"Longest Common Subsequence length: " << length << endl;

    cout << "Longest Common Subsequence: ";
    printLCS(s1.size() - 1, s2.size() - 1, s1, s2);
    cout << endl;


    int length = lcsBottomUp(s1, s2);
    cout << "Longest Common Subsequence length(Bottom-up): " << length << endl;

    cout << "Longest Common Subsequence(Bottom-up): ";
    string s= printLCSBottomUp(s1, s2);
    cout <<s<< endl;
    return 0;
}
