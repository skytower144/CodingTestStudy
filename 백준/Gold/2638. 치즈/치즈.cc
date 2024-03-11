#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> grid;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m;
int totalCheese = 0;

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> isAir(n, vector<int>(m, 0));
    vector<pair<int, int>> outerCheese;
    vector<pair<int, int>> willMelt;
    int nx, ny;
    
    visited[y][x] = 1;
    isAir[0][0] = 1;
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
            
            if (visited[ny][nx])
                continue;
            
            visited[ny][nx] = 1;

            if (grid[ny][nx] == 1)
                outerCheese.push_back({nx, ny});
            else {
                q.push({nx, ny});
                isAir[ny][nx] = 1;
            }
        }
    }
    for (const auto& [posX, posY] : outerCheese) {
        int air = 0;

        for (int j = 0; j < 4; j++) {
            nx = posX + dx[j];
            ny = posY + dy[j];

            if (grid[ny][nx] == 0 && isAir[ny][nx])
                air++;
        }
        if (air >= 2)
            willMelt.push_back({posX, posY});
    }
    for (const auto& [posX, posY] : willMelt) {
        grid[posY][posX] = 0;
        totalCheese--;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m, 0));
    int time = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];

            if (grid[i][j])
                totalCheese++;
        }
    }
    while (totalCheese) {
        BFS(0, 0);
        time++;
    }
    cout << time;
    return 0;
}