#include <iostream>

using namespace std;

bool isSorted(int arr[], int n) {

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    int arr[] = { 1, 2, 13, 4, 5 };

    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSorted(arr, n))
        cout << "Array is Sorted" << endl;
    else
        cout << "Array is not Sorted" << endl;


    return 0;
}