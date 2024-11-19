#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool CheckFullContamination(int n, int m, vector<vector<int>>& grid)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 0)
				return false;
		}
	}
	return true;
}

bool CanGo(int n, int m, int x, int y, vector<vector<int>>& grid)
{
	if (x < 0 || x >= m || y < 0 || y >= n)
		return false;

	if (grid[y][x])
		return false;

	return true;
}

struct Mold
{
	int x;
	int y;
	bool isEvenTurn;
};

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int>> evenGrid(n, vector<int>(m, 0));
	vector<vector<int>> oddGrid(n, vector<int>(m, 0));
	queue<Mold> q;

	int dx[] = { -1, 1, -1, 1 };
	int dy[] = { -1, -1, 1, 1 };
	int x, y;

	while (k--)
	{
		cin >> x >> y;

		evenGrid[y - 1][x - 1] = 1;
		q.push({ x - 1, y - 1, true});
	}

	while (!q.empty())
	{
		x = q.front().x;
		y = q.front().y;

		bool isEvenTurn = q.front().isEvenTurn;
		vector<vector<int>>& currentGrid = isEvenTurn ? oddGrid : evenGrid;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!CanGo(n, m, nx, ny, currentGrid))
				continue;

			currentGrid[ny][nx] = 1;
			q.push({ nx, ny, !isEvenTurn});
		}
	}
	bool isFullyContaminated = CheckFullContamination(n, m, evenGrid);
	isFullyContaminated |= CheckFullContamination(n, m, oddGrid);

	if (isFullyContaminated)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}