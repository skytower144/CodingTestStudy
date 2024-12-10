#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 50 * 50 + 1;

vector<vector<int>> grid;
int dx[] = {  0, 0,-1, 1, -1,-1, 1, 1 };
int dy[] = { -1, 1, 0, 0, -1, 1,-1, 1 };
int n, m;

int GetDistance(int x, int y)
{
    vector<vector<int>> distance(n, vector<int>(m, MAX));
    queue<pair<int, int>> q;

    q.push({ x, y });
    distance[y][x] = 0;

    int minDistance = MAX;

    while (!q.empty())
    {
        pair<int, int> popped = q.front();
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = popped.first + dx[i];
            int ny = popped.second + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            if (distance[ny][nx] <= distance[popped.second][popped.first] + 1)
                continue;

            distance[ny][nx] = distance[popped.second][popped.first] + 1;
            q.push({ nx, ny });

            if (grid[ny][nx] == 1)
                minDistance = min(minDistance, distance[ny][nx]);
        }
    }

    return minDistance;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;

    grid = vector<vector<int>>(n, vector<int>(m, 0));
    int answer = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                continue;

            answer = max(answer, GetDistance(j, i));
        }
    }

    cout << answer;

    return 0;
}