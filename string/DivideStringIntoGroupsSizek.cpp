#include <iostream>
#include <vector>

using namespace std;

void print(vector<string> ans) {
    for( string s : ans )
        cout << s << "\t";
}

vector<string> divideString(string s, int k, char fill) {

    int n = s.length();

    // storing the answer
    vector<string> result;

    // find the remaing char after operation
    int rem = n % k;

    string temp = "";

    for( int i = 0; i < n; ) {
        // run the inner loop by k time
        int k_inc = k;
        while( k_inc ) {
            if( i < n )
                temp.push_back(s[i]);
            else
                temp.push_back(fill);

            i++;
            k_inc--;
        }
        result.push_back(temp);
        temp.clear();
    }

    return result;
}

int main() {

    print(divideString("abcdefghij", 3, 'x'));

    return 0;
}