// important 

#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {

    int n = nums.size();

    int sum = 0;
    int ans = 0;

    unordered_map<int, int> map;
    map[0] = 1;

    for( int i = 0; i < n; i++ ) {

        sum += nums[i];

        if( map.find(sum - k) != map.end() ) {
            ans += map[sum - k];
        }

        if( map.find(sum) != map.end() ) {
            map[sum] = map[sum] + 1;
        } else {
            map[sum] = 1;
        }
    }

    return ans;
}

int main() {
    vector<int> a = { 0,0,0,0,0,0,0,0,0,0 };
    long long k = 0;

    cout << "The Subarray count with k Sum : " << subarraySum(a, k);

    return 0;
}