#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> parent;
vector<int> dist;
vector<int> depth;
vector<int> visited;
int n, m, a, b, c;

void DFS(int node, int currentDepth) {
    depth[node] = currentDepth;
    visited[node] = 1;

    for (const auto& child : graph[node]) {
        if (visited[child.first])
            continue;
        
        parent[child.first] = node;
        dist[child.first] = child.second;
        DFS(child.first, currentDepth + 1);
    }
}
int LCA(int a, int b) {
    int totalDistance = 0;

    if (depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    while (depth[a] > depth[b]) {
        totalDistance += dist[a];
        a = parent[a];
    }
    while (a != b) {
        totalDistance += dist[a] + dist[b];
        a = parent[a];
        b = parent[b];
    }
    return totalDistance;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    graph = vector<vector<pair<int, int>>>(n + 1);
    parent = vector<int>(n + 1, 0);
    dist = vector<int>(n + 1, 0);
    depth = vector<int>(n + 1, 0);
    visited = vector<int>(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    DFS(1, 0);
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << LCA(a, b) << '\n';   
    }
    return 0;
}