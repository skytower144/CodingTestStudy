#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

void Dijkstra(vector<vector<pair<int, int>>>& graph, vector<long long>& distance, vector<int>& visibility) {
    distance[0] = 0;
    priority_queue<pair<long long, long long>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        long long distanceSum = -pq.top().first;
        long long currentPos = pq.top().second;
        pq.pop();

        if (distanceSum > distance[currentPos])
            continue;
        
        for (const auto& [d, nextPos] : graph[currentPos]) {
            if (visibility[nextPos])
                continue;
            
            long long nextDistance = d + distanceSum;

            if (nextDistance < distance[nextPos]) {
                distance[nextPos] = nextDistance;
                pq.push({-nextDistance, nextPos});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b, t;
    vector<vector<pair<int, int>>> graph(n);
    vector<long long> distance(n, LLONG_MAX);
    vector<int> visibility(n, 0);

    for (int i = 0; i < n; i++)
        cin >> visibility[i];
    visibility[visibility.size() - 1] = 0;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        graph[a].push_back({t, b});
        graph[b].push_back({t, a});
    }
    Dijkstra(graph, distance, visibility);
    
    if (distance[n - 1] == LLONG_MAX)
        cout << -1;
    else
        cout << distance[n - 1];
    return 0;
}