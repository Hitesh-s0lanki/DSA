#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

int add(int a, int b) {
    return((a % MOD) + (b % MOD)) % MOD;
}

int mul(int a, int b) {
    return ((a % MOD) * 1LL * (b % MOD) % MOD);
}

int recursion(int n, int k) {

    // Base Condition
    if( n == 1 ) return k * n;

    if( n == 2 ) return add(k, mul(k, k - 1));

    return add(mul(recursion(n - 1, k), (k - 1)), (recursion(n - 2, k) * (k - 1)));
}

int memorization(int n, int k, vector<int> dp) {

    // Base Condition
    if( n == 1 ) return dp[n] = k * n;

    if( n == 2 ) return dp[n] = add(k, mul(k, k - 1));

    if( dp[n] != -1 ) return dp[n];

    return dp[n] = add(mul(memorization(n - 1, k, dp), (k - 1)), (memorization(n - 2, k, dp) * (k - 1)));
}

int tabulation(int n, int k) {

    if( n == 1 ) return k;

    int prev2 = k;
    int prev1 = add(k, mul(k, k - 1));

    for( int i = 3; i <= n; i++ ) {
        int ans = add(mul(prev1, (k - 1)), mul(prev2, (k - 1)));
        prev2 = prev1 % MOD;
        prev1 = ans % MOD;
    }

    return prev1;
}

int numberOfWays(int n, int k) {
    // using recursion
    // return recursion(n, k);

    // using memorization 
    // vector<int> dp(n + 1, -1);
    // return memorization(n, k, dp);

    // using tabulation
    return tabulation(n, k);
}

int main() {

    cout << "Number of way : " << numberOfWays(3, 3);

    return 0;
}