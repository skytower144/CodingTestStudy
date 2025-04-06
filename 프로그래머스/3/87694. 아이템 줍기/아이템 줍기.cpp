#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

int answer = INT_MAX;
int ItemX, ItemY;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vector<vector<int>> Rect;

bool CanGo(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited)
{
    if (x < 0 || y < 0 || x > 100 || y > 100)
        return false;
    
    if (visited[y][x])
        return false;
    
    if (grid[y][x] == 0)
        return false;
    
    for (auto rect : Rect)
    {
        int startX = rect[0] * 2;
        int endX = rect[2] * 2;
        int startY = rect[1] * 2;
        int endY = rect[3] * 2;
        
        if (x > startX && x < endX && y > startY && y < endY)
            return false;
    }
    
    return true;
}

void FindPath(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int cost)
{
    if (x == ItemX && y == ItemY)
    {
        answer = min(answer, cost / 2);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (!CanGo(nx, ny, grid, visited))
            continue;
        
        visited[ny][nx] = true;
        FindPath(grid, visited, nx, ny, cost + 1);
        visited[ny][nx] = false;
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<int>> grid(101, vector<int>(101, 0));
    vector<vector<bool>> visited(101, vector<bool>(101, false));
    
    ItemX = itemX * 2;
    ItemY = itemY * 2;
    Rect = rectangle;
    
    for (auto rect : rectangle)
    {
        int startX = rect[0] * 2;
        int endX = rect[2] * 2;
        int startY = rect[1] * 2;
        int endY = rect[3] * 2;
        
        for (int i = startY; i <= endY; i++)
        {
            for (int j = startX; j <= endX; j++)
            {
                if (i == startY || i == endY || j == startX || j == endX)
                    grid[i][j] = 1;
                else
                    grid[i][j] = 0;
            }
        }
    }
    
    characterX *= 2;
    characterY *= 2;
    
    visited[characterY][characterX] = true;
    FindPath(grid, visited, characterX, characterY, 0);
    return answer;
}