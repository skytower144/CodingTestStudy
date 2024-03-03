#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXNUM 10000000

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, a, b, c;
    cin >> n >> m;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, MAXNUM));

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == MAXNUM) dist[i][j] = 0;
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}