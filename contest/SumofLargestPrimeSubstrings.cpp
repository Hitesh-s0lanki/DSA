#include <iostream>
#include <cmath>
#include <queue>
#include <unordered_map>

using namespace std;

bool isPrime(int n) {

    if( n < 2 ) return false;

    for( int i = 2; i <= sqrt(n); i++ )
        if( n % i == 0 ) return false;

    return true;
}

long long solve(string s, long long num, priority_queue<long long, vector<long long>, greater<long long>>& queue, unordered_map<long long, bool>& visited) {

    if( s.length() == 0 ) return 0;

    long long number = (num * 10) + (s[0] - '0');

    long long include = solve(s.substr(1), number, queue, visited);
    long long exclude = solve(s.substr(1), num, queue, visited);

    if( isPrime(number) && !visited[number] ) {
        visited[number] = true;
        if( queue.size() == 3 ) {
            // remove the element 
            if( queue.top() < number ) {
                queue.pop();
                queue.push(number);
            }
        } else {
            queue.push(number);
        }
        return number + include + exclude;
    }

    return include + exclude;
}

long long sumOfLargestPrimes(string s) {

    priority_queue<long long, vector<long long>, greater<long long>> queue;
    unordered_map<long long, bool> visited;

    solve(s, 0, queue, visited);

    long long ans = 0;

    while( !queue.empty() ) {
        cout << queue.top() << endl;
        ans += queue.top();
        queue.pop();
    }

    return ans;
}

int main() {

    // cout << sumOfLargestPrimes("12234");
    cout << sumOfLargestPrimes("513");

    return 0;
}