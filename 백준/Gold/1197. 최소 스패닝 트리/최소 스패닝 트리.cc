#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int v, e;

int Prim(int start, vector<vector<pair<int, int>>>& graph) {
    priority_queue<pair<int, int>> pq;
    vector<int> visited(v + 1, 0);
    int totalCost = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int popped = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (visited[popped])
            continue;

        visited[popped] = 1;
        totalCost += cost;

        for (const auto& [cst, next] : graph[popped]) {
            if (!visited[next])
                pq.push({-cst, next});
        }
    }
    return totalCost;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> v >> e;

    int answer = 0;
    vector<vector<pair<int, int>>> graph(v + 1);

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    answer = Prim(1, graph);
    cout << answer;
    return 0;
}