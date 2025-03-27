#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int oCount = 0;
int xCount = 0;

bool ValidCount(vector<string>& board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'O')
                oCount++;
            
            else if (board[i][j] == 'X')
                xCount++;
        }
    }

    int diff = abs(oCount - xCount);

    if (oCount < xCount)
        return false;

    return diff <= 1;
}

bool ValidGame(vector<string>& board)
{
    int wins = 0;
    
    bool xWin = false;
    bool oWin = false;
    bool flag = true;
    
    // 아래 대각선    
    for (int i = 1; i < 3; i++)
    {
        if (board[i - 1][i - 1] != board[i][i])
        {
            flag = false;
            break;
        }
    }
    
    if (flag)
    {
        wins++;
        if (board[0][0] == 'O')
            oWin = true;
    
        else if (board[0][0] == 'X')
            xWin = true;
    }
    
    flag = true;
    
    // 위 대각선
    for (int i = 1; i >= 0; i--)
    {
        if (board[2 - i - 1][i + 1] != board[2 - i][i])
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        wins++;
        if (board[2][0] == 'O')
            oWin = true;
        
        else if (board[2][0] == 'X')
            xWin = true;
    }
    
    for (int i = 0; i < 3; i++)
    {
        flag = true;
        
        for (int j = 1; j < 3; j++)
        {
            if (board[i][j] != board[i][j - 1])
            {
                flag = false;
                break;
            }
        }
        
        if (flag)
        {
            wins++;
            if (board[i][0] == 'O')
                oWin = true;
            
            else if (board[i][0] == 'X')
                xWin = true;
        }
    }
    
    for (int j = 0; j < 3; j++)
    {
        flag = true;
        
        for (int i = 1; i < 3; i++)
        {
            if (board[i][j] != board[i - 1][j])
            {
                flag = false;
                break;
            }
        }
        
        if (flag)
        {
            wins++;
            if (board[0][j] == 'O')
                oWin = true;
            
            else if (board[0][j] == 'X')
                xWin = true;
        }
    }
    
    if (wins == 8 && board[0][0] == '.')
        return true;
    
    if (xWin && oWin)
        return false;
    
    if (xWin && xCount != oCount)
        return false;
    
    if (oWin && oCount <= xCount)
        return false;
    
    return true;
}

int solution(vector<string> board) {
    int answer = 0;
    
    if (!ValidCount(board))
        return 0;
    
    return ValidGame(board);
}