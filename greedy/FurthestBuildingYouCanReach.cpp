// Time Complexity = O(n log n)
// Space Complexity = O(n)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int n = heights.size();
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap

    for( int i = 0; i < n - 1; ++i ) {
        int gap = heights[i + 1] - heights[i];

        if( gap > 0 ) {
            pq.push(gap);

            if( pq.size() > ladders ) {
                int top = pq.top();
                pq.pop();

                bricks -= top;

                if( bricks < 0 ) return i;
            }
        }
    }

    return n - 1;
}

int main() {

    // vector<int> heights = { 4,2,7,6,9,14,12 };
    // int bricks = 5;
    // int ladders = 1;

    // vector<int> heights = { 4,12,2,7,3,18,20,3,19 };
    // int bricks = 10;
    // int ladders = 2;

    vector<int> heights = { 1,5,1,2,3,4,10000 };
    int bricks = 4;
    int ladders = 1;

    cout << furthestBuilding(heights, bricks, ladders);

    return 0;
}