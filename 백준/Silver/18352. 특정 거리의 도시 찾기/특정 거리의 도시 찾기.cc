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
        int currentCity = pq.top().second;
        int distanceSum = -pq.top().first;
        pq.pop();

        if (distanceSum > distance[currentCity])
            continue;
        
        for (const auto [d, nextCity] : graph[currentCity]) {
            int nextDistance = d + distanceSum;

            if (distance[nextCity] > nextDistance) {
                distance[nextCity] = nextDistance;
                pq.push({-nextDistance, nextCity});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, k, x;
    cin >> n >> m >> k >> x;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> distance(n + 1, INT_MAX);
    int startCity, endCity;

    for (int i = 0; i < m; i++) {
        cin >> startCity >> endCity;
        graph[startCity].push_back({1, endCity});
    }
    Dijkstra(x, graph, distance);
    bool flag = false;

    for (int i = 1; i <= n; i++) {
        if (distance[i] == k) {
            cout << i << '\n';
            flag = true;
        }
    }
    if (!flag) cout << -1;
    return 0;
}