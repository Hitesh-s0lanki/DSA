#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<int>& ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int recursion(int n, int x, int y, int z) {
    if( n == 0 ) return 0;

    if( n < 0 ) return INT_MIN;

    int maxi = INT_MIN;

    for( auto i : { x, y, z } ) {
        int ans = recursion(n - i, x, y, z);
        if( ans != INT_MIN ) {
            maxi = max(maxi, ans + 1);
        }
    }

    return maxi;
}

int memorization(int n, vector<int> cuts, vector<int>& dp) {
    if( n == 0 ) return 0;

    if( n < 0 ) return INT_MIN;

    if( dp[n] != -1 ) return dp[n];

    int maxi = INT_MIN;

    for( auto i : cuts ) {
        int ans = memorization(n - i, cuts, dp);
        if( ans != INT_MIN ) {
            maxi = max(maxi, ans + 1);
        }
    }

    return dp[n] = maxi;
}

int tabulation(int n, vector<int> cuts) {
    vector<int> dp(n + 1, INT_MIN);

    dp[0] = 0;

    for( int i = 1; i <= n; i++ ) {
        for( int j : cuts ) {
            if( i - j >= 0 && dp[i - j] != INT_MIN ) {
                dp[i] = max(dp[i - j] + 1, dp[i]);
            }
        }
    }

    return dp[n];
}

int cutSegments(int n, int x, int y, int z) {

    // using the recursion
    // int ans = recursion(n, x, y, z);
    // if( ans == INT_MIN ) ans = 0;
    // return ans;


    // using memorization   
    // vector<int> dp(n + 1, -1);
    // int ans = memorization(n, { x, y, z }, dp);
    // print(dp);
    // if( ans == INT_MIN ) ans = 0;
    // return ans;


    return tabulation(n, { x, y, z });
}

int main() {

    cout << "the maximum number of segments you can make of this rod provided : " << cutSegments(7, 5, 2, 2) << endl;
    // cout << "the maximum number of segments you can make of this rod provided : " << cutSegments(8, 3, 3, 3) << endl;

    return 0;
}