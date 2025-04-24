#include <iostream>
#include <vector>

using namespace std;

void print( vector<int> nums ) {
    for( int num : nums ) {
        cout << num << "\t";
    }
    cout << endl;
}

void reverse( vector<int>& nums, int start, int end )
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

bool check( vector<int>& nums ) {

    int cnt = 0;
    int n = nums.size();

    for( int i = 1; i < n; i++ ) {
        if( nums[i - 1] > nums[i] ) {
            cnt++;
        }
    }

    if( nums[n - 1] > nums[0] ) {
        cnt++;
    }

    return cnt <= 1;
}

int main() {

    vector<int> nums = { 2,1,3,4 };

    check( nums );

    return 0;
}