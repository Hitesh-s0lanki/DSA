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

void moveZeroes(vector<int>& nums) {

    int n = nums.size();

    int i = 0;
    int j = 1;

    while( i < n && j < n ) {
        if( nums[i] == 0 && nums[j] != 0 ) {
            swap(nums[i], nums[j]);
            i++;
        } else if( nums[i] != 0 ) {
            i++;
        }
        j++;
    }
}

int main() {

    vector<int> nums = { 4,2,4,0,0,3,0,5,1,0 };

    moveZeroes(nums);

    print(nums);

    return 0;
}