#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

int answer = INT_MAX;
int maxIndex;

vector<vector<int>> costTable;
vector<int> Picks;
vector<string> Minerals;

unordered_map<string, int> resourceMap = {
    {"diamond", 0},  
    {"iron", 1},  
    {"stone", 2},  
};

void GetSolution(int index, int cost, int pick)
{
    for (int i = index; i < index + 5 && i <= maxIndex; i++)
    {
        int mineral = resourceMap[Minerals[i]];
        cost += costTable[pick][mineral];
    }
    
    if (index + 5 > maxIndex)
    {        
        answer = min(cost, answer);
        return;
    }
    
    bool flag = false;
    
    for (int i = 0; i < 3; i++)
    {
        if (Picks[i] > 0)
        {
            flag = true;
            Picks[i]--;
            GetSolution(index + 5, cost, i);
            Picks[i]++;
        }
    }
    
    if (!flag)
        answer = min(cost, answer);
}

int solution(vector<int> picks, vector<string> minerals) {
    costTable = vector<vector<int>>(3, vector<int>(3, 0));
    maxIndex = minerals.size() - 1;
    
    Picks = picks;
    Minerals = minerals;
    
    costTable[0] = {1, 1, 1};
    costTable[1] = {5, 1, 1};
    costTable[2] = {25, 5, 1};
    
    for (int i = 0; i < 3; i++)
    {
        if (picks[i] > 0)
        {
            Picks[i]--;
            GetSolution(0, 0, i);
            Picks[i]++;
        }
    }
    
    return answer;
}