#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define LIMIT 15

using namespace std;

int n, a, b;
vector<vector<int>> graph;
vector<vector<int>> parent;
vector<int> visited;
vector<int> depth;

int GetRoot(int node) {
    while (parent[node][0] != 0)
        node = parent[node][0];
    return node;
}
void DFS(int node, int currentDepth) {
    visited[node] = 1;
    depth[node] = currentDepth;

    for (const auto& child : graph[node]) {
        if (visited[child])
            continue;
        
        DFS(child, currentDepth + 1);
    }
}
void SetParent() {
    DFS(GetRoot(1), 0);

    for (int j = 1; j < LIMIT; j++) {
        for (int i = 1; i <= n; i++)
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
}
int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int i = LIMIT - 1; i >= 0; i--) {
        if (depth[a] - depth[b] >= pow(2, i))
            a = parent[a][i];
    }
    if (a == b)
        return a;
    
    for (int i = LIMIT - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        
        graph = vector<vector<int>>(n + 1);
        parent = vector<vector<int>>(n + 1, vector<int>(LIMIT, 0));
        visited = vector<int>(n + 1, 0);
        depth = vector<int>(n + 1, 0);

        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            parent[b][0] = a;
        }
        SetParent();
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
    return 0;
}