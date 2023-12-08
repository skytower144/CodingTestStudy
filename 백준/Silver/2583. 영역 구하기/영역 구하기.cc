#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, k;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int nx, ny;

int BFS(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited) {
    queue<pair<int, int>> q;
    pair<int, int> visiting;

    visited[y][x] = 1;
    q.push(pair<int, int>(x, y));
    int areaSize = 1;

    while (!q.empty()) {
        visiting = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = visiting.first + dx[i];
            ny = visiting.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[ny][nx] && !grid[ny][nx]) {
                visited[ny][nx] = 1;
                q.push(pair<int, int>(nx, ny));
                areaSize++;
            }
        }
    }
    return areaSize;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> m >> n >> k;

    vector<vector<int>> grid(m, vector<int>(n, 0));
    vector<vector<int>> visited(m, vector<int>(n, 0));
    priority_queue<int> pq;
    int areaCount = 0, areaSize = 0;

    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = m - y2; y < m - y1;  y++) {
            for (int x = x1; x < x2; x++)
                grid[y][x] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && !grid[i][j]) {
                areaSize = BFS(j, i, grid, visited);
                pq.push(areaSize * -1);
                areaCount++;
            }
        }
    }
    cout << areaCount << '\n';

    int qSize = pq.size();
    for (int i = 0; i < qSize; i++) {
        cout << pq.top() * -1 << " ";
        pq.pop();
    }
}
