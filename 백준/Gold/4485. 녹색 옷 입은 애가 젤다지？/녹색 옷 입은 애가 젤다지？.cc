#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int i = 0;
    while (++i) {
        int n;
        cin >> n;

        if (n == 0) break;

        vector<vector<int>> cave(n, vector<int>(n, 0));
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> cave[i][j];
        }
        dp[0][0] = cave[0][0];
        q.push({0, 0});

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (dp[y][x] + cave[ny][nx] < dp[ny][nx]) {
                        dp[ny][nx] = dp[y][x] + cave[ny][nx];
                        q.push({nx, ny});
                    }
                }
            }
        }
        cout << "Problem " << i << ": " << dp[n - 1][n - 1] << '\n';
    }
    return 0;
}