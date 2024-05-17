#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> parent;
unordered_map<int, int> generator;

int FindParent(int x) {
    if (parent[x] != x)
        parent[x] = FindParent(parent[x]);
    return parent[x];
}
void UnionParent(int a, int b) {
    int parentA = FindParent(a);
    int parentB = FindParent(b);

    if (generator.count(parentA))
        generator[parentB] = parentA;

    else if (generator.count(parentB))
        generator[parentA] = parentB;

    else if (parentA < parentB)
        parent[parentB] = parentA;

    else
        parent[parentA] = parentB; 
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int num, u, v, w;
    vector<vector<int>> edges;

    for (int i = 0; i < k; i++) {
        cin >> num;
        generator[num]++;    
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    for (int i = 0; i <= n; i++)
        parent.push_back(i);

    sort(edges.begin(), edges.end());
    int answer = 0;

    for (const auto& edge : edges) {
        int parent1 = FindParent(edge[1]);
        int parent2 = FindParent(edge[2]);

        if (parent1 != parent2 && !(generator.count(parent1) && generator.count(parent2))) {
            UnionParent(edge[1], edge[2]);
            answer += edge[0];
        }
    }
    cout << answer;
    return 0;
}
