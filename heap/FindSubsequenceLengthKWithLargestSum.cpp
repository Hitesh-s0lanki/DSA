#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<int> ans) {
    for( int i : ans )
        cout << i << "\t";
}

class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

vector<int> maxSubsequence(vector<int>& nums, int k) {

    int n = nums.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    vector<int> taken(n, 0);

    for( int i = 0; i < n; i++ ) {
        if( pq.size() < k ) {
            taken[i] = 1;
            pq.push({ nums[i], i });
        } else if( pq.top().first < nums[i] ) {
            taken[pq.top().second] = 0;
            pq.pop();
            pq.push({ nums[i], i });
            taken[i] = 1;
        }
    }

    vector<int> ans;

    for( int i = 0; i < n; i++ ) {
        if( taken[i] != 0 )
            ans.push_back(nums[i]);
    }

    return ans;
}

int main() {

    vector<int> nums = { -1,-2,3,4 };
    int k = 2;

    print(maxSubsequence(nums, k));

    return 0;
}