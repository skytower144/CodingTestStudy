#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
vector<int> visited;
vector<vector<int>> graph;

void DFS(int node) {
    visited[node] = 1;
    cout << node << " ";

    for (const auto& next : graph[node]) {
        if (!visited[next])
            DFS(next);
    }
}
void BFS(int node) {
    queue<int> q;
    visited[node] = 1;
    q.push(node);
    cout << node << " ";

    while (!q.empty()) {
        int popped = q.front();
        q.pop();

        for (const auto& next : graph[popped]) {
            if (visited[next])
                continue;

            visited[next] = 1;
            q.push(next);
            cout << next << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m >> v;

    graph = vector<vector<int>>(n + 1);
    int from, to;

    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());
    
    visited = vector<int>(n + 1, 0);
    DFS(v);
    cout << '\n';

    visited = vector<int>(n + 1, 0);
    BFS(v);
    return 0;
}