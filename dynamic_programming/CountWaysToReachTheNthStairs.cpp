#include <iostream>
#include <vector>


using namespace std;

int recursion(int nStairs, int i) {

    if( nStairs == i ) return 1;

    if( i > nStairs ) return 0;

    return recursion(nStairs, i + 1) + recursion(nStairs, i + 2);
}

int memorization(int nStairs, int i, vector<int>& dp) {

    if( nStairs == i ) return 1;

    if( i > nStairs ) return 0;

    if( dp[i] != -1 ) return dp[i];

    dp[i] = memorization(nStairs, i + 1, dp) + memorization(nStairs, i + 2, dp);

    return dp[i];
}

int countDistinctWays(int nStairs) {

    if( nStairs == 0 || nStairs == 1 ) return nStairs;

    int step1 = 1;
    int step2 = 2;

    for( int i = 2; i <= nStairs; i++ ) {
        int dis = (step1 + step2)%;
        step1 = step2;
        step2 = dis;
    }

    return step2;
}

int main() {

    int nStairs = 33;

    cout << countDistinctWays(nStairs) << "\t";

    // for( int i = 1; i <= nStairs; i++ ) {
    //     cout << countDistinctWays(i) << "\t";
    // }


    return 0;
}