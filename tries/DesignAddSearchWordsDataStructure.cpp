#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    char data;
    Node* children[26];
    bool isTerminal;

    Node(char data) {
        this->data = data;

        for( int i = 0;i < 26; i++ )
            this->children[i] = NULL;

        this->isTerminal = false;
    }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        this->root = new Node('\0');
    }

    void insertUtils(Node* root, string word) {

        if( word.length() == 0 ) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        Node* child;

        if( root->children[index] != NULL ) {
            // data present 
            child = root->children[index];
        } else {
            // data is absent 
            child = new Node(word[0]);
            root->children[index] = child;
        }

        insertUtils(child, word.substr(1));
    }

    void addWord(string word) {
        insertUtils(root, word);
    }

    bool searchUtils(Node* root, string word) {
        if( word.length() == 0 ) {
            return root->isTerminal;
        }

        if( word[0] == '.' ) {
            for( int i = 0; i < 26; i++ ) {
                if( root->children[i] != NULL ) {
                    bool ans = searchUtils(root->children[i], word.substr(1));
                    if( ans ) return true;
                }
            }
            return false;
        } else {
            int index = word[0] - 'a';

            // word is present
            if( root->children[index] == NULL ) return false;

            return searchUtils(root->children[index], word.substr(1));
        }

    }

    bool search(string word) {
        return searchUtils(root, word);
    }
};

int main() {

    WordDictionary* w = new WordDictionary();

    vector<string> words = {
        "bad",
        "dad",
        "mad",
        "pad",
    };

    for( auto i : words )
        w->addWord(i);

    cout << w->search(".ad");

    return 0;
}