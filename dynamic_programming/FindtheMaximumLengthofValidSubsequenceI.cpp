#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumLength(vector<int>& nums) {
    int countEven = 0, countOdd = 0;
    for( int num : nums ) {
        if( num % 2 == 0 ) countEven++;
        else countOdd++;
    }

    // Try building alternating parity subsequence
    int altLen = 1; // At least one number
    int prevParity = nums[0] % 2;

    for( int i = 1; i < nums.size(); ++i ) {
        int currParity = nums[i] % 2;
        if( currParity != prevParity ) {
            altLen++;
            prevParity = currParity;
        }
    }

    return max({ countEven, countOdd, altLen });
}

int main() {

    vector<int> nums = { 1,2,1,1,2,1,2 };

    cout << maximumLength(nums);

    return 0;
}