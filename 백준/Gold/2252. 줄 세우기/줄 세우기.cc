#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b;
    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<int> result;
    queue<int> q;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            result.push_back(i);
        }
    }
    while (!q.empty()) {
        int popped = q.front();
        q.pop();

        for (const auto& neighbor : graph[popped]) {
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                q.push(neighbor);
                result.push_back(neighbor);
            }
        }
    }
    for (const auto& num : result)
        cout << num << " ";
    return 0;
}