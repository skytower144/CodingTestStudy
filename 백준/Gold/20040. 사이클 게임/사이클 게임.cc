#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> parent;

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

    cin >> n >> m;

    int a, b;
    vector<pair<int, int>> edges(m + 1);

    for (int i = 0; i <= n; i++)
        parent.push_back(i);

    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        edges[i] = {a, b};
    }
    for (int i = 1; i <= m; i++) {
        a = edges[i].first;
        b = edges[i].second;

        if (FindParent(a) != FindParent(b))
            UnionParent(a, b);
        else {
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}