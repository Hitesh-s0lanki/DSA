// Time Complexity -> O(2^n)
// Space Complexity -> O(k) for recursion stack and O(m * k) for result storage

#include <iostream>
#include<vector> 
#include <algorithm>

// candidates = [10, 1, 2, 7, 6, 1, 5]
// target = 8

// [] => 8
// ├── [1] => 7
// │   ├── [1,1] => 6
// │   │   ├── [1,1,2] => 4
// │   │   │   └── ...
// │   │   ├── [1,1,5] => 1
// │   │   └── ...
// │   ├── [1,2] => 5
// │   │   ├── [1,2,5] => 0 ✅ (Added to answer)
// │   │   └── ...
// │   ├── [1,5] => 2
// │   ├── [1,6] => 1
// │   └── ...
// ├── [2] => 6
// │   ├── [2,5] => 1
// │   ├── [2,6] => 0 ✅ (Added to answer)
// │   └── ...
// ├── [5] => 3
// ├── [6] => 2
// ├── [7] => 1
// └── [10] => -2 (Invalid)


using namespace std;

void print(vector<vector<int>> ans) {
    for( auto i : ans ) {
        for( auto j : i ) {
            cout << j << "\t";
        }
        cout << endl;
    }
}

void solve(vector<int>& candidates, int target, vector<int>& val, int index, vector<vector<int>>& ans) {
    if( target == 0 ) {
        ans.push_back(val);
        return;
    }

    for( int i = index; i < candidates.size(); i++ ) {
        // Skip duplicates
        if( i > index && candidates[i] == candidates[i - 1] ) continue;

        if( candidates[i] > target ) break; // No point in continuing if number is larger than target

        val.push_back(candidates[i]);
        solve(candidates, target - candidates[i], val, i + 1, ans); // i+1 because each number can only be used once
        val.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> val;

    sort(candidates.begin(), candidates.end());

    solve(candidates, target, val, 0, ans);

    return ans;
}

int main() {

    vector<int> candidates = { 10,1,2,7,6,1,5 };
    int target = 8;

    print(combinationSum2(candidates, target));

    return 0;
}