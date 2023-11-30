#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<vector<int>> grid;
vector<vector<int>> safeZone;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void BFS(int level, int x, int y) {
    queue<pair<int, int>> q;
    pair<int, int> area;
    int nx, ny;

    q.push(pair<int, int>(x, y));
    safeZone[y][x] = 1;

    while (!q.empty()) {
        area = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = area.first + dx[i];
            ny = area.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !safeZone[ny][nx] && grid[ny][nx] > level) {
                safeZone[ny][nx] = 1;
                q.push(pair<int, int>(nx, ny));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    grid = vector<vector<int>>(n, vector<int>(n, 0));
    int maxWaterLevel = 0;
    int maxSafeZones = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            maxWaterLevel = max(maxWaterLevel, grid[i][j]);
        }
    }
    for (int level = 0; level <= maxWaterLevel; level++) {
        int safeZoneCount = 0;
        safeZone = vector<vector<int>>(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > level && !safeZone[i][j]) {
                    BFS(level, j, i);
                    safeZoneCount++;
                }
            }
        }
        maxSafeZones = max(maxSafeZones, safeZoneCount);
    }
    cout << maxSafeZones;
    return 0;
}