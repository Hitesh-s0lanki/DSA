#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {

    int n = temperatures.size();

    stack<int> stack;
    stack.push(0);

    vector<int> ans(n);

    for( int i = n - 1; i >= 0; i-- ) {
        while( !stack.empty() && stack.top() != 0 && temperatures[stack.top()] <= temperatures[i] ) {
            stack.pop();
        }

        if( stack.top() == 0 ) {
            ans[i] = stack.top();
        } else {
            ans[i] = stack.top() - i;
        }
        stack.push(i);
    }

    return ans;
}

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int main() {

    vector<int> temperatures = { 73,74,75,71,69,72,76,73 };

    print(dailyTemperatures(temperatures));

    return 0;
}