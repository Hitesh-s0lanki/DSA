#include <iostream>
#include <vector>

using namespace std;

int recursion(vector<int>& nums, int n, int index) {
    if( index >= n ) return 0;

    // include 
    int include = nums[index] + recursion(nums, n, index + 2);

    int exclude = recursion(nums, n, index + 1);

    return max(include, exclude);
}

int memorization(vector<int>& nums, int n, int index, vector<int>& dp) {
    if( index >= n ) return 0;

    if( dp[index] != -1 ) return dp[index];

    // include 
    int include = nums[index] + recursion(nums, n, index + 2);

    int exclude = recursion(nums, n, index + 1);

    return dp[index] = max(include, exclude);
}

int tabulation(vector<int>& nums) {

    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for( int i = 1; i < n; i++ ) {
        int curr = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = curr;
    }

    // include 
    return prev1;
}


int rob(vector<int>& nums) {
    int n = nums.size();

    // using recursion
    // return recursion(nums, n, 0);

    // using memorization
    // vector<int> dp(n, -1);
    // return memorization(nums, n, 0, dp);

    // using tabulation
    return tabulation(nums);
}

int main() {

    vector<int> nums = { 1,2,3,1 };

    cout << rob(nums);

    return 0;
}