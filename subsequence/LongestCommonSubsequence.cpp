#include <iostream>
#include <vector>

using namespace std;

int recursion(string& text1, string& text2, int i, int j) {
    if( i == text1.length() ) return 0;
    if( j == text2.length() ) return 0;

    int ans = 0;
    if( text1[i] == text2[j] )
        ans = 1 + recursion(text1, text2, i + 1, j + 1);
    else
        ans = max(recursion(text1, text2, i, j + 1), recursion(text1, text2, i + 1, j));

    return ans;
}

int memorization(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
    if( i == text1.length() ) return 0;
    if( j == text2.length() ) return 0;

    if( dp[i][j] != -1 ) return dp[i][j];

    int ans = 0;
    if( text1[i] == text2[j] )
        ans = 1 + recursion(text1, text2, i + 1, j + 1);
    else
        ans = max(recursion(text1, text2, i, j + 1), recursion(text1, text2, i + 1, j));

    return dp[i][j] = ans;
}

int tabulation(string text1, string text2) {

    int n = text1.length();
    int m = text2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for( int i = n - 1; i >= 0; i-- ) {
        for( int j = m - 1; j >= 0; j-- ) {
            int ans = 0;
            if( text1[i] == text2[j] )
                ans = 1 + dp[i + 1][j + 1];
            else
                ans = max(dp[i][j + 1], dp[i + 1][j]);

            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int tabulationSO(string text1, string text2) {

    int n = text1.length();
    int m = text2.length();

    vector<int> curr(m + 1, 0);
    vector<int> next(m + 1, 0);

    for( int i = n - 1; i >= 0; i-- ) {
        for( int j = m - 1; j >= 0; j-- ) {
            int ans = 0;
            if( text1[i] == text2[j] )
                ans = 1 + next[j + 1];
            else
                ans = max(curr[j + 1], next[j]);

            curr[j] = ans;
        }
        next = curr;
    }

    return curr[0];
}

int longestCommonSubsequence(string text1, string text2) {
    // using recurion
    // return recursion(text1, text2, 0, 0);

    // using tabulation
    // vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
    // return memorization(text1, text2, 0, 0, dp);

    // using tabulation
    // return tabulation(text1, text2);

    return tabulationSO(text1, text2);
}

int main() {

    cout << longestCommonSubsequence("abcde", "ace");

    return 0;
}