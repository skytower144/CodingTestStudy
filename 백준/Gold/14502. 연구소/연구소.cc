#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int leftSafeZones = -3;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vector<vector<int>> grid;
vector<pair<int, int>> wallPos;
vector<pair<int, int>> virusPos;

int BFS() {
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    pair<int, int> virus;
    int nx, ny;
    int infectedZones = 0;

    for (auto pos : virusPos) {
        q.push(pair<int, int>(pos.first, pos.second));
        visited[pos.second][pos.first] = 1;
    }
    while (!q.empty()) {
        virus = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = virus.first + dx[i];
            ny = virus.second + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[ny][nx] && grid[ny][nx] == 0) {
                q.push(pair<int, int>(nx, ny));
                visited[ny][nx] = 1;
                infectedZones++;
            }
        }
    }
    return leftSafeZones - infectedZones;
}

void SetGridWalls(pair<int, int> a, pair<int, int> b, pair<int, int> c, int putWall) {
    grid[a.second][a.first] = putWall;
    grid[b.second][b.first] = putWall;
    grid[c.second][c.first] = putWall;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 0) {
                wallPos.push_back(pair<int, int>(j, i));
                leftSafeZones++;
            }
            else if (grid[i][j] == 2)
                virusPos.push_back(pair<int, int>(j, i));
        }
    }
    int possibleWalls = wallPos.size();
    int maxSafeZones = 0;

    for (int i = 0; i < possibleWalls - 2; i++) {
        for (int j = i + 1; j < possibleWalls - 1; j++) {
            for (int k = j + 1; k < possibleWalls; k++) {
                SetGridWalls(wallPos[i], wallPos[j], wallPos[k], true);
                maxSafeZones = max(maxSafeZones, BFS());
                SetGridWalls(wallPos[i], wallPos[j], wallPos[k], false);
            }
        }
    }
    cout << maxSafeZones;
    return 0;
}