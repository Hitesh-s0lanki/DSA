#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int findMinDiff(vector<int>& a, int m) {

    int n = a.size();

    sort(a.begin(), a.end());

    int i = 0;
    int j = m - 1;

    int mini = INT_MAX;

    while( j < n ) {

        mini = min(mini, a[j] - a[i]);

        i++;
        j++;
    }

    return mini;
}

int main() {

    vector<int> a = { 3, 4, 1, 9, 56, 7, 9, 12 };
    int m = 5;

    cout << findMinDiff(a, m);

    return 0;
}