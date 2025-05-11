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

void maxHeap(vector<int>& arr, int n) {
    for( int i = n / 2; i >= 0; i-- ) {
        heapify(arr, n, i);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    maxHeap(arr, n);

    for( int i = n - 1; i > 0; i-- ) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

void print(vector<int> ans) {
    for( auto i : ans ) {
        cout << i << ", ";
    }
    cout << endl;
}

int main() {

    vector<int> arr = { 9, 3, 2, 6, 7 };

    heapSort(arr);

    print(arr);

    return 0;
}