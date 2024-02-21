#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int pictures = 0;
int largestPicture = 0;
int n, m;

int BFS(vector<vector<int>>& graph, vector<vector<int>>& visited, int x, int y) {
    queue<pair<int, int>> q;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    int nx, ny;
    int count = 0;

    visited[y][x] = 1;
    count++;
    q.push({x, y});

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            
            if (!graph[ny][nx] || visited[ny][nx])
                continue;
            
            visited[ny][nx] = 1;
            count++;
            q.push({nx, ny});
        }
    }
    return count;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int pictureSize;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] && !visited[i][j]) {
                pictures++;
                pictureSize = BFS(graph, visited, j, i);
                largestPicture = max(largestPicture, pictureSize);
            }
        }
    }
    cout << pictures << '\n' << largestPicture;
    return 0;
}