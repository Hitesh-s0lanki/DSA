// Time Complexity -> O(N)
// Space Complexity -> O(1)

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int recursion(vector<int>& nums, int n, int index) {

    if( index >= n ) return 0;

    // inclusion
    int inc = recursion(nums, n, index + 2) + nums[index];

    // exclusion
    int exc = recursion(nums, n, index + 1);

    return max(inc, exc);
}

int memorization(vector<int>& nums, vector<int>& dp, int index) {
    if( index < 0 ) return 0;

    // memorization
    if( dp[index] != -1 ) return dp[index];

    // inclusion
    int inc = memorization(nums, dp, index - 2) + nums[index];

    // exclusion
    int exc = memorization(nums, dp, index - 1);

    return dp[index] = max(inc, exc);
}

int tabulation(vector<int>& nums) {
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for( int i = 1; i < n; i++ ) {
        int curr = max(prev2 + nums[i], prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return max(prev2, prev1);
}

int maximumNonAdjacentSum(vector<int>& nums) {

    int n = nums.size();

    // using recursion 
    // return recursion(nums, n, 0);

    //using memorization
    // vector<int> dp(n, -1);
    // int ans = memorization(nums, dp, n - 1);

    // return ans;

    return tabulation(nums);
}


int main() {

    // vector<int> nums = { 19, 9, 8, 20 };
    // vector<int> nums = { 1, 2, 4 };
    // vector<int> nums = { 2, 1, 4, 9 };
    vector<int> nums = { 1, 2, 3, 1, 3, 5, 8, 1, 9 };

    cout << maximumNonAdjacentSum(nums);

    return 0;
}