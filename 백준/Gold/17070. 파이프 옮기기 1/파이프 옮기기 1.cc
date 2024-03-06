#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

vector<vector<int>> grid;
vector<vector<int>> visited;
int dx[] = {0, 1, 1};
int dy[] = {1, 1, 0};
int answer = 0;
int n;

enum Direction {
    DOWN,
    DIAGONAL,
    RIGHT
};

void PrintGrid() {
    cout << "=============================================\n";
    for (const auto& line : grid) {
        for (const auto& l : line)
            cout << l << " ";
        cout << '\n';
    }
}

void DFS(int x, int y, Direction dir) {
    int startIdx = 0, endIdx = 2;
    int nx, ny;

    if (x == n - 1 && y == n - 1) {
        answer++;
        return;
    }
    switch (dir) {
        case DOWN:
            endIdx = 1;
            break;
        
        case RIGHT:
            startIdx = 1;
            break;
        
        default:
            break;
    }
    for (int i = startIdx; i <= endIdx; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;

        if (grid[ny][nx])
            continue;       

        if (i == 1 && (grid[ny - 1][nx] || grid[ny][nx - 1]))
            continue;

        DFS(nx, ny, (Direction)i);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    grid = vector<vector<int>>(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    DFS(1, 0, RIGHT);
    cout << answer;

    return 0;
}