#include <iostream>
#include <vector>

using namespace std;

int fib(int n, vector<int> dp) {
    if( dp[n] != -1 ) return dp[n];

    cout << "I m called" << endl;

    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

void tabulation(int n) { }

int main() {

    int n = 10;

    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = 1;

    for( int i = 0; i < n; i++ ) {
        cout << fib(i, dp) << "\t";
    }

    return 0;
}