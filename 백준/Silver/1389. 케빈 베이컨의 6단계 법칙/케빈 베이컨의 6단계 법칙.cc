#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
    int a, b;

    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX)
                    continue;
                
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                graph[j][i] = graph[i][j];
            }
        }
    }
    int answer = 1;
    int minBacons = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int bacons = 0;

        for (int j = 1; j <= n; j++) {
            if (graph[i][j] != INT_MAX)
                bacons += graph[i][j];
        }
        if (bacons < minBacons) {
            answer = i;
            minBacons = bacons;
        }
    }
    cout << answer;
    return 0;
}
