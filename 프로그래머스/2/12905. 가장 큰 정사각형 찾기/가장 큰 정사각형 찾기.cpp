#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board)
{
    int height = board.size();
    int width = board[0].size();
    int dp[1001][1001] = {0, };
    int longest = 0;
    
    for (int i = 0; i < width; i++) {
        dp[0][i] = board[0][i];
        longest = max(longest, dp[0][i]);
    }
    for (int i = 1; i < height; i++) {
        dp[i][0] = board[i][0];
        longest = max(longest, dp[i][0]);
    }
    for (int i = 1; i < height; i++) {
        for (int j = 1; j < width; j++) {
            if (board[i][j]) {
                dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
                longest = max(longest, dp[i][j]);
            }
        }
    }
    return longest * longest;
}