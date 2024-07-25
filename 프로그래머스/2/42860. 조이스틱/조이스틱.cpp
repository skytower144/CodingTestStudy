#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int GetAlphabetAmount(char target)
{
    int moveUp = target - 'A';
    int moveDown = 'Z' - target + 1;
    return min(moveUp, moveDown);
}

int solution(string name) {
    int answer = 0;
    int nameSize = name.size();
    int minMoveX = nameSize - 1;
    
    for (int i = 0; i < nameSize; i++)
    {
        if (name[i] != 'A')
            answer += GetAlphabetAmount(name[i]);
    }
    for (int i = 0; i < nameSize; i++)
    {
        int checkEndPos = i + 1;
        while (checkEndPos < nameSize && name[checkEndPos] == 'A')
            checkEndPos++;
        
        minMoveX = min(minMoveX, (i * 2) + (1) + (nameSize - 1 - checkEndPos));
        minMoveX = min(minMoveX, (nameSize - 1 - checkEndPos) * 2 + (2) + (i));
    }
    answer += minMoveX;
    return answer;
}