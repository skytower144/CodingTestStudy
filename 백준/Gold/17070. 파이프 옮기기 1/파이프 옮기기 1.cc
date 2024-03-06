#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

// DP로 풀어보기
// https://velog.io/@eunseokim/BOJ-17070번-파이프-옮기기-1-dp-풀이-python


int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    int grid[17][17] = {};
    int dp[17][17][3] = {};

    enum Direction {
        RIGHT,
        DOWN,
        DIAGONAL
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    dp[0][1][RIGHT] = 1;

    for (int j = 2; j < n; j++) {
        if (grid[0][j] != 1)
            dp[0][j][RIGHT] = dp[0][j - 1][RIGHT];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] != 1) {
                dp[i][j][RIGHT] = dp[i][j - 1][RIGHT] + dp[i][j - 1][DIAGONAL];
                dp[i][j][DOWN] = dp[i - 1][j][DOWN] + dp[i - 1][j][DIAGONAL];
            }
            if (grid[i][j] != 1 && grid[i - 1][j] != 1 && grid[i][j - 1] != 1)
                dp[i][j][DIAGONAL] = dp[i - 1][j - 1][RIGHT] + dp[i - 1][j - 1][DOWN] + dp[i - 1][j - 1][DIAGONAL];
        }
    }
    cout << dp[n - 1][n - 1][RIGHT] + dp[n - 1][n - 1][DOWN] + dp[n - 1][n - 1][DIAGONAL];
    return 0;
}