#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void print(vector<int> ans) {
    for( int i : ans )
        cout << i << "\t";
    cout << endl;
}

// int minimumDeletions(string word, int k) {

//     int n = word.size();

//     vector<int> freq(26, 0);

//     // frequency table is created 
//     for( char ch : word )
//         freq[ch - 'a']++;

//     // create the array of freq;
//     vector<int> freq_list;
//     freq_list.reserve(26);

//     for( int i = 0; i < 26; i++ ) {
//         if( freq[i] != 0 )
//             freq_list.push_back(freq[i]);
//     }

//     print(freq_list);

//     //sort the array
//     sort(freq_list.begin(), freq_list.end());

//     // now get the max count 
//     int mini = freq_list[0];
//     int cnt = 1;
//     int max_cnt = 1;

//     for( int i = 1; i < freq_list.size(); i++ ) {
//         if( freq_list[i] - mini > k ) {
//             mini = freq_list[i];
//             cnt = 0;
//         }
//         cnt++;
//         max_cnt = max(max_cnt, cnt);
//     }

//     return n - max_cnt;
// }

int minimumDeletions(string word, int k) {
    int n = word.size();

    vector<int> freq(26, 0);

    // frequency table is created 
    for( char ch : word )
        freq[ch - 'a']++;

    // create the array of freq;
    vector<int> freq_list;
    freq_list.reserve(26);

    for( int i = 0; i < 26; i++ ) {
        if( freq[i] != 0 )
            freq_list.push_back(freq[i]);
    }

    //sort the array
    sort(freq_list.begin(), freq_list.end());

    print(freq_list);

    int result = INT_MAX;
    int sum = 0;

    for( int i = 0; i < freq_list.size(); i++ ) {
        int cnt = 0;
        for( int j = freq_list.size() - 1; j > i; j-- ) {
            if( (freq_list[i] + k) >= freq_list[j] ) break;

            cnt += freq_list[j] - freq_list[i] - k;
        }
        result = min(cnt + sum, result);
        sum += freq_list[i];
    }

    return result;
}

int main() {

    // cout << minimumDeletions("aabcaba", 0);
    cout << minimumDeletions("aaabaaa", 2);

    return 0;
}