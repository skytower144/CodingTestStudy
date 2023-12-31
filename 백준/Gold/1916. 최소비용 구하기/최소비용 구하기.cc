#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& distance) {
    priority_queue<pair<int, int>> pq;
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int distanceSum = -pq.top().first;
        int currentCity = pq.top().second;
        pq.pop();

        if (distance[currentCity] < distanceSum)
            continue;

        for (const auto [d, nextCity] : graph[currentCity]) {
            int nextDistance = d + distanceSum;
            
            if (nextDistance < distance[nextCity]) {
                distance[nextCity] = nextDistance;
                pq.push({-nextDistance, nextCity});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> distance(n + 1, INT_MAX);

    for (int i = 0; i < m; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        graph[s].push_back({d, e});
    }
    int startCity, endCity;
    cin >> startCity >> endCity;

    dijkstra(startCity, graph, distance);
    cout << distance[endCity];

    return 0;
}
