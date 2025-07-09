#include <iostream>

using namespace std;

int possibleStringCount(string word) {

    int n = word.length();

    int result = 1;

    int i = 0;
    while( i < n ) {

        char ch = word[i];
        int cnt = 0;

        while( i < n && word[i] == ch ) {
            cnt++;
            i++;
        }

        result += (cnt - 1);
    }

    return result;
}

int main() {

    cout << possibleStringCount("aaa");

    return 0;
}