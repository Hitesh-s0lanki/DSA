#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;

    if( leftIndex < n && arr[leftIndex] < arr[smallest] ) {
        smallest = leftIndex;
    }

    if( rightIndex < n && arr[rightIndex] < arr[smallest] ) {
        smallest = rightIndex;
    }

    if( smallest != i ) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int>& arr) {

    int n = arr.size();

    for( int i = (n / 2) - 1; i >= 0; i-- ) {
        heapify(arr, n, i);
    }

    return arr;
}

void print(vector<int> ans) {
    for( auto i : ans ) {
        cout << i << ", ";
    }
    cout << endl;
}

int main() {

    vector<int> arr = { 9, 3, 2, 6, 7 };

    print(buildMinHeap(arr));

    return 0;
}