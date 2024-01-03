#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>

using namespace std;

int n, m, k, x;

void Dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& distance) {
    priority_queue<pair<int, int>> pq;
    set<int> cities;
    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty()) {
        int currentCity = pq.top().second;
        int distanceSum = -pq.top().first;
        pq.pop();

        if (distanceSum > distance[currentCity])
            continue;

        if (distance[currentCity] == k)
            cities.insert(currentCity);
        
        for (const auto [d, nextCity] : graph[currentCity]) {
            int nextDistance = d + distanceSum;

            if (distance[nextCity] > nextDistance) {
                distance[nextCity] = nextDistance;
                pq.push({-nextDistance, nextCity});
            }
        }
    }
    for (auto c : cities) cout << c << '\n';
    if (!cities.size()) cout << -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> k >> x;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> distance(n + 1, INT_MAX);
    int startCity, endCity;

    for (int i = 0; i < m; i++) {
        cin >> startCity >> endCity;
        graph[startCity].push_back({1, endCity});
    }
    Dijkstra(x, graph, distance);
    return 0;
}