#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m;

void BFS(int start_x, int start_y, vector<vector<int>>& grid, vector<vector<int>>& distance) {
    queue<pair<int, int>> q;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    int x, y, nx, ny;
    
    q.push({start_x, start_y});
    distance[start_y][start_x] = 0;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[ny][nx] != 0) {
                if (distance[y][x] + 1 < distance[ny][nx]) {
                    distance[ny][nx] = distance[y][x] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    int start_x, start_y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                start_x = j;
                start_y = i;
            }
        }
    }
    BFS(start_x, start_y, grid, distance);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (distance[i][j] == INT_MAX) {
                if (grid[i][j] == 0)
                    cout << 0 << " ";
                else
                    cout << -1 << " ";
            }
            else
                cout << distance[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}