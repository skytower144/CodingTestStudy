#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 50 * 50 + 1;

vector<vector<int>> grid;
vector<vector<int>> dist;
queue<pair<int, int>> q;

int dx[] = { 0, 0,-1, 1, -1,-1, 1, 1 };
int dy[] = { -1, 1, 0, 0, -1, 1,-1, 1 };
int n, m;
int answer = -1;

void BFS()
{
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

            if (dist[ny][nx] <= dist[popped.second][popped.first] + 1)
                continue;

            dist[ny][nx] = dist[popped.second][popped.first] + 1;
            q.push({ nx, ny });

            answer = max(answer, dist[ny][nx]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;

    grid = vector<vector<int>>(n, vector<int>(m, 0));
    dist = vector<vector<int>>(n, vector<int>(m, MAX));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 1)
            {
                q.push({ j, i });
                dist[i][j] = 0;
            }
        }
    }

    BFS();
    cout << answer;

    return 0;
}