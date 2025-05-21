#include <iostream>
#include<vector>

using namespace std;

void print(vector<vector<int>> mat) {
    for( auto i : mat ) {
        for( int j : i )
            cout << j << "\t";
        cout << endl;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // step 1: check the infected 0 column and 0 row

    // for row 
    bool isRowZero = false;
    for( int i = 0; i < m; i++ )
        if( matrix[0][i] == 0 )
            isRowZero = true;

    // for col 
    bool isColZero = false;
    for( int i = 0; i < n; i++ )
        if( matrix[i][0] == 0 )
            isColZero = true;


    // step 2 use the col 0 and row 0 as a security guard
    for( int i = 1; i < n; i++ ) {
        for( int j = 1; j < m; j++ ) {
            if( matrix[i][j] == 0 ) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    // step 3 convert the infected to zero
    for( int i = 1; i < n; i++ ) {
        for( int j = 1; j < m; j++ ) {
            if( matrix[0][j] == 0 || matrix[i][0] == 0 ) {
                matrix[i][j] = 0;
            }
        }
    }

    // step 4 check the first col and row 
    if( isColZero )
        for( int i = 0; i < n; i++ )
            matrix[i][0] = 0;

    if( isRowZero )
        for( int i = 0; i < n; i++ )
            matrix[0][i] = 0;

}

int main() {

    vector<vector<int>> matrix = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };

    setZeroes(matrix);

    print(matrix);

    return 0;
}