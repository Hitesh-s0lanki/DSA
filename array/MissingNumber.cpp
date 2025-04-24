#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> nums) {
    for( int num : nums ) {
        cout << num << "\t";
    }
    cout << endl;
}

void reverse(vector<int>& nums, int start, int end)
{
    while( start <= end )
    {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

int missingNumber(vector<int>& nums) {

}

int main() {

    vector<int> nums = { 2, 1 };

    cout << missingNumber(nums);

    return 0;
}