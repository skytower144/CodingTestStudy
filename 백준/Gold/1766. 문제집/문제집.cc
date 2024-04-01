#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<int> order;
    priority_queue<int> q;
    int first, second;

    while (m--) {
        cin >> first >> second;
        graph[first].push_back(second);
        indegree[second]++;
    }
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(-i);
    }
    while (!q.empty()) {
        int popped = -q.top();
        cout << popped << " ";
        q.pop();

        for (const auto& next : graph[popped]) {
            indegree[next]--;
            if (indegree[next] == 0)
                q.push(-next);
        }
    }
    return 0;
}