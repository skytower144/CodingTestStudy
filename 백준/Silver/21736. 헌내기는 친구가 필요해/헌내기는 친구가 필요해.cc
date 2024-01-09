#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n, m;

int FindPeople(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<vector<int>>& counter) {
    queue<pair<int, int>> q;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    int count = 0;

    q.push({x, y});
    visited[y][x] = 1;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            
            if (visited[ny][nx])
                continue;
            
            if (grid[ny][nx] == 'X')
                continue;

            visited[ny][nx] = 1;
            if (grid[ny][nx] == 'P') {
                counter[ny][nx] = counter[y][x] + 1;
                count++;
            }
            else
                counter[ny][nx] = counter[y][x];
            q.push({nx, ny});
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> counter(n, vector<int>(m, 0));
    string line;
    int startX = 0, startY = 0;

    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < m; j++) {
            grid[i][j] = line[j];
            if (grid[i][j] == 'I')
                startX = j, startY = i;
        }
    }
    int totalFound = FindPeople(startX, startY, grid, visited, counter);

    if (totalFound == 0)
        cout << "TT";
    else
        cout << totalFound;
    return 0;
}