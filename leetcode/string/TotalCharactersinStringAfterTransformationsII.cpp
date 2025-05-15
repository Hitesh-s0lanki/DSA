#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007
#define SIZE 26

using Matrix = vector<vector<int>>;

// Multiply two 26x26 matrices
Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix C(SIZE, vector<int>(SIZE, 0));

    for( int i = 0; i < SIZE; ++i ) {
        for( int k = 0; k < SIZE; ++k ) {
            if( A[i][k] == 0 ) continue;  // Skip zero rows
            for( int j = 0; j < SIZE; ++j ) {
                C[i][j] = (C[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }

    return C;
}

// Exponentiate transformation matrix
Matrix matrixExpo(Matrix base, int exp) {
    Matrix result(SIZE, vector<int>(SIZE, 0));
    for( int i = 0; i < SIZE; ++i )
        result[i][i] = 1;  // Identity matrix

    while( exp > 0 ) {
        if( exp & 1 )
            result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    vector<int> freq(SIZE, 0);
    for( char c : s ) freq[c - 'a']++;

    // Build optimized transformation matrix
    Matrix T(SIZE, vector<int>(SIZE, 0));
    for( int i = 0; i < SIZE; ++i ) {
        int times = nums[i];
        for( int j = 1; j <= times; ++j ) {
            T[(i + j) % SIZE][i] = (T[(i + j) % SIZE][i] + 1) % MOD;
        }
    }

    // Matrix exponentiation
    Matrix Tt = matrixExpo(T, t);

    // Apply T^t on frequency vector
    vector<int> result(SIZE, 0);
    for( int i = 0; i < SIZE; ++i ) {
        for( int j = 0; j < SIZE; ++j ) {
            result[i] = (result[i] + (1LL * Tt[i][j] * freq[j]) % MOD) % MOD;
        }
    }

    // Compute final sum
    int total = 0;
    for( int x : result )
        total = (total + x) % MOD;

    return total;
}


// ------------------------------------------------------- BRUTE FORCE -------------------------------------------------------------------------- //
// int lengthAfterTransformations(string s, int t, vector<int>& nums) {
//     vector<int> charCount(26, 0);

//     // storing the frequency of the char
//     for( auto i : s )
//         charCount[i - 'a']++;

//     // iterating t time
//     while( t-- ) {
//         vector<int> letters(26, 0);

//         int zIndex = charCount[25];

//         for( int i = 25; i >= 0; i-- ) {
//             if( charCount[i] >= 1 ) {
//                 int size = nums[i];
//                 int index = i + 1;
//                 while( size-- ) {
//                     if( index == 26 ) {
//                         index = 0;
//                     }
//                     letters[index] = (letters[index] + charCount[i]) % MOD;
//                     index++;
//                 }
//             }
//         }

//         // print(letters);
//         // print(charCount);

//         for( int i = 0; i < 26; i++ ) {
//             charCount[i] = letters[i] % MOD;
//         }
//     }

//     // returning the count of the string
//     long long ans = 0;
//     for( auto i : charCount ) {
//         ans = (ans + i) % MOD;
//     }

//     return int(ans);
// }

// ------------------------------------------------------- BRUTE FORCE -------------------------------------------------------------------------- //


int main() {

    // string s = "abcyy";
    // vector<int> nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2 };
    // int t = 2;

    string s = "u";
    vector<int> nums = { 1,1,2,2,3,1,2,2,1,2,3,1,2,2,2,2,3,3,3,2,3,2,3,2,2,3 };
    int t = 5;


    cout << "the length of the resulting string after exactly t transformations : " << lengthAfterTransformations(s, t, nums);

    return 0;
}