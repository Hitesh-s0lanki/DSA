#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// space -> O(1)
// time -> O(N)
// vector<pair<char, int>> duplicate_char(string s, int n) {
//     vector<int> letter(26 * 2, 0);

//     for( char ch : s )
//         letter[ch - 'A']++;

//     vector<pair<char, int>> ans;

//     for( int i = 0; i < 26; i++ ) {
//         if( letter[i] >= n )
//             ans.push_back({ 'A' + i, letter[i] });

//     }

//     return ans;
// }

// vector<pair<char, int>> duplicate_char(string s, int n) {
//     unordered_map<char, int> letter(26 * 2, 0);

//     for( char ch : s )
//         letter[ch]++;

//     vector<pair<char, int>> ans;

//     for( auto i : letter ) {
//         if( i.second >= 2 )
//             ans.push_back({ i.first , i.second });

//     }

//     return ans;
// }


vector<pair<char, int>> duplicate_char(string s, int n) {

    vector<int> letter(256, 0);
    for( char ch : s )
        letter[ch]++;

    vector<pair<char, int>> ans;
    ans.reserve(256);

    for( int i = 0; i < 256; i++ ) {
        if( letter[i] >= 2 ) {
            ans.emplace_back(static_cast< char >(i), letter[i]);
        }
    }

    return ans;
}

int main() {

    vector<pair<char, int>> ans = duplicate_char("GEEK", 2);

    for( auto i : ans ) {
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}