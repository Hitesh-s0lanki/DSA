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


class Trie {
public:
    Node* root;
    Trie() {
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

    void insert(string word) {
        insertUtils(root, word);
    }

    string longestCommonPrefix(Node* root, string s) {

        char ch = '\0';
        Node* child;

        for( int i = 0; i < 26; i++ ) {
            if( root->children[i] != NULL ) {
                if( ch != '\0' ) return s;
                child = root->children[i];
                ch = 'a' + i;
            }
        }

        if( ch == '\0' ) return s;

        s.push_back(ch);

        return longestCommonPrefix(child, s);
    }
};

string longestCommonPrefix(vector<string>& strs) {
    Trie* t = new Trie();
    for( string i : strs ) {
        t->insert(i);
    }

    return t->longestCommonPrefix(t->root, "");
}

int main() {
    return 0;
}