#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

void Dijkstra(int start, vector<vector<pair<int, int>>>& roads, vector<int>& distance) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty()) {
        int distanceSum = -pq.top().first;
        int currentPos = pq.top().second;
        pq.pop();

        if (distanceSum > distance[currentPos])
            continue;
        
        for (const auto [d, nextPos] : roads[currentPos]) {
            int nextDistance = d + distanceSum;

            if (nextDistance < distance[nextPos]) {
                distance[nextPos] = nextDistance;
                pq.push({-nextDistance, nextPos});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    vector<vector<pair<int, int>>> roads(10001);
    vector<int> distance(10001, INT_MAX);
    int shortStart, shortEnd, length;

    for (int i = 0; i < d; i++)
        roads[i].push_back({1, i + 1});
     
    for (int i = 0; i < n; i++) {
        cin >> shortStart >> shortEnd >> length;
        roads[shortStart].push_back({length, shortEnd});
    }
    Dijkstra(0, roads, distance);
    cout << distance[d];

    return 0;
}