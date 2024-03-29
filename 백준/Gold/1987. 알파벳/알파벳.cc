#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char grid[21][21];
int charExists[27] = {0,};

int r, c;
int maxCount = -1;
int currentCount = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void DFS(int x, int y) {
    charExists[grid[y][x] - 'A'] = 1;
    currentCount++;

    if (maxCount < currentCount)
        maxCount = currentCount;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= c || ny < 0 || ny >= r)
            continue;
        
        if (charExists[grid[ny][nx] - 'A'] > 0)
            continue;
        
        DFS(nx, ny);
        charExists[grid[ny][nx] - 'A'] = 0;
        currentCount--;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> r >> c;
    string line;

    for (int i = 0; i < r; i++) {
        cin >> line;
        for (int j = 0; j < c; j++)
            grid[i][j] = line[j];
    }
    DFS(0, 0);
    cout << maxCount;
    return 0;
}