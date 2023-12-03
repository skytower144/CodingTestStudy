#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int grid[1001][1001];
int visited[1001][1001][2];
int dx[] = {0, 0, -1 ,1};
int dy[] = {-1, 1, 0, 0};
int n, m, nx, ny;

int BFS(int x, int y) {
    queue<vector<int>> q;
    q.push({x, y, false});
    int wallBreak;

    while (!q.empty()) {
        x = q.front()[0];
        y = q.front()[1];
        wallBreak = q.front()[2];
        q.pop();

        if (x == m - 1 && y == n - 1)
            return visited[y][x][wallBreak];

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (grid[ny][nx] == 0 && !visited[ny][nx][wallBreak]) {
                    // 같은 차원 내에서 이동
                    visited[ny][nx][wallBreak] = visited[y][x][wallBreak] + 1;
                    q.push({nx, ny, wallBreak});
                }
                else if (grid[ny][nx] == 1 && !wallBreak) {
                    // 다른 차원으로 이동
                    visited[ny][nx][true] = visited[y][x][false] + 1;
                    q.push({nx, ny, true});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    string line;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < m; j++)
            grid[i][j] = line[j] - '0';
    }
    visited[0][0][false] = 1;
    answer = BFS(0, 0);

    cout << answer;
    return 0;
}