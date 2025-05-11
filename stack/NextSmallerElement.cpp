#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmallerElement(vector<int>& arr, int n) {
    stack<int> stack;
    stack.push(-1);

    vector<int> ans(n);

    for( int i = n - 1; i >= 0; i-- ) {
        while( !stack.empty() && stack.top() > arr[i] ) {
            stack.pop();
        }

        int top = stack.top();
        ans[i] = top;

        stack.push(arr[i]);
    }

    return ans;
}

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int main() {

    vector<int> arr = { 2, 1, 4, 3 };
    int n = arr.size();

    print(nextSmallerElement(arr, n));

    return 0;
}