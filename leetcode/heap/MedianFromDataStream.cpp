#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int size;
    double median;

public:
    MedianFinder() { size = 0; }

    void addNum(int num) {
        if( maxHeap.empty() || maxHeap.top() >= num ) {
            maxHeap.push(num);
            if( maxHeap.size() > minHeap.size() + 1 ) {
                int top = maxHeap.top();
                maxHeap.pop();
                minHeap.push(top);
            }
        } else {
            minHeap.push(num);
            if( maxHeap.size() < minHeap.size() ) {
                int top = minHeap.top();
                minHeap.pop();
                maxHeap.push(top);
            }
        }
        size++;
    }

    double findMedian() {
        if( size == 0 )
            return median;

        if( size % 2 == 0 ) {
            return median = double(maxHeap.top() + minHeap.top()) / 2;
        }

        return median = maxHeap.top();
    }
};


int main() {
    return 0;
}