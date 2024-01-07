#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m;

bool BelmanFord(vector<vector<int>>& edges, vector<long long>& duration) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            int from = edges[j][0];
            int to = edges[j][1];
            int time = edges[j][2];

            if (duration[from] == INT_MAX)
                continue;
            
            if (duration[to] > duration[from] + time) {
                if (i == n)
                    return true;
                duration[to] = duration[from] + time;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> edges;
    vector<long long> duration(n + 1, INT_MAX);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    duration[1] = 0;
    if (BelmanFord(edges, duration)) {
        cout << -1;
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        if (duration[i] == INT_MAX)
            cout << -1 << '\n';
        else
            cout << duration[i] << '\n';
    }
    return 0;
}