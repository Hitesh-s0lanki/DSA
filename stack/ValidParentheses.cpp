#include <iostream>
#include <stack>

using namespace std;

bool isValidParenthesis(string s) {
    stack<char> st;

    for( int i = 0; i < s.length(); i++ ) {

        if( !st.empty() && st.top() == '[' && s[i] == ']' ) {
            st.pop();
        } else if( !st.empty() && st.top() == '{' && s[i] == '}' ) {
            st.pop();
        } else if( !st.empty() && st.top() == '(' && s[i] == ')' ) {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    return st.empty();
}

int main() {

    string s = "[()]{}{[()()]()}";

    return 0;
}