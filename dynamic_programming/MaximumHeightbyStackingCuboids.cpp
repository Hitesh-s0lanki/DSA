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

bool check(vector<int>& base, vector<int>& newBox) {
    if( newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2] )
        return true;
    return false;
}

int solve(vector<vector<int>>& cuboids) {
    int n = cuboids.size();

    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for( int curr = n - 1; curr >= 0; curr-- ) {
        for( int prev = curr - 1; prev >= -1; prev-- ) {

            int take = 0;
            if( prev == -1 || check(cuboids[curr], cuboids[prev]) )
                take = cuboids[curr][2] + nextRow[curr + 1];

            // exclude
            int notTake = nextRow[prev + 1];

            currRow[prev + 1] = max(take, notTake);
        }
        nextRow = currRow;
    }

    return nextRow[0];
}

int maxHeight(vector<vector<int>>& cuboids) {

    // sort the each vector as dimensions is not complusory
    for( auto& a : cuboids )
        sort(a.begin(), a.end());


    // sort the complete cuboids vector by there w & l
    sort(cuboids.begin(), cuboids.end());

    // use the Longest Increasing Subsequence 
    int ans = solve(cuboids);

    return ans;
}

int main() {

    vector<vector<int>> cuboids = { {50,45,20},{95,37,53},{45,23,12} };

    cout << maxHeight(cuboids);

    return 0;
}