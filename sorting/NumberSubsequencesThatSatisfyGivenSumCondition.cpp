#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int numSubseq(vector<int>& nums, int target) {

    int n = nums.size();
    int mod = 1e9 + 7;

    sort(nums.begin(), nums.end());

    vector<int> power(n, 1);
    for( int i = 0; i < n; i++ )
        power[i] = pow(2, i);

    int i = 0;
    int j = n - 1;

    int result = 0;

    while( i < j ) {
        int topper = nums[i] + nums[j];
        if( topper <= target ) {
            result = (result + power[j - i]) % mod;
            i++;
        } else j--;
    }

    return result;
}

int main() {

    vector<int> nums = { 3,5,6,7 };
    int target = 9;

    cout << numSubseq(nums, target);

    return 0;
}