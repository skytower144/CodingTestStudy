#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

vector<int> pathDistance;

void FindPath(unordered_map<int, vector<int>>& nodeMap, vector<bool>& visited)
{
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    
    while (!q.empty())
    {
        int current = q.front().first;
        int length = q.front().second;
        q.pop();

        if (pathDistance[current] != -1)
            continue;
        
        pathDistance[current] = length + 1;
        visited[current] = true;
        
        for (auto next : nodeMap[current])
        {
            if (visited[next])
                continue;
            
            q.push({next, length + 1});
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 1;
    
    unordered_map<int, vector<int>> nodeMap;
    vector<bool> visited(n + 1, false);
    pathDistance = vector<int>(n + 1, -1);
    
    for (auto e : edge)
    {
        nodeMap[e[0]].push_back(e[1]);
        nodeMap[e[1]].push_back(e[0]);
    }
    
    FindPath(nodeMap, visited);
    sort(pathDistance.begin() + 1, pathDistance.end());

    int longest = pathDistance.back();

    for (int i = pathDistance.size() - 2; i > 0; i--)
    {
        if (pathDistance[i] != longest)
            break;
        
        answer++;
    }
    
    return answer;
}