#include <string>
#include <vector>

using namespace std;

int answer = -1;

void GetSolution(int count, int current, vector<vector<int>>& dungeons, vector<bool>& visited)
{
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (visited[i])
            continue;
        
        int needed = dungeons[i][0];
        int cost = dungeons[i][1];
        
        if (current < needed)
            continue;
        
        visited[i] = true;
        GetSolution(count + 1, current - cost, dungeons, visited);
        visited[i] = false;
    }
    if (answer < count)
        answer = count;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size());
    GetSolution(0, k, dungeons, visited);
    return answer;
}