// Time Complexity: O(N * L)
// Space Complexity: O(N)

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    int n = wordList.size();

    // mapping the visited node
    unordered_set<string> set(wordList.begin(), wordList.end());

    // bfs travesal
    queue<pair<string, int>> queue;
    queue.push(make_pair(beginWord, 1));
    set.erase(beginWord);

    while( !queue.empty() ) {
        pair<string, int> front = queue.front();
        queue.pop();

        string word = front.first;

        if( word == endWord ) return front.second;

        for( int i = 0; i < word.length(); i++ ) {
            char original = word[i];
            for( char ch = 'a'; ch <= 'z'; ch++ ) {
                word[i] = ch;
                if( set.find(word) != set.end() ) {
                    set.erase(word);
                    queue.push(make_pair(word, front.second + 1));
                }
            }
            word[i] = original;
        }
    }

    return 0;
}

int main() {

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = { "hot","dot","dog","lot","log","cog" };

    cout << ladderLength(beginWord, endWord, wordList);

    return 0;
}