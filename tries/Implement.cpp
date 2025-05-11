#include <iostream>

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
    Node* root;

public:
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

    bool searchUtils(Node* root, string word) {
        if( word.length() == 0 ) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';

        // word is present
        if( root->children[index] == NULL ) return false;

        return searchUtils(root->children[index], word.substr(1));
    }

    bool search(string word) {
        return searchUtils(root, word);
    }

    bool startsWithUtils(Node* root, string word) {
        if( word.length() == 0 ) {
            return true;
        }

        int index = word[0] - 'a';

        // word is present
        if( root->children[index] == NULL ) return false;

        return startsWithUtils(root->children[index], word.substr(1));
    }

    bool startsWith(string prefix) {
        return startsWithUtils(root, prefix);
    }
};

int main() {

    Trie* t = new Trie();

    t->insert("hitesh");
    t->insert("kapil");
    t->insert("hit");


    cout << "Found the word or not : " << t->search("hite") << endl;
    cout << "Word Start with or not : " << t->startsWith("hi") << endl;

    return 0;
}