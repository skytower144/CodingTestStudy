#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> parent;

int FindParent(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = FindParent(parent[x]);
}
void UnionParent(int a, int b) {
    int parentA = FindParent(a);
    int parentB = FindParent(b);

    if (parentA < parentB)
        parent[parentB] = parentA;
    else
        parent[parentA] = parentB;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> edges;
    int generatorNum, u, v, w;

    for (int i = 0; i <= n; i++)
        parent.push_back(i);

    for (int i = 0; i < k; i++) {
        cin >> generatorNum;
        edges.push_back({0, 0, generatorNum});
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    int answer = 0;

    for (const auto& edge : edges) {
        if (FindParent(edge[1]) != FindParent(edge[2])) {
            UnionParent(edge[1], edge[2]);
            answer += edge[0];
        }
    }
    cout << answer;
    return 0;
}
