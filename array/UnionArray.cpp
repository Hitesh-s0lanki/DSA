#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> nums) {
    for( int num : nums ) {
        cout << num << "\t";
    }
    cout << endl;
}

vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;

    int n1 = nums1.size();
    int n2 = nums2.size();

    int i = 0;
    int j = 0;

    while( i != n1 && j != n2 ) {

        int n = ans.size();

        if( nums1[i] <= nums2[j] ) {
            if( n == 0 || nums1[i] != ans[n - 1] ) {
                ans.push_back(nums1[i++]);
            } else {
                i++;
            }

        } else {
            if( n == 0 || nums2[j] != ans[n - 1] ) {
                ans.push_back(nums2[j++]);
            } else {
                j++;
            }
        }
    }


    while( i < n1 ) {
        int n = ans.size();
        if( n == 0 || nums1[i] != ans[n - 1] ) {
            ans.push_back(nums1[i]);
        }
        i++;
    }

    while( j < n2 ) {
        int n = ans.size();
        if( n == 0 || nums2[j] != ans[n - 1] ) {
            ans.push_back(nums2[j]);
        }
        j++;
    }

    return ans;
}

int main() {

    vector<int> nums1 = { 3, 4, 6, 7, 9, 9 };
    vector<int> nums2 = { 1, 5, 7, 8, 8 };

    vector<int> ans = unionArray(nums1, nums2);

    print(ans);

    return 0;
}