#include <iostream>
#include<vector>

using namespace std;

void print(vector<vector<int>> ans) {
    for( auto i : ans ) {
        for( auto j : i ) {
            cout << j << "\t";
        }
        cout << endl;
    }
}

void solve(vector<int>& candidates, int target, vector<int> val, int index, vector<vector<int>>& ans) {

    // check is the answer meet aur not 
    if( target == 0 ) {
        ans.push_back(val);
        return;
    }

    // Base case 
    if( target < 0 || index >= candidates.size() ) return;

    // inclusion
    val.push_back(candidates[index]);
    solve(candidates, target - candidates[index], val, index, ans);
    val.pop_back();

    // exlcusion
    solve(candidates, target, val, index + 1, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<vector<int>> ans;
    vector<int> val;

    solve(candidates, target, val, 0, ans);

    return ans;
}

int main() {

    vector<int> candidates = { 2,3,6,7 };
    int target = 7;

    print(combinationSum(candidates, target));

    return 0;
}