

#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> ans) {
    for( auto i : ans ) {
        for( int j : i )
            cout << j << "\t";
        cout << endl;
    }
}

int recursion(vector<int> weight, vector<int> value, int index, int capacity) {
    if( index == 0 ) {
        if( weight[0] <= capacity )
            return value[0];
        else
            return 0;
    }

    int include = 0;

    if( weight[index] <= capacity )
        include = value[index] + recursion(weight, value, index - 1, capacity - weight[index]);

    int exclude = recursion(weight, value, index - 1, capacity);

    return max(include, exclude);
}

int memorization(vector<int> weight, vector<int> value, vector<vector<int>>& dp, int index, int capacity) {

    if( index == 0 ) {
        if( weight[0] <= capacity )
            return value[0];
        else
            return 0;
    }

    if( dp[index][capacity] != -1 ) return dp[index][capacity];

    int include = 0;

    if( weight[index] <= capacity )
        include = value[index] + recursion(weight, value, index - 1, capacity - weight[index]);

    int exclude = recursion(weight, value, index - 1, capacity);

    return dp[index][capacity] = max(include, exclude);

}

int tabulation(vector<int> weight, vector<int> value, int n, int capacity) {

    // step1 : 
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

    // step2: base case set
    for( int w = weight[0]; w < capacity; w++ ) {
        if( weight[0] <= capacity )
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for( int index = 1; index < n; index++ ) {
        for( int w = 0; w <= capacity; w++ ) {
            int include = 0;

            if( weight[index] <= w )
                include = value[index] + dp[index - 1][w - weight[index]];

            int exclude = dp[index - 1][w];

            dp[index][w] = max(include, exclude);
        }
    }


    // print(dp);

    return dp[n - 1][capacity];
}


int tabulationOptimize(vector<int> weight, vector<int> value, int n, int capacity) {

    // step1 :
    vector<int> curr(capacity + 1, -1);

    // step2: base case set
    for( int w = weight[0]; w < capacity; w++ ) {
        if( weight[0] <= capacity )
            curr[w] = value[0];
        else
            curr[w] = 0;
    }

    for( int index = 1; index < n; index++ ) {
        for( int w = capacity; w >= 0; w-- ) {
            int include = 0;

            if( weight[index] <= w )
                include = value[index] + curr[w - weight[index]];

            int exclude = curr[w];

            curr[w] = max(include, exclude);
        }
    }


    return curr[capacity];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {

    // using recursion 
    // return recursion(weight, value, n - 1, maxWeight);

    // using memorization
    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // int ans = memorization(weight, value, dp, n - 1, maxWeight);
    // print(dp);
    // return ans;

    // using tabulation
    // return tabulation(weight, value, n, maxWeight);

    return tabulationOptimize(weight, value, n, maxWeight);
}

int main() {

    vector<int> weight = { 1, 2, 4, 5 };
    vector<int> value = { 5, 4, 8, 6 };

    cout << knapsack(weight, value, weight.size(), 5);

    return 0;
}