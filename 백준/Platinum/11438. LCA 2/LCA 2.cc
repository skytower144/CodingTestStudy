#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define LIMIT 18

using namespace std;

int n, m, a, b;
vector<vector<int>> graph;
vector<vector<int>> parent;
vector<int> depth;
vector<int> visited;

int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int j = LIMIT - 1; j >= 0; j--) {
        if (depth[a] - depth[b] >= pow(2, j))
            a = parent[a][j];
    }
    if (a == b)
        return a;
    
    for (int j = LIMIT - 1; j >= 0; j--) {
        if (parent[a][j] != parent[b][j]) {
            a = parent[a][j];
            b = parent[b][j];
        }
    }
    return parent[a][0];
}

void DFS(int node, int currentDepth) {
    depth[node] = currentDepth;
    visited[node] = 1;

    for (const auto& child : graph[node]) {
        if (visited[child])
            continue;
        
        parent[child][0] = node;
        DFS(child, currentDepth + 1);
    }
}
void SetParent() {
    DFS(1, 0);

    for (int j = 1; j < LIMIT; j++) {
        for (int i = 1; i <= n; i++)
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;
    
    graph = vector<vector<int>>(n + 1);
    parent = vector<vector<int>>(n + 1, vector<int>(LIMIT, 0));
    depth = vector<int>(n + 1, 0);
    visited = vector<int>(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    SetParent();
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
    return 0;
}