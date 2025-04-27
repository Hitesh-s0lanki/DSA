#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int longestAlternatingSubarray(vector<int>& nums, int threshold) {

    int n = nums.size();

    int i = 0;
    int j = 0;

    // true - even
    // false - odd
    int maxLen = 0;

    while( j < n && i < n ) {
        // checking for First element each time enter 
        if( nums[i] % 2 != 0 || nums[i] > threshold ) {
            i++;
            j = i;
        }

        bool even = (i % 2 == 0 && j % 2 != 0) || (i % 2 != 0 && j % 2 == 0) ? false : true;

        if( j <= (n - 1) ) {
            if( (nums[j] % 2 != 0 && even) || (nums[j] % 2 == 0 && !even) || (nums[j] > threshold) ) {
                cout << "I m here " << j << endl;
                maxLen = max(maxLen, j - i);
                i = j;
            }
        }

        if( j == (n - 1) ) {
            // last index handle 
            if( i == (n - 1) && nums[i] % 2 == 0 && nums[i] <= threshold ) {
                maxLen = max(maxLen, 1);
            } else if( (nums[j] % 2 == 0 && even && nums[j] <= threshold) || (nums[j] % 2 != 0 && !even && nums[j] <= threshold) ) {
                maxLen = max(maxLen, j - i + 1);
            }
        }

        j++;
    }

    return maxLen;
}

int longestAlternatingSubarrayV2(vector<int>& nums, int threshold) {
    int n = nums.size();
    int maxLen = 0;
    int currentLen = 0;

    for( int i = 0; i < n; ++i ) {
        if( nums[i] > threshold || nums[i] % 2 != 0 ) {
            // reset if first number invalid
            currentLen = 0;
            continue;
        }

        currentLen = 1; // Start new subarray
        int parity = nums[i] % 2; // 0 if even, 1 if odd

        for( int j = i + 1; j < n; ++j ) {
            if( nums[j] > threshold || nums[j] % 2 == parity ) {
                break; // Break if threshold fail or no alternation
            }
            parity = nums[j] % 2;
            currentLen++;
        }

        maxLen = max(maxLen, currentLen);
    }

    return maxLen;
}

int main() {
    vector<int> nums = { 3, 2, 5, 4 };
    int threshold = 5;

    cout << "Longest Even Odd Subarray With Threshold : " << longestAlternatingSubarrayV2(nums, threshold);

    return 0;
}