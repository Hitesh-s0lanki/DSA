#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int memorization(vector<int> cost, vector<int>& dp, int n, int index) {
    if( index >= n ) return 0;

    if( dp[index] != -1 ) return dp[index];

    return dp[index] = min(memorization(cost, dp, n, index + 1), memorization(cost, dp, n, index + 2)) + cost[index];
}

int recursion(vector<int> cost, int n, int index) {
    if( index >= n ) return 0;

    return min(recursion(cost, n, index + 1), recursion(cost, n, index + 2)) + cost[index];
}

int loveBabbar(vector<int>& cost) {
    int n = cost.size();

    int step1 = cost[0];
    int step2 = cost[1];

    for( int i = 2; i < n; i++ ) {
        int curr = cost[i] + min(step1, step2);
        step2 = step1;
        step1 = curr;
    }

    return min(step1, step2);
}

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();

    // using recursion
    // return min(recursion(cost, n, 0), recursion(cost, n, 1));

    // using memorization 
    // vector<int> dp(n, -1);
    // int ans = min(memorization(cost, dp, n, 0), memorization(cost, dp, n, 1));
    // print(dp);
    // return ans;

    // using dp
    int step1 = 0;
    int step2 = 0;

    for( int i = n - 1; i >= 0; i-- ) {
        int curr = min(cost[i] + step1, cost[i] + step2);
        step2 = step1;
        step1 = curr;
    }

    return min(step1, step2);
}



int main() {

    vector<int> cost = { 10,15,20 };
    // vector<int> cost = { 1,100,1,1,1,100,1,1,100,1 };

    cout << "the minimum cost to reach the top of the floor : " << minCostClimbingStairs(cost);

    return 0;
}