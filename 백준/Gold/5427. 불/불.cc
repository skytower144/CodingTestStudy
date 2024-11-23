#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool CanGo(vector<vector<char>>& grid, int x, int y)
{
	int h = grid.size();
	int w = grid[0].size();

	if (x < 0 || x >= w || y < 0 || y >= h)
		return false;

	if (grid[y][x] == '#' || grid[y][x] == '*')
		return false;

	return true;
}

bool IsExit(vector<vector<char>>& grid, int x, int y)
{
	int h = grid.size();
	int w = grid[0].size();

	if (x == 0 || x == w - 1)
		return true;

	if (y == 0 || y == h - 1)
		return true;

	return false;
}

int BFS(vector<vector<char>>& grid, int playerX, int playerY, vector<pair<int, int>>& firePos)
{
	vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
	queue<pair<int, int>> q;
	int fireCt = 0;
	int playerCt = 1;

	for (int i = 0; i < firePos.size(); i++)
	{
		fireCt++;
		q.push({ firePos[i].first, firePos[i].second });
	}
	q.push({ playerX, playerY });
	visited[playerY][playerX] = 1;

	int dx[] = { 0, 0, -1, 1 };
	int dy[] = { -1, 1, 0, 0 };

	while (!q.empty())
	{
		int addedFire = 0;

		while (fireCt > 0)
		{
			fireCt--;

			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (CanGo(grid, nx, ny))
				{
					grid[ny][nx] = '*';
					q.push({ nx, ny });
					addedFire++;
				}
			}
		}
		fireCt = addedFire;

		if (q.empty())
			break;

		int addedPlayer = 0;

		while (playerCt > 0)
		{
			playerCt--;

			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (IsExit(grid, x, y))
				return visited[y][x];

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (CanGo(grid, nx, ny) && !visited[ny][nx])
				{
					grid[y][x] = '.';
					grid[ny][nx] = '@';
					q.push({ nx, ny });
					visited[ny][nx] = visited[y][x] + 1;
					addedPlayer++;
				}
			}
		}
		playerCt = addedPlayer;
	}
	return -1;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--)
	{
		int w, h;
		cin >> w >> h;

		vector<vector<char>> grid(h, vector<char>(w, '\0'));
		int playerX = 0, playerY = 0;
		vector<pair<int, int>> firePos;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> grid[i][j];

				if (grid[i][j] == '@')
					playerX = j, playerY = i;

				else if (grid[i][j] == '*')
					firePos.push_back({ j, i });
			}
		}
		int duration = BFS(grid, playerX, playerY, firePos);

		if (duration == -1)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << duration << '\n';
	}
	return 0;
}