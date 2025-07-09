#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> ans) {
    for( int i : ans )
        cout << i << "\t";
}

int findLHS(vector<int>& nums) {

    const int n = nums.size();

    sort(nums.begin(), nums.end());

    int maxLen = 0;

    for( int l = 0, r = 0; r < n; r++ ) {
        const int x = nums[r];

        while( l < r && nums[l] < x - 1 ) l++;

        if( nums[l] == x - 1 ) maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}

int main() {

    vector<int> nums = { 1,3,2,2,5,2,3,7 };

    cout << findLHS(nums);

    return 0;
}