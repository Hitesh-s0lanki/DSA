#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>& arr, int start, int end) {
    while( start < end ) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

vector<int> performOperations(vector<int> arr, vector<vector<int>> operations) {

    int n = operations.size();

    for( int i = 0; i < n; i++ ) {
        int element1 = operations[i][0];
        int element2 = operations[i][1];

        reverse(arr, element1, element2);

        // int indexElement1 = 0;
        // int indexElement2 = 0;

        // for( int i = 0; i < arr.size(); i++ ) {
        //     if( arr[i] == element1 ) {
        //         indexElement1 = i;
        //     } else if( arr[i] == element2 ) {
        //         indexElement2 = i;
        //     }
        // }

        // if( indexElement1 > indexElement2 ) {
        //     reverse(arr, indexElement2, indexElement1);
        // } else {
        //     reverse(arr, indexElement1, indexElement2);
        // }

    }

    return arr;
}

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int main() {

    vector<int> arr = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

    vector<vector<int>> operations = {
        {0, 9},
        {4, 5},
        {3, 6},
        {2, 7},
        {1, 8},
        {0, 9}
    };

    print(performOperations(arr, operations));

    return 0;
}