#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int height = land.size();

    vector<vector<int>> dp(height, vector<int>(4, 0));
    dp[0] = land[0];
    
    for (int i = 1; i < height; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (k == j) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + land[i][j]);
            }
        }
    }
    answer = *max_element(dp[height - 1].begin(), dp[height - 1].end());
    return answer;
}