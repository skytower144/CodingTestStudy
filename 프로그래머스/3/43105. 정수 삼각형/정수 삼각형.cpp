#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = -1;
    
    vector<vector<int>> dp(triangle.size());
    
    dp[0].push_back(triangle[0][0]);
    
    for (int i = 1; i < triangle.size(); i++)
    {
        dp[i] = vector<int>(triangle[i].size(), 0);
        
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
                dp[i][j] = triangle[i][j] + dp[i - 1][0];

            else if (j == triangle[i].size() - 1)
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            
            else
                dp[i][j] = max(triangle[i][j] + dp[i - 1][j - 1], triangle[i][j] + dp[i - 1][j]);
            
            answer = max(answer, dp[i][j]);
        }
    }
    
    return answer;
}