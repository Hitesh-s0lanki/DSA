#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {

    int largest = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;

    if( leftIndex < n && arr[leftIndex] > arr[largest] ) {
        largest = leftIndex;
    }

    if( rightIndex < n && arr[rightIndex] > arr[largest] ) {
        largest = rightIndex;
    }

    if( largest != i ) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int>& a, vector<int>& b, int n, int m) {
    // create a new array by merging both
    vector<int> ans;
    for( int i : a )
        ans.push_back(i);
    for( int i : b )
        ans.push_back(i);

    // make a make heap of it 
    int size = ans.size();
    for( int i = size / 2 - 1; i >= 0; i-- ) {
        heapify(ans, size, i);
    }

    return ans;
}

void print(vector<int> ans) {
    for( int i : ans ) {
        cout << i << "\t";
    }
    cout << endl;
}

int main() {

    vector<int> a = { 10, 5, 6, 2 };
    vector<int> b = { 12, 7, 9 };

    print(mergeHeaps(a, b, a.size(), b.size()));

    return 0;
}