#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> grid;
int ROW, COL;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int Rotate(int y1, int x1, int y2, int x2)
{
    --y1; --x1; --x2; --y2;
    int minVal = grid[y1][x1];
    
    int behind = grid[y1][x1];
    if (y1 != y2)
        behind = grid[y1 + 1][x1];
    
    int front;
    for (int i = x1; i <= x2; i++)
    {
        minVal = min(minVal, behind);
        
        front = grid[y1][i];
        grid[y1][i] = behind;
        behind = front;
    }
    for (int i = y1 + 1; i <= y2; i++)
    {
        minVal = min(minVal, behind);
        
        front = grid[i][x2];
        grid[i][x2] = behind;
        behind = front; 
    }
    for (int i = x2 - 1; i >= x1; i--)
    {
        minVal = min(minVal, behind);
        
        front = grid[y2][i];
        grid[y2][i] = behind;
        behind = front;
    }
    for (int i = y2 - 1; i > y1; i--)
    {
        minVal = min(minVal, behind);
        
        front = grid[i][x1];
        grid[i][x1] = behind;
        behind = front;
    }
    return minVal;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    grid = vector<vector<int>>(rows, vector<int>(columns));
    ROW = rows;
    COL = columns;
    int count = 1;
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            grid[i][j] = count++;
    }
    for (const auto& query : queries)
    {
        answer.push_back(Rotate(query[0], query[1], query[2], query[3]));
    }
    
    return answer;
}