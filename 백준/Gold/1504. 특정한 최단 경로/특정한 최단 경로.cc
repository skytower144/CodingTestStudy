#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

void Dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& distance) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty()) {
        int distanceSum = -pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (distanceSum > distance[currentNode])
            continue;

        for (const auto& [d, nextNode] : graph[currentNode]) {
            int nextDistance = distanceSum + d;

            if (nextDistance < distance[nextNode]) {
                distance[nextNode] = nextDistance;
                pq.push({-nextDistance, nextNode});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, e;
    int a, b, c;
    int v1, v2;
    int answer = -1;
    cin >> n >> e;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> distance1(n + 1, INT_MAX);
    vector<int> distanceV1(n + 1, INT_MAX);
    vector<int> distanceV2(n + 1, INT_MAX);

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    cin >> v1 >> v2;
    
    Dijkstra(1, graph, distance1);
    Dijkstra(v1, graph, distanceV1);
    Dijkstra(v2, graph, distanceV2);
    
    if (distance1[v1] < INT_MAX && distanceV1[v2] < INT_MAX && distanceV2[n] < INT_MAX &&
        distance1[v2] < INT_MAX && distanceV2[v1] < INT_MAX && distanceV1[n] < INT_MAX) {
    
        answer = min(
            distance1[v1] + distanceV1[v2] + distanceV2[n],
            distance1[v2] + distanceV2[v1] + distanceV1[n]
        );
    }
    cout << answer;
    return 0;
}