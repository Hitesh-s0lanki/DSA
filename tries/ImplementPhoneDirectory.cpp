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

    void printSuggestion(Node* root, vector<string>& temp, string s) {

        if( root->isTerminal ) {
            temp.push_back(s);
        }

        for( int i = 0; i < 26; i++ ) {
            if( root->children[i] != NULL ) {
                s.push_back('a' + i);
                printSuggestion(root->children[i], temp, s);
                s.pop_back();
            }
        }
    }

    void suggestion(Node* root, string queryStr, vector<string>& temp, string s) {

        if( queryStr.length() == 0 ) {
            printSuggestion(root, temp, s);
            return;
        }

        int index = queryStr[0] - 'a';

        if( root->children[index] == NULL ) {
            return;
        }

        s.push_back(queryStr[0]);

        suggestion(root->children[index], queryStr.substr(1), temp, s);
    }
};

vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {

    Trie* t = new Trie();

    for( int i = 0; i < contactList.size(); i++ ) {
        t->insert(contactList[i]);
    }

    vector<vector<string>> output;

    string s;
    for( int i = 0; i < queryStr.size(); i++ ) {
        s.push_back(queryStr[i]);

        vector<string> temp;
        t->suggestion(t->root, s, temp, "");

        if( temp.size() > 0 )
            output.push_back(temp);
    }

    return output;
}

int main() {

    // vector<string> contactList = { "cod", "coding", "codding", "code", "coly" };
    vector<string> contactList = { "coding", "ninja" };
    string queryStr = "cell";

    vector<vector<string>> ans = phoneDirectory(contactList, queryStr);

    for( auto i : ans ) {
        for( auto j : i ) {
            cout << j << "\t";
        }
        cout << endl;
    }

    return 0;
}