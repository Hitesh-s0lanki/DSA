#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<int>> ans) {
    for( auto i : ans ) {
        for( int j : i ) {
            cout << j << "\t";
        }
        cout << endl;
    }
}

vector<vector<int>> divideArray(vector<int>& nums, int k) {

    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    for( int i = 0; i < n; i += 3 ) {
        if( nums[i + 2] - nums[i] > k ) {
            return {};
        }

        result.push_back({ nums[i], nums[i + 1], nums[i + 2] });
    }

    return result;
}

int main() {

    vector<int> nums = { 4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11 };

    print(divideArray(nums, 14));

    return 0;
}