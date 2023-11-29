#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, h;
queue<vector<int>> q;
vector<vector<vector<int>>> box;
vector<vector<vector<int>>> visited;

bool CanGo(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0 || x >= m || y >= n || z >= h)
        return false;
    
    if (box[z][y][x] == -1)
        return false;
    
    if (visited[z][y][x] != -1)
        return false;
    return true;
}

int BFS() {
    int dx[] = { 0, 0,-1, 1, 0, 0};
    int dy[] = {-1, 1, 0, 0, 0, 0};
    int dz[] = { 0, 0, 0, 0,-1, 1};

    int days = 0;
    int nx, ny, nz;
    vector<int> tomato;

    while (!q.empty()) {
        tomato = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            nx = tomato[0] + dx[i];
            ny = tomato[1] + dy[i];
            nz = tomato[2] + dz[i];

            if (CanGo(nx, ny, nz)) {
                q.push({nx, ny, nz});
                visited[nz][ny][nx] = visited[tomato[2]][tomato[1]][tomato[0]] + 1;
                days = max(days, visited[nz][ny][nx]);
            }
        }
    }
    return days;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n >> h;

    box = vector<vector<vector<int>>>(h, vector<vector<int>>(n, vector<int>(m, 0)));
    visited = vector<vector<vector<int>>>(h, vector<vector<int>>(n, vector<int>(m, -1)));

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cin >> box[z][y][x];

                if (box[z][y][x] == 1) {
                    q.push({x, y, z});
                    visited[z][y][x] = 0;
                }
                if (box[z][y][x] == -1)
                    visited[z][y][x] = 0;
            }
        }
    }
    int days = BFS();

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (visited[z][y][x] == -1) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << days;
    return 0;
}