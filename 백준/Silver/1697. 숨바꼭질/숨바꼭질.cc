#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int start, target;
vector<int> visited(100001, 0);
queue<pair<int, int>> q;

int FindTarget() {
    int position, passedTime, nx;

    while (!q.empty()) {
        position = q.front().first;
        passedTime = q.front().second + 1;

        int dx[] = {-1, 1, position};
        q.pop();

        for (int i = 0; i < 3; i++) {
            nx = position + dx[i];

            if (nx >= 0 && nx <= 100000 && !visited[nx]) {
                visited[nx] = passedTime;
                q.push(pair<int, int>(nx, passedTime));
                // cout << "visited : " << nx << " at time : " << passedTime << endl;

                if (nx == target)
                    return visited[nx];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    long long answer;
    cin >> start >> target;
    
    visited[start] = 0;
    q.push(pair<int, int>(start, 0));

    if (start == target) answer = 0;
    else answer = FindTarget();
    cout << answer;

    return 0;
}