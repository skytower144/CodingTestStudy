#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define LIMIT 17

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<vector<int>> parent;
vector<vector<int>> dist;
vector<int> depth;
vector<int> visited;
int n, m, a, b, c;

void DFS(int node, int currentDepth) {
    depth[node] = currentDepth;
    visited[node] = 1;

    for (const auto& child : graph[node]) {
        int childNode = child.first;
        int length = child.second;

        if (visited[childNode])
            continue;
        
        parent[childNode][0] = node;
        dist[childNode][0] = length;
        DFS(childNode, currentDepth + 1);
    }
}
void SetParent() {
    DFS(1, 0);
    
    for (int j = 1; j < LIMIT; j++) {
        for (int i = 1; i <= n; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
            dist[i][j] = dist[i][j - 1] + dist[parent[i][j - 1]][j - 1];
        }
    }
}
int LCA(int a, int b) {
    int totalDistance = 0;

    if (depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int i = LIMIT - 1; i >= 0; i--) {
        if (depth[a] - depth[b] >= pow(2, i)) {
            totalDistance += dist[a][i];
            a = parent[a][i];
        }
    }
    if (a == b)
        return totalDistance;
    
    for (int i = LIMIT - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            totalDistance += dist[a][i] + dist[b][i];
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return totalDistance + dist[a][0] + dist[b][0];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    graph = vector<vector<pair<int, int>>>(n + 1);
    parent = vector<vector<int>>(n + 1, vector<int>(LIMIT, 0));
    dist = vector<vector<int>>(n + 1, vector<int>(LIMIT, 0));
    depth = vector<int>(n + 1, 0);
    visited = vector<int>(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    SetParent();
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << LCA(a, b) << '\n';   
    }
    return 0;
}