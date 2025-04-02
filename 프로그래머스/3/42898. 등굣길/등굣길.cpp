#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int NUMBER = 1000000007;
int N, M;
vector<vector<int>> dp;

int dx[] = {0, 1};
int dy[] = {1, 0};

bool IsPuddle(vector<vector<int>>& puddles, int x, int y)
{
    for (int i = 0; i < puddles.size(); i++)
    {
        if (x == puddles[i][0] - 1 && y == puddles[i][1] - 1)
            return true;
    }
    return false;
}

void GetSolution(vector<vector<int>>& puddles)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    dp[0][0] = 1;
    
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            
            if (IsPuddle(puddles, nx, ny))
                continue;
            
            if (dp[ny][nx] == -1)
            {
                dp[ny][nx] = dp[y][x];
                q.push({nx, ny});
            }
            else
                dp[ny][nx] = (dp[ny][nx] + dp[y][x]) % NUMBER;
        }
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    N = n;
    M = m;
    
    dp = vector<vector<int>>(n, vector<int>(m, -1));
    GetSolution(puddles);

    answer = dp[n - 1][m - 1];
    
    if (answer == -1)
        answer = 0;
    
    return answer;
}