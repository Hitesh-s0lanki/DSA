#include <iostream>
#include <stack>

using namespace std;

bool findRedundantBrackets(string& s) {
    stack<int> stack;

    for( int i = 0; i < s.length(); i++ ) {
        char ch = s[i];

        if( ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ) {
            stack.push(ch);
        } else if( ch == ')' ) {
            bool isOperator = false;

            while( !stack.empty() && stack.top() != '(' ) {
                char top = stack.top();
                if( top == '+' || top == '-' || top == '*' || top == '/' ) {
                    isOperator = true;
                }
                stack.pop();
            }

            if( !isOperator || stack.empty() ) return true;

            stack.pop();

        }
    }

    return false;
}

int main() {
    string s = "((a/b))";

    cout << findRedundantBrackets(s);
    return 0;
}