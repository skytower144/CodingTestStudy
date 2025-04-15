#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 회전: (x, y) -> (y, -x)

int N, M;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct Shape
{
    vector<pair<int, int>> coords;
};

void Normalize(Shape& s)
{
    int moveX = -s.coords[0].first;
    int moveY = -s.coords[0].second;
    
    for (int i = 0; i < s.coords.size(); i++)
    {
        int x = s.coords[i].first;
        int y = s.coords[i].second;

        moveX = max(moveX, -x);
        moveY = max(moveY, -y);
    }
    
    for (int i = 0; i < s.coords.size(); i++)
    {
        int x = s.coords[i].first;
        int y = s.coords[i].second;

        s.coords[i] = { x + moveX, y + moveY };
    }
    
    sort(s.coords.begin(), s.coords.end());
}

void Rotate(Shape& s)
{
    for (int i = 0; i < s.coords.size(); i++)
    {
        int temp = -s.coords[i].first;
        s.coords[i].first = s.coords[i].second;
        s.coords[i].second = temp;
    }
    
    Normalize(s);
}

bool CompareShapes(Shape& a, Shape& b)
{
    for (int i = 0; i < a.coords.size(); i++)
    {
        if (a.coords[i] != b.coords[i])
            return false;
    }
    
    return true;
}

bool FitShapes(Shape& b, Shape& p)
{    
    if (b.coords.size() != p.coords.size())
        return false;
 
    Normalize(b);
    Normalize(p);
    
    if (CompareShapes(b, p))
        return true;
    
    for (int i = 0; i < 3; i++)
    {
        Rotate(p);
        if (CompareShapes(b, p))
            return true;
    }
    
    return false;
}

void CollectShapes(vector<Shape>& shapes, vector<vector<int>>& board, vector<vector<bool>>& visited, int type, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;
    
    Shape shape;
    shape.coords.push_back({x, y});
    
    while (!q.empty())
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            
            if (visited[ny][nx])
                continue;
            
            if (board[ny][nx] != type)
                continue;
            
            q.push({nx, ny});
            visited[ny][nx] = true;
            shape.coords.push_back({nx, ny});
        }
    }
    
    shapes.push_back(shape);
}

void FindShapes(vector<Shape>& shapes, vector<vector<int>>& board, int type)
{    
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] != type)
                continue;
            
            if (visited[i][j])
                continue;
            
            CollectShapes(shapes, board, visited, type, j, i);
        }
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    N = table.size();
    M = table[0].size();
    
    vector<Shape> blanks, pieces;
    
    FindShapes(blanks, game_board, 0);
    FindShapes(pieces, table, 1);
    
    vector<bool> taken(blanks.size(), false);

    for (int i = 0; i < pieces.size(); i++)
    {
        for (int j = 0; j < blanks.size(); j++)
        {
            if (taken[j])
                continue;
            
            Shape p = pieces[i];
            Shape b = blanks[j];
            
            if (FitShapes(b, p))
            {
                answer += p.coords.size();
                taken[j] = true;
                break;
            }
        }
    }
    
    return answer;
}