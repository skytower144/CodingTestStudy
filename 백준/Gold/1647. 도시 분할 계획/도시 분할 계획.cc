#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m;

int Prim(int start, vector<vector<pair<int, int>>>& graph) {
    vector<int> visited(n + 1, 0);
    priority_queue<pair<int, int>> pq;
    int totalCost = 0;
    int maxCost = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int popped = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (visited[popped])
            continue;

        visited[popped] = 1;
        totalCost += cost;
        maxCost = max(maxCost, cost);

        for (const auto& [cst, next] : graph[popped]) {
            if (!visited[next])
                pq.push({-cst, next});
        }
    }
    return totalCost - maxCost;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;

    int a, b, c;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    int answer = Prim(1, graph);
    cout << answer;
    return 0;
}