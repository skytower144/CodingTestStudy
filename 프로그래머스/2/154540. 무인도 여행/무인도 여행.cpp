#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int N, M;

int GetSum(vector<string>& maps, vector<vector<bool>>& visited, int j, int i)
{
    int totalSum = maps[i][j] - '0';
    
    queue<pair<int, int>> q;
    q.push({j, i});
    visited[i][j] = true;
    
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;

            if (maps[ny][nx] == 'X')
                continue;
            
            if (visited[ny][nx])
                continue;
            
            visited[ny][nx] = true;
            totalSum += maps[ny][nx] - '0';
            q.push({nx, ny});
        }
    }
    
    return totalSum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    N = maps.size();
    M = maps[0].size();
    
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j])            
                continue;
            
            if (maps[i][j] == 'X')
                continue;
            
            answer.push_back(GetSum(maps, visited, j, i));
        }
    }
    
    if (answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    
    return answer;
}