#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

void Dijkstra(int x, vector<vector<pair<int, int>>>& graph, vector<int>& duration) {
    priority_queue<pair<int, int>> pq;
    duration[x] = 0;
    pq.push({0, x});

    while (!pq.empty()) {
        int currentTown = pq.top().second;
        int elapsedTime = -pq.top().first;
        pq.pop();

        if (elapsedTime > duration[currentTown])
            continue;
        
        for (const auto [time, nextTown] : graph[currentTown]) {
            int nextElapsedTime = time + elapsedTime;

            if (nextElapsedTime < duration[nextTown]) {
                duration[nextTown] = nextElapsedTime;
                pq.push({-nextElapsedTime, nextTown});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, x;
    int roadStart, roadEnd, time;
    cin >> n >> m >> x;

    vector<vector<pair<int, int>>> graph1(n + 1);
    vector<vector<pair<int, int>>> graph2(n + 1);

    vector<int> duration1(n + 1, INT_MAX);
    vector<int> duration2(n + 1, INT_MAX);

    for (int i = 0; i < m; i++) {
        cin >> roadStart >> roadEnd >> time;
        graph1[roadEnd].push_back({time, roadStart});
        graph2[roadStart].push_back({time, roadEnd});
    }
    Dijkstra(x, graph1, duration1);
    Dijkstra(x, graph2, duration2);
    
    int maxTime = -1;
    for (int i = 1; i <= n; i++) {
        // cout << i << " : " << duration1[i] << '+' << duration2[i] << endl;
        maxTime = max(maxTime, duration1[i] + duration2[i]);
    }
    cout << maxTime;
    return 0;
}
