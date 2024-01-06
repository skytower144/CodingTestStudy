#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, d, c, a, b, s;
        cin >> n >> d >> c;

        vector<vector<pair<int, int>>> graph(n + 1);
        vector<int> distance(n + 1, INT_MAX);

        for (int i = 0; i < d; i++) {
            cin >> a >> b >> s;
            graph[b].push_back({s, a});
        }
        priority_queue<pair<int, int>> pq;
        pq.push({0, c});
        distance[c] = 0;

        while (!pq.empty()) {
            int distanceSum = -pq.top().first;
            int currentCom = pq.top().second;
            pq.pop();

            if (distanceSum > distance[currentCom])
                continue;
            
            for (const auto& [d, nextCom] : graph[currentCom]) {
                int nextDistance = d + distanceSum;
                
                if (nextDistance < distance[nextCom]) {
                    distance[nextCom] = nextDistance;
                    pq.push({-nextDistance, nextCom});
                }
            }
        }
        int infected = 0;
        int totalDuration = -1;

        for (int i = 1; i <= n; i++) {
            if (distance[i] != INT_MAX) {
                infected++;
                totalDuration = max(totalDuration, distance[i]);
            }
        }
        cout << infected << " " << totalDuration << '\n';
    }
}