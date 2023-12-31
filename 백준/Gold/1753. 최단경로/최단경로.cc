#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int v, e, k;
    cin >> v >> e >> k;

    int u, t, w;
    vector<vector<pair<int, int>>> graph(v + 1);
    vector<int> distance(v + 1, INT_MAX);

    for (int i = 0; i < e; i++) {
        cin >> u >> t >> w;
        graph[u].push_back(pair<int, int>(-w, t));
    }
    priority_queue<pair<int, int>> pq;
    pq.push(pair<int, int>(0, k));
    distance[k] = 0;
    
    while (!pq.empty()) {
        int distanceSum = -pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (distanceSum > distance[currentNode])
            continue;
        
        for (const auto& [d, node] : graph[currentNode]) {
            if (-d + distanceSum < distance[node]) {
                distance[node] = -d + distanceSum;
                pq.push(pair<int, int>(-distance[node], node));
            }
        }
    }
    for (int i = 1; i <= v; i++) {
        if (distance[i] == INT_MAX)
            cout << "INF" << '\n';
        else
            cout << distance[i] << '\n';
    }
    return 0;
}