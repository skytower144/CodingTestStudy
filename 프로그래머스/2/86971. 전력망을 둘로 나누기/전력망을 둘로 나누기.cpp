#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int ct = 0;

void DFS(int start, vector<vector<int>>& graph, vector<int>& visited) {
    visited[start] = 1;
    ct++;
    
    for (const auto& next : graph[start]) {
        if (visited[next])
            continue;
        
        DFS(next, graph, visited);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    int from, to;
    
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < wires.size(); i++) {
        from = wires[i][0];
        to = wires[i][1];
        
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for (int i = 0; i < wires.size(); i++) {        
        from = wires[i][0];
        to = wires[i][1];
        
        auto it = remove(graph[from].begin(), graph[from].end(), to);
        graph[from].resize(it - graph[from].begin());
        
        it = remove(graph[to].begin(), graph[to].end(), from);
        graph[to].resize(it - graph[to].begin());
        
        ct = 0;
        vector<int> visited(n + 1, 0);
        DFS(1, graph, visited);
        
        answer = min(answer, abs(ct - n + ct));
        
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    return answer;
}