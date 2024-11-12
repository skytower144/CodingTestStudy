#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = -1;
vector<pair<int, int>> verticies;

int GetArea(vector<int>& indexes)
{
	int side1 = -1;
	int side2 = -1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			int x1 = verticies[indexes[i]].first;
			int x2 = verticies[indexes[j]].first;
			int y1 = verticies[indexes[i]].second;
			int y2 = verticies[indexes[j]].second;

			if (side1 < 0 && x1 == x2)
				side1 = abs(y1 - y2);

			if (side2 < 0 && y1 == y2)
				side2 = abs(x1 - x2);

			if (side1 >= 0 && side2 >= 0)
				return { side1 * side2 };
		}
	}
	return 0;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int x, y;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		verticies.push_back({ x, y });
	}
	vector<int> indexes(3, 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				indexes[0] = i;
				indexes[1] = j;
				indexes[2] = k;
				answer = max(answer, GetArea(indexes));
			}
		}
	}
	cout << answer;
	return 0;
}