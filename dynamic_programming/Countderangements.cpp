#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

long long int recursion(int n) {
    // Base condition
    if( n == 1 ) return 0;
    if( n == 2 ) return 1;

    return ((n - 1) % MOD) * ((recursion(n - 1) % MOD) + (recursion(n - 2) % MOD));
}

long long int memorization(int n, vector<int>& dp) {

    // Base condition
    if( n == 1 || n == 2 ) return dp[n] = n - 1;

    if( dp[n] != -1 ) return dp[n];

    return dp[n] = ((n - 1) % MOD) * ((memorization(n - 1, dp) % MOD) + (memorization(n - 2, dp) % MOD));
}

long long tabulation(int n) {

    int prev2 = 0;
    int prev1 = 1;

    for( int i = 3; i <= n; i++ ) {
        int curr = ((i - 1) % MOD) * ((prev1 % MOD) + (prev2 % MOD));
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long int countDerangements(int n) {
    // using recursion
    // return recursion(n);

    // using memorization
    // vector<int> dp(n + 1, -1);
    // long long int ans = memorization(n, dp);
    // print(dp);
    // return ans;


    // using tabulation
    return tabulation(n);
}

int main() {

    cout << "The total number of derangements possible of a set of 'N' elements : " << countDerangements(6);

    return 0;
}