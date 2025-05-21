// Time Complexity -> O(n log n)
// Space Complexity -> O(N)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<int>>& ans) {
    for( auto i : ans ) {
        for( int j : i )
            cout << j << "\t";
        cout << endl;
    }
}

bool compare(vector<int> a, vector<int> b) {
    if( a[0] == b[0] )
        return a[1] > b[1];

    return a[0] < b[0];
}

int maxEnvelopes(vector<vector<int>>& envelopes) {

    // sort the envelopes 
    sort(envelopes.begin(), envelopes.end(), compare);

    // binary + dp solution
    int n = envelopes.size();
    vector<int> ans;
    ans.push_back(envelopes[0][1]);

    for( int i = 1; i < n; i++ ) {
        if( envelopes[i][1] > ans.back() )
            ans.push_back(envelopes[i][1]);
        else {
            // just usse jada bada vala index
            int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
            ans[index] = envelopes[i][1];
        }
    }

    return ans.size();
}

int main() {

    vector<vector<int>> envelopes = { {5,4},{6,4},{6,7},{2,3} };

    cout << maxEnvelopes(envelopes);

    return 0;
}