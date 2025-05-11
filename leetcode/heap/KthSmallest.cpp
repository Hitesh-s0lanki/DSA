#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    int n = arr.size();
    // code here
    priority_queue<int> pq;

    for( int i = 0; i < k; i++ ) {
        pq.push(arr[i]);
    }

    for( int i = k; i < n; i++ ) {
        if( pq.top() > arr[i] ) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}


int main() {

    vector<int> arr = { 7, 10, 4, 3, 20, 15 };

    cout << "The k smallest element is : " << kthSmallest(arr, 3);

    return 0;
}


// The dominant cost comes from the heap‐operations (push/pop), each of which takes $O(\log k)$ when the heap size is $k$. You do:

// 1. **Build the heap** with the first $k$ elements:
//    $k$ pushes ⇒ $k \times O(\log k) = O(k\log k)$

// 2. **Process the remaining** $n-k$ elements:
//    For each one you might do a pop+push (in the worst case) ⇒ $(n-k)\times O(\log k) = O((n-k)\log k)$

// Putting those together gives:

// $$
// O(k\log k) + O((n-k)\log k) = O(n\log k).
// $$

// So **time complexity** is

// $$
// \boxed{O(n\log k)}
// $$

// because you perform at most $n$ heap operations, each costing $O(\log k)$.
