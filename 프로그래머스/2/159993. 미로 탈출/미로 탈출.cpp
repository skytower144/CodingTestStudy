#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N, M;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int FindPath(int beginX, int beginY, int goalX, int goalY, vector<string>& maps, vector<vector<int>>& grid)
{
    queue<pair<int, int>> q;
    q.push({beginX, beginY});
    grid[beginY][beginX] = 1;
    
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            
            if (grid[ny][nx] > 0)
                continue;
            
            if (maps[ny][nx] == 'X')
                continue;
            
            grid[ny][nx] = grid[y][x] + 1;
            
            if (nx == goalX && ny == goalY)
                break;
            
            q.push({nx, ny});
        }
    }
    
    return grid[goalY][goalX] - 1;
}

int solution(vector<string> maps) {
    int answer = 0;
    N = maps.size();
    M = maps[0].size();
    
    vector<vector<int>> grid1(N, vector<int>(M, 0));
    vector<vector<int>> grid2 = grid1;
    
    int startX, startY;
    int leverX, leverY;
    int exitX, exitY;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (maps[i][j] == 'S')
                startX = j, startY = i;
            
            else if (maps[i][j] == 'L')
                leverX = j, leverY = i;
            
            else if (maps[i][j] == 'E')
                exitX = j, exitY = i;
        }
    }
    
    int leverTime = FindPath(startX, startY, leverX, leverY, maps, grid1);
    int exitTime = FindPath(leverX, leverY, exitX, exitY, maps, grid2);

    if (leverTime < 0 || exitTime < 0)
        return -1;
    
    answer = leverTime + exitTime;
    return answer;
}