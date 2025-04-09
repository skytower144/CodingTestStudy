#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void BFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[y][x] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;

            if (visited[ny][nx])
                continue;

            if (grid[ny][nx] != 1)
                continue;

            visited[ny][nx] = true;
            q.push({ nx, ny });
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int m, n, k;
        cin >> m >> n >> k;

        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> wormPos;

        while (k--)
        {
            int x, y;
            cin >> x >> y;
            grid[y][x] = 1;
            wormPos.push_back({ x, y });
        }

        int totalWorms = 0;
        for (auto pos : wormPos)
        {
            if (visited[pos.second][pos.first])
                continue;

            totalWorms++;
            BFS(grid, visited, pos.first, pos.second, n, m);
        }

        cout << totalWorms << '\n';
    }

    return 0;
}