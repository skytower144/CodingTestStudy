#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<int>> grid(100, vector<int>(100, 0));

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		y = 100 - (y + 10);

		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				int nx = x + k;
				int ny = y + j;

				if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100)
					continue;

				grid[y + j][x + k] = 1;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
			answer += grid[i][j];
	}
	cout << answer;

	return 0;
}