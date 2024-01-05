#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> grid(n);
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    string line;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    for (int i = 0; i < n; i++) {
        cin >> line;
        for (const auto c : line)
            grid[i].push_back(c - '0');
    }
    queue <pair<int, int>> q;
    q.push({0, 0});
    dp[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            bool flag = false;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (grid[ny][nx] == 0 && dp[y][x] + 1 < dp[ny][nx]) {
                    dp[ny][nx] = dp[y][x] + 1;
                    flag = true;
                }
                else if (grid[ny][nx] == 1 && dp[y][x] < dp[ny][nx]) {
                    dp[ny][nx] = dp[y][x];
                    flag = true;
                }
                if (flag)
                    q.push({nx, ny});
            }
        }
    }
    cout << dp[n - 1][n - 1];
    return 0;
}