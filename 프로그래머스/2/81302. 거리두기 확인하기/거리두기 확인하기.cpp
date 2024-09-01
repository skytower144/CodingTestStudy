#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx1[] = {2, -2, 0, 0};
int dy1[] = {0, 0, 2, -2};

int dx2[] = {1, 1, -1, -1};
int dy2[] = {1, -1, 1, -1};

int Distance(int x1, int y1, int x2, int y2)
{
    return (abs(x1 - x2) + abs(y1 - y2));
}

bool IsValidSeat(int x, int y)
{
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}

bool CheckSeat(vector<string>& place, int x, int y)
{
    int nx, ny;
    int sx, sy;
    
    for (int i = 0; i < 4; i++)
    {
        nx = x + (dx1[i] / 2);
        ny = y + (dy1[i] / 2);
        
        if (!IsValidSeat(nx, ny))
            continue;
        
        if (place[ny][nx] == 'P')
            return false;
    }
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx1[i];
        ny = y + dy1[i];
        
        sx = x + (dx1[i] / 2);
        sy = y + (dy1[i] / 2);
        
        if (!IsValidSeat(nx, ny))
            continue;
        
        if (place[ny][nx] == 'P' && place[sy][sx] != 'X')
            return false;
    }
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx2[i];
        ny = y + dy2[i];
        
        if (!IsValidSeat(nx, ny))
            continue;
        
        if (place[ny][nx] == 'P' && ((place[y][nx] != 'X') || (place[ny][x] != 'X')))
            return false;
    }
    return true;
}

bool CheckPlace(vector<string>& place)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (place[i][j] == 'P' && !CheckSeat(place, j, i))
                return false;
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (auto& place : places)
        answer.push_back(CheckPlace(place));
    
    return answer;
}