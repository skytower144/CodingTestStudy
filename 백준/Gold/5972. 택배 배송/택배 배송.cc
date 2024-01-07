#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

void Dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& fodder) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    fodder[start] = 0;

    while (!pq.empty()) {
        int foodSum = -pq.top().first;
        int currentBarn = pq.top().second;
        pq.pop();

        for (const auto& [food, nextBarn] : graph[currentBarn]) {
            int nextFood = food + foodSum;

            if (nextFood < fodder[nextBarn]) {
                fodder[nextBarn] = nextFood;
                pq.push({-nextFood, nextBarn});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> fodder(n + 1, INT_MAX);
    int A_i, B_i, C_i;

    for (int i = 0; i < m; i++) {
        cin >> A_i >> B_i >> C_i;
        graph[A_i].push_back({C_i, B_i});
        graph[B_i].push_back({C_i, A_i});
    }
    Dijkstra(1, graph, fodder);
    cout << fodder[n];
    return 0;
}