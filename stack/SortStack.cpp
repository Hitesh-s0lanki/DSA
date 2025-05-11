#include <iostream>
#include <stack>

using namespace std;

void insertAtRight(int n, stack<int>& s) {
    if( s.empty() ) {
        s.push(n);
        return;
    }

    int peek = s.top();

    if( peek > n ) {
        s.push(n);
    } else {
        s.pop();
        insertAtRight(n, s);
        s.push(peek);
    }
}

void sortStack(stack<int>& s) {
    if( s.empty() ) return;

    int top = s.top();
    s.pop();

    sortStack(s);

    insertAtRight(top, s);
}

void print(stack<int> s) {
    while( !s.empty() ) {
        cout << s.top() << "\t";
        s.pop();
    }
    cout << endl;
}

int main() {

    stack<int> s;
    s.push(2);
    s.push(1);
    s.push(3);

    print(s);

    sortStack(s);

    print(s);

    return 0;
}