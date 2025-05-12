#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> betterApproach(vector<int>& nums, int target) {

    int n = nums.size();

    unordered_map<int, int> arrayMap;
    vector<int> ans;

    for( int i = 0; i < n; i++ ) {
        int  rem = target - nums[i];

        if( arrayMap.find(rem) != arrayMap.end() ) {
            // found the rem
            ans.push_back(arrayMap[rem]);
            ans.push_back(i);
            return ans;
        }

        arrayMap[nums[i]] = i;
    }

    return ans;
}

vector<int> optimalApproach(vector<int>& nums, int target) {

    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<int> ans;

    int i = 0;
    int j = n - 1;

    while( i < j ) {
        int sum = nums[i] + nums[j];
        if( sum == target ) {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            return ans;
        } else if( sum < target ) {
            i++;
        } else {
            j--;
        }
    }

    return ans;
}

vector<int> twoSum(vector<int>& nums, int target) {
    return betterApproach(nums, target);
}

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int main() {

    vector<int> nums = { 2,7,11,15 };
    int target = 9;

    print(twoSum(nums, target));

    return 0;
}