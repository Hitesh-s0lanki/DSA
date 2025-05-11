#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int findMinimumCost(string str) {
    stack<int> stack;

    int reverseCount = 0;

    for( int i = 0; i < str.length(); i++ ) {
        if( !stack.empty() && str[i] == '}' ) {
            stack.pop();
            reverseCount--;
        } else {
            stack.push(str[i]);
            reverseCount++;
        }
    }

    int openBrac = abs(stack.size() - reverseCount);

    cout << reverseCount << endl;

    if( reverseCount == openBrac ) {
        return reverseCount / 2;
    }

    return openBrac % 2 == 0 ? abs(reverseCount - (stack.size() / 2)) : -1;
}
int main() {

    string str = "{}}{}}";

    cout << findMinimumCost(str);

    return 0;
}