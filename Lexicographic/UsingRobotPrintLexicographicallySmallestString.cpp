#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string robotWithString(string s) {

    int n = s.length();

    // store the minimum character at the left 
    vector<char> minCharToLeft(n);
    minCharToLeft[n - 1] = s[n - 1];

    for( int i = n - 2; i >= 0; i-- )
        minCharToLeft[i] = min(s[i], minCharToLeft[i + 1]);

    stack<char> t;
    string paper;

    int i = 0;
    while( i < n ) {
        t.push(s[i]);

        char minChar = (i + 1) != n ? minCharToLeft[i + 1] : s[i];

        // check if there is any min char to the left of string
        while( !t.empty() && t.top() <= minChar ) {
            paper.push_back(t.top());
            t.pop();
        }

        i++;
    }

    // push all the remaining character
    while( !t.empty() ) {
        paper.push_back(t.top());
        t.pop();
    }

    return paper;
}

int main() {

    cout << robotWithString("bdda");

    return 0;
}