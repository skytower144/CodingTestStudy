#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int minMoves = INT_MAX;

int GetAlphabetAmount(char target)
{
    int moveUp = target - 'A';
    int moveDown = 'Z' - target + 1;
    return min(moveUp, moveDown);
}

void GetTotalMoves(string name, int currentPos, int count, int dir)
{
    int nameSize = name.size();
    int tempCount = 0;

    if (dir < 0)
    {
        for (int i = 0; i < name.size(); i++)
        {
            currentPos = (currentPos + nameSize - 1) % nameSize;
            tempCount++;
            
            if (name[currentPos] != 'A')
            {
                name[currentPos] = 'A';
                count += tempCount;
                GetTotalMoves(name, currentPos, count, 1);
                GetTotalMoves(name, currentPos, count, -1);
            }
        }
    }
    else
    {
        for (int i = 0; i < name.size(); i++)
        {
            currentPos = (currentPos + 1) % nameSize;
            tempCount++;
            
            if (name[currentPos] != 'A')
            {
                name[currentPos] = 'A';
                count += tempCount;
                GetTotalMoves(name, currentPos, count, 1);
                GetTotalMoves(name, currentPos, count, -1);
            }
        }
    }
    minMoves = min(minMoves, count);
}

int solution(string name) {
    int answer = 0, cursor = 0;
    
    if (name[0] != 'A')
    {
        answer += GetAlphabetAmount(name[0]);
        name[0] = 'A';
    }
    GetTotalMoves(name, 0, 0, 1);
    GetTotalMoves(name, 0, 0, -1);
    
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] != 'A')
            answer += GetAlphabetAmount(name[i]);
    }
    answer += minMoves;
    return answer;
}