#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(int n, stack<int>& s) {
    if( s.empty() ) {
        s.push(n);
        return;
    }

    int peek = s.top();
    s.pop();

    insertAtBottom(n, s);

    s.push(peek);
}

void reverseStack(stack<int>& s) {
    if( s.empty() ) return;

    int top = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(top, s);
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

    reverseStack(s);

    print(s);

    return 0;
}