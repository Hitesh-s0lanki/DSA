#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int recursion(vector<int>& nums1, vector<int>& nums2, int n, int index, bool swapped) {

    if( index >= n ) return 0;

    int ans = INT_MAX;

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    if( swapped ) swap(prev1, prev2);

    // no swap case
    if( nums1[index] > prev1 && nums2[index] > prev2 )
        ans = recursion(nums1, nums2, n, index + 1, false);

    // swap the number if possible
    if( nums1[index] > prev2 && nums2[index] > prev1 )
        ans = min(ans, 1 + recursion(nums1, nums2, n, index + 1, true));

    return ans;
}

int memorization(vector<int>& nums1, vector<int>& nums2, int n, int index, bool swapped, vector<vector<int>>& dp) {

    if( index >= n ) return 0;

    if( dp[index][swapped] != -1 ) return dp[index][swapped];

    int ans = INT_MAX;

    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];

    if( swapped ) swap(prev1, prev2);

    // no swap case
    if( nums1[index] > prev1 && nums2[index] > prev2 )
        ans = memorization(nums1, nums2, n, index + 1, false, dp);

    // swap the number if possible
    if( nums1[index] > prev2 && nums2[index] > prev1 )
        ans = min(ans, 1 + memorization(nums1, nums2, n, index + 1, true, dp));

    return dp[index][swapped] = ans;
}

int tabulation(vector<int>& nums1, vector<int>& nums2, int n) {

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for( int index = n - 1; index >= 1; index-- ) {
        for( int swapped = 1; swapped >= 0; swapped-- ) {
            int ans = INT_MAX;

            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];

            if( swapped ) swap(prev1, prev2);

            // no swap case
            if( nums1[index] > prev1 && nums2[index] > prev2 )
                ans = next[0];

            // swap the number if possible
            if( nums1[index] > prev2 && nums2[index] > prev1 )
                ans = min(ans, 1 + next[1]);

            curr[swapped] = ans;
        }
        next = curr;
    }

    return curr[0];
}

int minSwap(vector<int>& nums1, vector<int>& nums2) {

    // step 1 : put -1 in the front column
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    // size of the new array
    int n = nums1.size();

    // using recursion
    // return recursion(nums1, nums2, n, 1, false);

    // using memorization
    // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    // return memorization(nums1, nums2, n, 1, false, dp);

    // using tabulation
    return tabulation(nums1, nums2, n);
}

int main() {

    vector<int> nums1 = { 1,3,5,4 };
    vector<int> nums2 = { 1,2,3,7 };

    cout << minSwap(nums1, nums2);

    return 0;
}