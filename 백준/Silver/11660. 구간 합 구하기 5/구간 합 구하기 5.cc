#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    for (int i = 0; i < n * n; i++) {
        dp[i / n][i % n] = dp[max(0, i - 1) / n][max(0, i - 1) % n] + grid[i / n][i % n];
    }
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;

        int answer = 0;
        for (int x = x1; x <= x2; x++) {
            int before = dp[x][(y1 + n - 1) % n];
            if (y1 == 0) {
                if (x == 0)
                    before = 0;
                else
                    before = dp[x - 1][(y1 + n - 1) % n];
            }
            answer += dp[x][y2] - before;
        }
        cout << answer << '\n';
    }

    return 0;
}