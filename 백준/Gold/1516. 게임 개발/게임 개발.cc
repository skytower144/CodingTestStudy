#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<int> buildTime(n + 1, 0);
    vector<int> requiredTime(n + 1, 0);
    queue<int> q;
    int requiredBuilding;

    for (int i = 1; i <= n; i++) {
        cin >> buildTime[i];
        
        while (true) {
            cin >> requiredBuilding;
            if (requiredBuilding == -1) break;

            graph[requiredBuilding].push_back(i);
            indegree[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            requiredTime[i] = buildTime[i];
        }
    }
    while (!q.empty()) {
        int popped = q.front();
        q.pop();

        for (const auto& next : graph[popped]) {
            indegree[next]--;
            requiredTime[next] = max(requiredTime[next], requiredTime[popped]);

            if (indegree[next] == 0) {
                q.push(next);
                requiredTime[next] += buildTime[next];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << requiredTime[i] << '\n';

    return 0;
}