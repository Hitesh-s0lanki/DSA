// Time Complexity -> O(amount * coins.size())
// Space Complexity -> O(N)

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int recursion(vector<int>& coins, int amount) {

    if( amount == 0 ) return 0;

    if( amount < 0 ) return INT_MAX;

    int mini = INT_MAX;

    for( int i : coins ) {
        int ans = recursion(coins, amount - i);
        if( ans != INT_MAX ) {
            mini = min(mini, ans + 1);
        }
    }

    return mini;
}

int memorization(vector<int>& coins, vector<int>& dp, int amount) {

    if( amount == 0 ) return 0;

    if( amount < 0 ) return INT_MAX;

    if( dp[amount] != -1 ) return  dp[amount];

    int mini = INT_MAX;

    for( int i : coins ) {
        int ans = memorization(coins, dp, amount - i);
        if( ans != INT_MAX ) {
            mini = min(mini, ans + 1);
        }
    }

    return dp[amount] = mini;
}

int tabulation(vector<int> coins, int amount) {

    int n = coins.size();

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for( int i = 1; i <= amount; i++ ) {
        for( int j = 0; j < n; j++ ) {
            if( i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX ) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    return dp[amount];
}

int coinChange(vector<int>& coins, int amount) {
    // using recursion 
    // int ans = recursion(coins, amount);
    // return ans != INT_MAX ? ans : -1;

    // memorization
    // vector<int> dp(amount + 1, -1);
    // int ans = memorization(coins, dp, amount);
    // return ans;

    // tabulation method
    return tabulation(coins, amount);
}

int main() {

    vector<int> coins = { 1, 2, 5 };
    int amount = 11;

    // vector<int> coins = { 2 };
    // int amount = 3;

    // vector<int> coins = { 1 };
    // int amount = 0;

    cout << "number of coins that you need to make up that amount : " << coinChange(coins, amount);

    return 0;
}