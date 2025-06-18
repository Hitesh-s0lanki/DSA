#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int isValid(vector<int>& nums, int n, int mid, int p) {

    int i = 0;
    int countPairs = 0;

    while( i < n - 1 && countPairs < p ) {
        if( nums[i + 1] - nums[i] <= mid ) {
            countPairs++;
            i = i + 2;
        } else {
            i++;
        }
    }

    return countPairs >= p;
}

int minimizeMax(vector<int>& nums, int p) {

    // Size of the Array
    int n = nums.size();

    // binary search problem sort the array
    sort(nums.begin(), nums.end());

    //start the binary search
    int l = 0;
    int r = nums[n - 1] - nums[0];

    int result = INT_MAX;

    while( l <= r ) {

        int mid = l + (r - l) / 2;

        if( isValid(nums, n, mid, p) ) {
            result = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }

    }

    return result;
}

int main() {

    vector<int> nums = { 10,1,2,7,1,3 };
    int p = 2;

    cout << minimizeMax(nums, p);

    return 0;
}