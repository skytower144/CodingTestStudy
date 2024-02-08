#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXNUM 10000001

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> distance(n + 1, vector<int>(n + 1, MAXNUM));
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, -1));
    int st, ed, time;

    for (int i = 1; i <= n; i++)
        distance[i][i] = 0;
    
    for (int i = 0; i < m; i++) {
        cin >> st >> ed >> time;
        distance[st][ed] = time;
        graph[st][ed] = ed;

        distance[ed][st] = time;
        graph[ed][st] = st;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    graph[i][j] = graph[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] < 0)
                cout << '-' << " ";
            else
                cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}