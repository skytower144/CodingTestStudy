#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int N;
vector<int> parents;

void GetSolution(int num, vector<vector<int>>& computers)
{
    for (int i = 0; i < N; i++)
    {
        if (i == num)
            continue;
        
        if (parents[i] == parents[num])
            continue;
        
        if (computers[num][i] == 0)
            continue;
        
        parents[i] = parents[num];
        GetSolution(i, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    N = n;
    parents = vector<int>(computers.size());
    int answer = 0;

    for (int i = 0; i < computers.size(); i++)
        parents[i] = i;
    
    for (int i = 0; i < computers.size(); i++)
        GetSolution(i, computers);
    
    unordered_set<int> numSet;
    
    for (auto p : parents)
        numSet.insert(p);
    
    answer += numSet.size();
    return answer;
}