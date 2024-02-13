#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int answer = 0;
vector<vector<int>> grid;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool CanGo(int x, int y) {
    return x >= 0 && x < m && y >= 0 && y < n && grid[y][x] != 1;
}
bool CanBack(int x, int y, int dir) {
    dir = (dir + 2) % 4;
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    return CanGo(nx, ny);
}
bool DetectFilth(int x, int y) {
    int nx, ny;

    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (CanGo(nx, ny) && grid[ny][nx] == 0)
            return true;
    }
    return false;
}
void Clean(int x, int y, int dir) {
    while (true) {
        if (grid[y][x] == 0) {
            grid[y][x] = 2;
            answer++;
        }
        if (!DetectFilth(x, y)) {
            if (CanBack(x, y, dir)) {
                x += dx[(dir + 2) % 4];
                y += dy[(dir + 2) % 4];
            }
            else
                return;
        }
        else {
            dir = (dir + 3) % 4;
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (CanGo(nx, ny) && grid[ny][nx] == 0) {
                x = nx; y = ny;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int r, c, d;

    cin >> n >> m;
    cin >> r >> c >> d;

    grid = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    
    Clean(c, r, d);
    cout << answer;
    return 0;
}