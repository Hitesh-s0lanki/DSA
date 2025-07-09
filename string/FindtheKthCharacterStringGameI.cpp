#include <iostream>
#include <vector>

using namespace std;

char kthCharacter(int k) {
    return 'a' + __builtin_popcount(k - 1);
}

int main() {

    cout << kthCharacter(16);

    return 0;
}