#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int maxMeetings(vector<int>& start, vector<int>& end) {

    int n = start.size();
    vector<pair<int, int>> meetings;

    for( int i = 0; i < n; i++ ) {
        meetings.push_back(make_pair(start[i], end[i]));
    }

    sort(meetings.begin(), meetings.end(), compare);

    int cnt = 1;
    int ansEnd = meetings[0].second;

    for( int i = 1; i < n; i++ ) {
        pair<int, int> meeting = meetings[i];

        if( meeting.first > ansEnd ) {
            ansEnd = meeting.second;
            cnt++;
        }

    }

    return cnt;
}

int main() {

    vector<int> start = { 1, 3, 0, 5, 8, 5 };
    vector<int> end = { 2, 4, 6, 7, 9, 9 };

    cout << maxMeetings(start, end);

    return 0;
}