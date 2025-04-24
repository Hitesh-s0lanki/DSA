#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestElement( vector<int>& nums ) {
        int largest = nums[0];

        for( int i = 1; i < nums.size(); i++ ) {
            if( largest < nums[i] ) {
                largest = nums[i];
            }
        }

        return largest;
    }
};

int main() {

    vector<int> nums = { 1, 2, 3, 4, 5 };

    Solution sol;

    int largest = sol.largestElement( nums );
    cout << "The largest element is: " << largest << endl;

    return 0;
}