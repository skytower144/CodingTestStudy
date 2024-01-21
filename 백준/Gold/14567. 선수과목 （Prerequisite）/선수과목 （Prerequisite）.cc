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
    vector<int> semester(n + 1, 1001);
    queue<int> q;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            semester[i] = 1;
        }
    }
    while (!q.empty()) {
        int popped = q.front();
        q.pop();

        for (const auto& next : graph[popped]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(next);
                semester[next] = min(semester[next], semester[popped] + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << semester[i] << " ";
    return 0;
}