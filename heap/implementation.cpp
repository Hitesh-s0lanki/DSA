#include <iostream>

using namespace std;

class Heap {
    int* arr;
    int size;
public:

    Heap() {
        arr = new int[100];
        size = 0;
    }

    void insertion(int val) {
        size++;
        int index = size;
        arr[index] = val;

        while( index > 1 ) {
            int parent = index / 2;

            if( arr[index] > arr[parent] ) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deletion() {
        // root node deleting 
        int index = 1;
        arr[index] = arr[size];
        size--;

        while( index < size ) {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            if( leftIndex <= size && arr[leftIndex] > arr[index] ) {
                swap(arr[leftIndex], arr[index]);
                index = leftIndex;
            }
            if( rightIndex <= size && arr[rightIndex] > arr[index] ) {
                swap(arr[rightIndex], arr[index]);
                index = rightIndex;
            } else { return; }
        }

    }

    void print() {
        for( int i = 1;i <= size;i++ ) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};



int main() {

    Heap h;

    h.insertion(20);
    h.insertion(30);
    h.insertion(40);
    h.insertion(50);
    h.insertion(60);

    h.print();

    h.deletion();

    h.print();

    return 0;
}