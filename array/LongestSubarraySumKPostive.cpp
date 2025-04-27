#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int getLongestSubarray(vector<int>& nums, int k) {
    // Optimal approach
    int n = nums.size();

    int left = 0;
    int right = 0;
    int sum = nums[0];
    int longestSubarray = 0;

    while( right < n ) {
        // reduce the sum <= k
        while( left <= right && sum > k ) {
            sum -= nums[left];
            left++;
        }

        if( sum == k )
            longestSubarray = max(longestSubarray, right - left + 1);

        right++;

        if( right < n )
            sum += nums[right];
    }

    return longestSubarray;
}

int main() {

    vector<int> a = { 2, 3, 5, 1, 9 };
    long long k = 10;

    cout << "The longest Subarray in only positive is : " << getLongestSubarray(a, k);

    return 0;
}