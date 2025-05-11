#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> prevLargestElement(vector<int> heights, int n) {
    stack<int> stack;
    stack.push(-1);

    vector<int> ans(n);

    for( int i = 0; i < n; i++ ) {
        while( !stack.empty() && stack.top() != -1 && heights[stack.top()] >= heights[i] ) {
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
        while( !stack.empty() && stack.top() != -1 && heights[stack.top()] >= heights[i] ) {
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

int maxArea(vector<vector<int>>& mat) {
    int row = mat.size();
    int col = mat[0].size();

    for( int i = 1; i < row; i++ ) {
        for( int j = 0; j < col; j++ ) {
            if( mat[i][j] != 0 ) {
                mat[i][j] += mat[i - 1][j];
            }
        }
    }

    int ans = 0;

    for( int i = 0; i < row; i++ ) {
        ans = max(ans, largestRectangleArea(mat[i]));
    }

    return ans;
}

int main() {

    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    cout << maxArea(mat);

    return 0;
}