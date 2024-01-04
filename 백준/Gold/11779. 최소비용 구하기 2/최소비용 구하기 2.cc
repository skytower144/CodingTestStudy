#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    int startCity, endCity;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    priority_queue<pair<int, int>> pq;
    vector<int> costs(n + 1, INT_MAX);
    vector<vector<int>> paths(n + 1);

    for (int i = 0; i < m; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        graph[s].push_back({cost, e});
    }
    cin >> startCity >> endCity;

    costs[startCity] = 0;
    paths[startCity].push_back(startCity);
    pq.push({0, startCity});

    while (!pq.empty()) {
        int currentCity = pq.top().second;
        int costSum = -pq.top().first;
        pq.pop();

        if (costSum > costs[currentCity])
            continue;
        
        for (const auto [cost, nextCity] : graph[currentCity]) {
            int nextCost = cost + costSum;
            if (costs[nextCity] > nextCost) {
                costs[nextCity] = nextCost;
                paths[nextCity] = paths[currentCity];
                paths[nextCity].push_back(nextCity);
                pq.push({-nextCost, nextCity});
            }
        }
    }
    cout << costs[endCity] << '\n';
    cout << paths[endCity].size() << '\n';
    
    for (const auto city : paths[endCity])
        cout << city << " ";

    return 0;
}