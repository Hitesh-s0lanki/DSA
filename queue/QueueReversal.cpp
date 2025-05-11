#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void reverse(queue<int>& q) {

    if( q.empty() ) return;

    int top = q.front();
    q.pop();

    reverse(q);

    q.push(top);
}


queue<int> reverseQueue(queue<int>& q) {
    reverse(q);
    return q;
}

void print(queue<int> q) {
    while( !q.empty() ) {
        cout << q.front() << "\t";
        q.pop();
    }
}

int main() {

    vector<int> nums = { 4, 3, 1, 10, 2, 6 };

    queue<int> q;
    for( auto i : nums )
        q.push(i);

    print(reverseQueue(q));

    return 0;
}