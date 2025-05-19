// Time Complexity -> O(n * target)
// Space Complexity -> O(target)

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}


// Time Complexity -> O(n^target)
// Space -> O(target)
int recursion(vector<int>& nums, int target) {
    if( target == 0 ) return 1;

    if( target < 0 ) return 0;

    int ans = 0;

    for( auto i : nums )
        ans += recursion(nums, target - i);

    return ans;
}

int memorization(vector<int>& nums, int target, vector<int>& dp) {
    if( target == 0 ) return 1;

    if( target < 0 ) return 0;

    int ans = 0;

    for( auto i : nums )
        ans += memorization(nums, target - i, dp);

    return dp[target] = ans;
}

int tabulation(vector<int>& nums, int target) {

    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;

    for( int i = 1; i <= target; i++ ) {
        for( auto j : nums ) {
            if( i - j >= 0 ) {
                dp[i] += dp[i - j];
            }
        }
    }

    return dp[target];
}

int combinationSum4(vector<int>& nums, int target) {

    // using recursion
    // return recursion(nums, target);

    // using memorization
    // vector<int> dp(target + 1);
    // int ans = memorization(nums, target, dp);
    // print(dp);
    // return ans;

    // using tabulation
    return tabulation(nums, target);
}

int main() {

    vector<int> nums = { 1,2,3 };
    int target = 4;

    cout << combinationSum4(nums, target);

    return 0;
}