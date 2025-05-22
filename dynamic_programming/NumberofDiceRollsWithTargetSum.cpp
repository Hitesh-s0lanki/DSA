// Time Complexity -> O(dice * target * faces)
// Space Complexity -> O(2 * target)  

#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

int recursion(int dice, int faces, int target) {

    // base case
    if( target < 0 )  return 0;
    if( dice == 0 && target != 0 )  return 0;
    if( dice != 0 && target == 0 )  return 0;

    // target achieve case
    if( target == 0 && dice == 0 ) return 1;

    int ans = 0;

    for( int i = 1; i <= faces; i++ )
        ans += recursion(dice - 1, faces, target - i);

    return ans;
}

int memorization(int dice, int faces, int target, vector<vector<int>>& dp) {

    // base case
    if( target < 0 )  return 0;
    if( dice == 0 && target != 0 )  return 0;
    if( dice != 0 && target == 0 )  return 0;

    // target achieve case
    if( target == 0 && dice == 0 ) return 1;

    if( dp[dice][target] != -1 ) return dp[dice][target];

    int ans = 0;

    for( int i = 1; i <= faces; i++ )
        if( target - i >= 0 )
            ans = (ans + memorization(dice - 1, faces, target - i, dp)) % MOD;

    return dp[dice][target] = ans;
}

int tabulation(int d, int f, int t) {
    vector<vector<int>> dp(d + 1, vector<int>(t + 1, 0));

    dp[0][0] = 1;

    for( int dice = 1; dice <= d; dice++ ) {
        for( int target = 1; target <= t; target++ ) {
            int ans = 0;

            for( int i = 1; i <= f; i++ )
                if( target - i >= 0 )
                    ans = (ans + dp[dice - 1][target - i]) % MOD;

            dp[dice][target] = ans;
        }
    }

    return dp[d][t];
}

int tabulationSO(int d, int f, int t) {

    vector<int> curr(t + 1, 0);
    vector<int> prev(t + 1, 0);

    prev[0] = 1;

    for( int dice = 1; dice <= d; dice++ ) {
        for( int target = 1; target <= t; target++ ) {
            int ans = 0;

            for( int i = 1; i <= f; i++ )
                if( target - i >= 0 )
                    ans = (ans + prev[target - i]) % MOD;

            curr[target] = ans;
        }
        prev = curr;
    }

    return curr[t];
}

int numRollsToTarget(int dice, int faces, int target) {

    // using recursion
    // return recursion(dice, faces, target);

    // using memorization
    // vector<vector<int>> dp(dice + 1, vector<int>(target + 1, -1));
    // return memorization(dice, faces, target, dp);

    // using tabulation
    // return tabulation(dice, faces, target);

    // tabulation + SO
    return tabulationSO(dice, faces, target);
}

int main() {

    cout << numRollsToTarget(2, 6, 7);
    // cout << numRollsToTarget(30, 30, 500);

    return 0;
}