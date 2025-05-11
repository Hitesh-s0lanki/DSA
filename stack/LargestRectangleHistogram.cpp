#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

vector<int> prevLargestElement(vector<int> heights, int n) {
    stack<int> stack;
    stack.push(-1);

    vector<int> ans(n);

    for( int i = 0; i < n; i++ ) {
        while( !stack.empty() && stack.top() != -1 && heights[stack.top()] > heights[i] ) {
            stack.pop();
        }

        ans[i] = stack.top();
        stack.push(i);
    }

    return ans;
}

vector<int> nextLargestElement(vector<int> heights, int n) {
    stack<int> stack;
    stack.push(-1);

    vector<int> ans(n);

    for( int i = n - 1; i >= 0; i-- ) {
        while( !stack.empty() && stack.top() != -1 && heights[stack.top()] > heights[i] ) {
            stack.pop();
        }

        ans[i] = stack.top();
        stack.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int>& heights) {

    int n = heights.size();

    vector<int> leftIndex = prevLargestElement(heights, n);
    vector<int> rightIndex = nextLargestElement(heights, n);

    int ans = 0;

    for( int i = 0; i < n; i++ ) {
        int lenght = heights[i];

        if( rightIndex[i] == -1 ) {
            rightIndex[i] = n;
        }

        int breath = rightIndex[i] - leftIndex[i] - 1;
        ans = max(ans, lenght * breath);
    }


    return ans;
}

int main() {

    vector<int> heights = { 2,1,5,6,2,3 };

    cout << largestRectangleArea(heights);

    return 0;
}