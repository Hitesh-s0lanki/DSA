#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> ans) {
    for( auto i : ans ) {
        for( auto j : i ) {
            cout << j << "\t";
        }
        cout << endl;
    }
}

void solve(int k, int n, int index, vector<int>& val, vector<vector<int>>& ans) {
    if( n == 0 ) {
        if( val.size() == k )
            ans.push_back(val);
        return;
    }

    if( n < 0 || val.size() >= k || index > 9 ) return;

    // include 
    val.push_back(index);
    solve(k, n - index, index + 1, val, ans);
    val.pop_back();

    // exclude 
    solve(k, n, index + 1, val, ans);
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> val;

    solve(k, n, 1, val, ans);

    return ans;
}

int main() {

    print(combinationSum3(3, 7));

    return 0;
}