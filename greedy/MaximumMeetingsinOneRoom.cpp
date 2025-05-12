#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second; // Sort by end time
}

vector<int> maxMeetings(int n, vector<int>& start, vector<int>& end) {
    vector<pair<pair<int, int>, int>> meetings;

    for( int i = 0; i < n; i++ ) {
        meetings.push_back({ {start[i], i + 1}, end[i] }); // {{start, index}, end}
    }

    sort(meetings.begin(), meetings.end(), compare);

    vector<int> ans;
    int lastEnd = 0;

    for( int i = 0; i < n; i++ ) {
        int s = meetings[i].first.first;
        int idx = meetings[i].first.second;
        int e = meetings[i].second;

        if( s > lastEnd ) {
            ans.push_back(idx);
            lastEnd = e;
        }
    }

    sort(ans.begin(), ans.end()); // optional: sort for output consistency

    return ans;
}

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int main() {

    // vector<int> start = { 1,3,0,5,8,5 };
    // vector<int> end = { 2,4,6,7,9,9 };
    vector<int> start = { 12, 6, 16, 12, 6, 9, 16, 6, 17, 5 };
    vector<int> end = { 17, 13, 16, 18, 17, 10, 18, 12, 18, 11 };
    // vector<int> start = { 1, 3, 0, 5, 8, 5 };
    // vector<int> end = { 2, 4, 6, 7, 9, 9 };

    print(maxMeetings(start.size(), start, end));

    return 0;
}