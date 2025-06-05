#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

//     int n = status.size();

//     vector<bool> visited(n, false);
//     vector<bool> present(n, false);

//     // put all initialBoxes in queue
//     queue<int> q;
//     for( int i : initialBoxes ) {
//         q.push(i);
//         present[i] = true;
//     }

//     int ans = 0;

//     while( !q.empty() ) {
//         // check if the box is open or not
//         int front = q.front();
//         q.pop();

//         if( status[front] == 1 && !visited[front] ) {
//             // count the candy
//             ans += candies[front];

//             // mark the node visited
//             visited[front] = true;

//             // checks the keys in containers
//             for( int key : keys[front] )
//                 status[key] = 1;

//             // put the found box inside queue
//             for( int box : containedBoxes[front] ) {
//                 if( status[box] == 1 ) {
//                     q.push(box);
//                 }
//                 present[box] = true;
//             }
//         }

//         // check if any box is present/open and not visited
//         for( int i = 0; i < n; i++ ) {
//             if( present[i] && !visited[i] && status[i] == 1 )
//                 q.push(i);
//         }
//     }

//     return ans;
// }

int maxCandies(vector<int>& status,
    vector<int>& candies,
    vector<vector<int>>& keys,
    vector<vector<int>>& containedBoxes,
    vector<int>& initialBoxes)
{
    int n = status.size();

    // visited[i] = have we already opened box i?
    vector<bool> visited(n, false);

    // haveBox[i] = do we currently "have" box i in hand (whether locked or unlocked)?
    vector<bool> haveBox(n, false);

    // q will hold all boxes that are currently in hand AND unlocked AND not yet visited.
    queue<int> q;

    // 1) Mark all initialBoxes as "in hand." If they're also open, push them to q immediately.
    for( int b : initialBoxes ) {
        if( !haveBox[b] ) {
            haveBox[b] = true;
            if( status[b] == 1 ) {
                q.push(b);
            }
        }
    }

    int totalCandies = 0;

    // Process queue until no more open boxes are reachable
    while( !q.empty() ) {
        int box = q.front();
        q.pop();

        if( visited[box] ) continue;      // (safety) skip if already opened
        if( status[box] == 0 ) continue;  // should not happen, but just in case

        // 2) Open box, collect candies:
        visited[box] = true;
        totalCandies += candies[box];

        // 3) For each key inside this box:
        //    - Unlock that box (status[keyBox] = 1).
        //    - If we already have that box in hand AND haven't opened it yet, push it.
        for( int keyBox : keys[box] ) {
            if( status[keyBox] == 0 ) {
                status[keyBox] = 1;         // unlock it
                if( haveBox[keyBox] && !visited[keyBox] ) {
                    q.push(keyBox);
                }
            }
        }

        // 4) For each contained box inside this box:
        //    - Mark it "in hand."
        //    - If it is already unlocked (status[...] == 1) and not yet visited, enqueue it.
        for( int newBox : containedBoxes[box] ) {
            if( !haveBox[newBox] ) {
                haveBox[newBox] = true;
                if( status[newBox] == 1 && !visited[newBox] ) {
                    q.push(newBox);
                }
            }
        }
    }

    return totalCandies;
}

int main() {

    vector<int> status = { 1,0,1,0 }, candies = { 7,5,4,100 }, initialBoxes = { 0 };
    vector<vector<int>> keys = { {},{},{1},{} }, containedBoxes = { {1,2},{3},{},{} };

    cout << maxCandies(status, candies, keys, containedBoxes, initialBoxes);

    return 0;
}