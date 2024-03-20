#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
vector<pair<int, int>> path(100002, {-1, 0});

void BFS(int x) {
    queue<pair<int, int>> q;
    int dx[] = {-1, 1, 0};
    int currentX, time, count, nx;

    path[x] = {0, 1};
    q.push({x, 0});

    while (!q.empty()) {
        currentX = q.front().first;
        time = q.front().second;
        count = path[currentX].second;
        q.pop();

        for (int i = 0; i < 3; i++) {
            if (i == 2)
                dx[2] = currentX;

            nx = currentX + dx[i];

            if (nx < 0 || nx > 100001)
                continue;

            if (path[nx].first == time + 1)
                path[nx].second += count;

            if (path[nx].first == -1 || path[nx].first > time + 1) {
                path[nx].first = time + 1;
                path[nx].second = count;

                q.push({nx, time + 1});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> k;

    BFS(n);
    cout << path[k].first << '\n' << path[k].second;

    return 0;
}