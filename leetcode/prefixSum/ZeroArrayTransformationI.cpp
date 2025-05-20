#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& ans) {
    for( int i : ans )
        cout << i << "\t";
    cout << endl;
}

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();

    vector<int> prefix(n + 1, 0);
    int ans = 1;

    for( int i = 0; i < n; i++ ) {
        if( nums[i] > 0 )
            break;
        else if( nums[i] == 0 && i == n - 1 ) return 0;
    }

    // step 1 : prepare the prefix tree with the operations
    for( auto query : queries ) {
        int start = query[0];
        int end = query[1];

        int val = query[2];

        prefix[start] += val;
        prefix[end + 1] += -(val);

        // step 2 : do the prefix sum of prefix array
        vector<int> temp(prefix.begin(), prefix.end());
        for( int i = 1; i < n; i++ ) {
            temp[i] = temp[i - 1];
        }

        // step 3 : do the difference between ans
        int cnt = 0;
        for( int i = 0; i < n; i++ ) {
            if( nums[i] - temp[i] > 0 )
                break;
            else
                cnt++;
        }

        if( cnt == n ) return ans;

        ans++;
    }

    return -1;
}

int main() {
    // vector<int> nums = { 4,3,2,1 };
    // vector<vector<int>> queries = { {1,3},{0,2} };

    // vector<int> nums = { 2,0,2 };
    // vector<vector<int>> queries = { {0,2,1},{0,2,1},{1,1,3} };

    vector<int> nums = { 0 };
    vector<vector<int>> queries = { {0,0,5},{0,0,1},{0,0,3},{0,0,2} };

    cout << minZeroArray(nums, queries);

    return 0;
}