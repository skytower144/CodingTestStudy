#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m, r;

int Dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& items) {
    priority_queue<pair<int, int>> pq;
    vector<int> distance(n + 1, INT_MAX);
    int totalItems = 0;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int distanceSum = -pq.top().first;
        int currentPos = pq.top().second;
        pq.pop();

        if (distanceSum > distance[currentPos])
            continue;
        
        for (const auto& [d, nextPos] : graph[currentPos]) {
            int nextDistance = d + distanceSum;

            if (nextDistance > m)
                continue;

            if (nextDistance < distance[nextPos]) {
                distance[nextPos] = nextDistance;
                pq.push({-nextDistance, nextPos});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (distance[i] <= m)
            totalItems += items[i];
    }
    return totalItems;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> r;

    vector<int> items(n + 1, 0);
    vector<vector<pair<int, int>>> graph(n + 1);
    int a, b, l;
    int answer = -1;

    for (int i = 1; i <= n; i++)
        cin >> items[i];

    for (int i = 0; i < r; i++) {
        cin >> a >> b >> l;
        graph[a].push_back({l, b});
        graph[b].push_back({l, a});
    }
    for (int i = 1; i <= n; i++)
        answer = max(answer, Dijkstra(i, graph, items));
    
    cout << answer;
    return 0;
}