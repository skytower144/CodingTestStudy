#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void Dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& duration) {
    priority_queue<pair<int, int>> pq;
    duration[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int elapsedTime = -pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        
        if (elapsedTime > duration[currentNode])
            continue;
        
        for (const auto& [nextNode, t] : graph[currentNode]) {
            if (duration[nextNode] > elapsedTime + t) {
                duration[nextNode] = elapsedTime + t;
                pq.push({-duration[nextNode], nextNode});
            }
        }
    }
}
int solution(int N, vector<vector<int>> road, int K) {
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> duration(N + 1, INT_MAX);
    int answer = 0;
    
    for (int i = 0; i < road.size(); i++) {
        int from = road[i][0];
        int to = road[i][1];
        int time = road[i][2];
        
        graph[from].push_back({to, time});
        graph[to].push_back({from, time});
    }
    Dijkstra(graph, duration);
    
    for (int i = 1; i <= N; i++)
        if (duration[i] <= K) answer++;

    return answer;
}