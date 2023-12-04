#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int k, w, h;
int grid[200][200];
int visited[200][200][30];
int dx[] = { 0, 0,-1, 1};
int dy[] = {-1, 1, 0, 0};
int dxa[] = {1, 2, 2, 1,-1,-2,-2,-1};
int dya[] = {-2,-1, 1, 2, 2, 1,-1,-2};
int nx, ny;

int FindPath(int x, int y) {
    visited[y][x][0] = 1;
    queue<vector<int>> q;
    q.push({x, y, 0});

    vector<int> pos;
    int skillCount;

    while (!q.empty()) {
        pos = q.front();
        q.pop();

        x = pos[0];
        y = pos[1];
        skillCount = pos[2];

        if (x == w - 1 && y == h - 1)
            return visited[h - 1][w - 1][skillCount] - 1;

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < w && ny >= 0 && ny < h && grid[ny][nx] == 0 && !visited[ny][nx][skillCount]) {
                visited[ny][nx][skillCount] = visited[y][x][skillCount] + 1;
                q.push({nx, ny, skillCount});
            }
        }
        if (skillCount >= k) continue;

        for (int i = 0; i < 8; i++) {
            nx = x + dxa[i];
            ny = y + dya[i];

            if (nx >= 0 && nx < w && ny >= 0 && ny < h && grid[ny][nx] == 0 && !visited[ny][nx][skillCount + 1]) {
                visited[ny][nx][skillCount + 1] = visited[y][x][skillCount] + 1;
                q.push({nx, ny, skillCount + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> k >> w >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];
    }
    int answer = FindPath(0, 0);
    cout << answer;
    return 0;
}