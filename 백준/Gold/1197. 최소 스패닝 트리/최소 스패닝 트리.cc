#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> parent;
int v, e;

int FindParent(int x) {
    if (parent[x] != x)
        parent[x] = FindParent(parent[x]);
    return parent[x];
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> v >> e;

    int a, b, c;
    vector<vector<int>> edges;

    for (int i = 0; i <= v; i++)
        parent.push_back(i);

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
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