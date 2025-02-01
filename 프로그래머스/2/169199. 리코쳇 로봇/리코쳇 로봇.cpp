#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

vector<vector<int>> visited;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int width, height;
int answer = INT_MAX;

struct PathInfo
{
    int x;
    int y;
    int cost;
};

bool CanGo(vector<string>& board, int x, int y)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
        return false;
    
    if (board[y][x] == 'D')
        return false;
    
    return true;
}

void FindPath(vector<string>& board, int startX, int startY)
{
    queue<PathInfo> q;
    q.push({startX, startY, 0});
    
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        q.pop();
        
        if (board[y][x] == 'G')
        {
            answer = min(answer, visited[y][x]);
            continue;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x;
            int ny = y;
            
            while (CanGo(board, nx + dx[i], ny + dy[i]))
            {
                nx += dx[i];
                ny += dy[i];
            }
            
            if (nx == x && ny == y)
                continue;
            
            if (visited[ny][nx] > 0 && (visited[ny][nx] <= cost + 1))
                continue;
            
            visited[ny][nx] = cost + 1;
            q.push({nx, ny, cost + 1});
        }
    }
}

int solution(vector<string> board) {
    width = board[0].size();
    height = board.size();
    
    visited = vector<vector<int>>(height, vector<int>(width, 0));
    int startX, startY;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j] == 'R')
            {
                startX = j, startY = i;
                break;
            }
        }
    }
    
    FindPath(board, startX, startY);
    
    if (answer == INT_MAX)
        answer = -1;
    
    return answer;
}