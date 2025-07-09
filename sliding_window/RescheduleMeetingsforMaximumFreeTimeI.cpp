#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {

    int n = startTime.size();

    // store the freetime in the array to iterate in it
    vector<int> freeTime;

    // first time interval
    freeTime.push_back(startTime[0]);

    for( int i = 1; i < n; i++ )
        freeTime.push_back(startTime[i] - endTime[i - 1]);

    // end time free duration
    freeTime.push_back(eventTime - endTime[n - 1]);

    // now us the desi sliding window concept
    int i = 0;
    int j = 0;

    int maxSum = 0;
    int currSum = 0;

    n = freeTime.size();

    while( j < n ) {
        currSum = freeTime[j];

        if( i < n && j - i + 1 > k + 1 ) {
            currSum -= freeTime[i];
            i++;
        }

        maxSum = max(maxSum, currSum);
        j++;
    }

    return maxSum;
}

int main() {

    int eventTime = 5, k = 1;
    vector<int> startTime = { 1,3 }, endTime = { 2,5 };

    cout << maxFreeTime(eventTime, k, startTime, endTime);

    return 0;
}