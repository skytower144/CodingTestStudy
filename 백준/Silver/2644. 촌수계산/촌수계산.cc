#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

void BFS(vector<vector<int>>& graph, vector<int>& distance, int start) {
    queue<int> q;
    vector<int> visited(n + 1, 0);

    q.push(start);
    distance[start] = 0;
    visited[start] = 1;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (const auto& linked : graph[current]) {
            if (!visited[linked]) {
                q.push(linked);
                distance[linked] = distance[current] + 1;
                visited[linked] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    int a, b;
    cin >> a >> b;

    int m;
    cin >> m;

    int x, y;
    vector<vector<int>> graph(n + 1);
    vector<int> distance(n + 1, -1);

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    BFS(graph, distance, a);
    cout << distance[b];
    return 0;
}