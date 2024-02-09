#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            sum += grid[i][j];
            dp[i][j] = sum;
        }
    }
    int k, y1, x1, y2, x2;
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        int answer = 0;
        cin >> y1 >> x1 >> y2 >> x2;

        for (int j = y1; j <= y2; j++)
            answer += dp[j][x2] - dp[j][x1 - 1];
        cout << answer << '\n';
    }
    return 0;
}