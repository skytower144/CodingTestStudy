#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int ChangeAlphabet(char target)
{
    int up = target - 'A';
    int down = 'Z' - target + 1;
    return min(up, down);
}

int solution(string name) {
    int answer = INT_MAX;
    int changeSum = 0;
    
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == 'A')
            continue;
        
        changeSum += ChangeAlphabet(name[i]);
        
        int sum = 0;
        int index = i - 1;
        int backForth = name.size() - i;
        
        while (index > 0 && name[index] == 'A')
            index--;

        sum += backForth * 2 + index;
        
        index = i + 1;
        backForth = i;
        
        while (index < name.size() - 1 && name[index] == 'A')
            index++;
        
        int distance = backForth * 2 + name.size() - index;
        sum = min(sum, distance);
        
        if (answer > sum)
            answer = sum;
    }
    
    int index2 = name.size() - 1;
    
    while (index2 > 0 && name[index2] == 'A')
        index2--;
    
    cout << changeSum << endl;
    cout << answer << endl;
    
    answer = min(answer, index2);
    
    if (answer == INT_MAX)
        answer = 0;
    
    answer += changeSum;
    
    return answer;
}