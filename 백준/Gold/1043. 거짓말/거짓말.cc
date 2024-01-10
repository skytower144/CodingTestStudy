#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m, w;
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

    cin >> n >> m >> w;

    int woke, headCount;
    parent = vector<int>(n + 1);
    vector<vector<int>> parties(m);
    unordered_map<int, bool> wokeMap;
    unordered_map<int, bool> wokeParents;
    
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    
    for (int i = 0; i < w; i++) {
        cin >> woke;
        wokeMap[woke] = true;
    }
    for (int i = 0; i < m; i++) {
        cin >> headCount;
        vector<int> currentParty(headCount, 0);

        cin >> currentParty[0];
        parties[i].push_back(currentParty[0]);

        for (int j = 1; j < headCount; j++) {
            cin >> currentParty[j];
            parties[i].push_back(currentParty[j]);
            UnionParent(currentParty[j - 1], currentParty[j]);
        }
    }
    int answer = 0;
    for (const auto& [k, v] : wokeMap)
        wokeParents[FindParent(k)] = true;

    for (int i = 0; i < m; i++) {
        if (wokeParents[FindParent(parties[i][0])])
            continue;
        answer++;
    }
    cout << answer;
    return 0;
}