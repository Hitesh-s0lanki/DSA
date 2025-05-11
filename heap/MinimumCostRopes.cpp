#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minCost(vector<int>& arr) {

    // create a min heap 
    priority_queue<int, vector<int>, greater<int>> pq;

    for( int i : arr )
        pq.push(i);

    int cost = 0;

    while( pq.size() > 1 ) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int temp = a + b;

        pq.push(temp);

        cost += temp;
    }

    return cost;
}

int main() {

    vector<int> arr = { 4, 3, 2, 6 };

    cout << minCost(arr);

    return 0;
}