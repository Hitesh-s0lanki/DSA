#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Job {
public:
    int deadline;
    int profit;

    Job(int deadline, int profit) {
        this->deadline = deadline;
        this->profit = profit;
    }
};

class Compare {
public:
    bool operator()(Job* a, Job* b) {
        return a->profit < b->profit;
    }
};

vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {

    int n = deadline.size();

    priority_queue<Job*, vector<Job*>, Compare> pq;

    int maxTime = 0;
    for( int i = 0; i < n; i++ ) {
        pq.push(new Job(deadline[i], profit[i]));
        maxTime = max(maxTime, deadline[i]);
    }

    // schedular 
    vector<int> schedular(maxTime + 1, -1);

    int cnt = 0;
    int maxProfit = 0;

    while( !pq.empty() ) {
        Job* top = pq.top();
        pq.pop();

        for( int i = top->deadline; i > 0; i-- ) {
            if( schedular[i] == -1 ) {
                maxProfit += top->profit;
                cnt++;
                schedular[i] = 0;
                break;
            }
        }
    }

    vector<int> ans;
    ans.push_back(cnt);
    ans.push_back(maxProfit);

    return ans;
}

void print(vector<int> ans) {
    for( auto i : ans )
        cout << i << "\t";
    cout << endl;
}

int main() {

    vector<int> deadline = { 4, 1, 1, 1 };
    vector<int> profit = { 20, 10, 40, 30 };

    print(jobSequencing(deadline, profit));

    return 0;
}