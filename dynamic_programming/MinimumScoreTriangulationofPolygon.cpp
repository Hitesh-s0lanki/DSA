#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<vector<int>>& dp) {
    for( auto i : dp ) {
        for( int j : i ) {
            cout << j << "\t";
        }
        cout << endl;
    }
}

int recursion(vector<int>& values, int i, int j) {
    if( i + 1 == j ) return 0;

    int ans = INT_MAX;
    for( int k = i + 1; k < j; k++ ) {
        ans = min(ans, values[i] * values[k] * values[j] + recursion(values, i, k) + recursion(values, k, j));
    }

    return ans;
}

int memorization(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
    if( i + 1 == j ) return 0;

    if( dp[i][j] != -1 ) return dp[i][j];

    int ans = INT_MAX;
    for( int k = i + 1; k < j; k++ ) {
        ans = min(ans, values[i] * values[k] * values[j] + recursion(values, i, k) + recursion(values, k, j));
    }

    return dp[i][j] = ans;
}

int tabulation(vector<int>& values, int n) {

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for( int i = n - 1; i >= 0; i-- ) {
        for( int j = i + 2; j < n; j++ ) {
            int ans = INT_MAX;
            for( int k = i + 1; k < j; k++ ) {
                ans = min(ans, values[i] * values[k] * values[j] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }

    return dp[0][n - 1];
}

int minScoreTriangulation(vector<int>& values) {
    int n = values.size();

    // using recursion
    // return recursion(values, 0, n - 1);

    // using memorization
    // vector<vector<int>> dp(n, vector<int>(n, -1));
    // int ans = memorization(values, 0, n - 1, dp);
    // print(dp);
    // return ans;

    // using tabulation
    return tabulation(values, n);
}

int main() {

    vector<int> values = { 1,3,1,4,1,5 };
    cout << minScoreTriangulation(values);

    return 0;
}