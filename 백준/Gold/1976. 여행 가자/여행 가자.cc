#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<int> parent;

int FindParent(int x) {
    if (parent[x] == x) return x;
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> schedule(m, 0);
    int linked;

    for (int i = 0; i <= n; i++)
        parent.push_back(i);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> linked;
            if (linked)
                UnionParent(i, j);
        }
    }
    for (int i = 0; i < m; i++)
        cin >> schedule[i];
    
    int firstParent = FindParent(schedule[0]);
    for (int i = 1; i < m; i++) {
        if (firstParent != FindParent(schedule[i])) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}