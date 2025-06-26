#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> ans) {
    for( int i : ans )
        cout << i << "\t";
    cout << endl;
}

vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> result;

    int n = nums.size();

    int start = 0;
    int end = n - 1;

    for( int i = 0; i < n; i++ ) {
        if( nums[i] == key ) {
            start = max(start, i - k);
            end = min(n - 1, i + k);

            while( start <= end ) {
                result.push_back(start);
                start++;
            }
        }
    }

    return result;
}

int main() {


    vector<int> nums = { 3,4,9,1,3,9,5 };
    print(findKDistantIndices(nums, 9, 1));

    return 0;
}