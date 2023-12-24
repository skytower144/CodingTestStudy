#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int dx[] = {0, -1, -1};
    int dy[] = {-1, 0, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    dp[0][0] = grid[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 3; d++) {
                int nx = j + dx[d];
                int ny = i + dy[d];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                    dp[i][j] = max(dp[i][j], grid[i][j] + dp[ny][nx]);
            }
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}