#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> students(6, vector<int>(2, 0));
	int s, y;

	for (int i = 0; i < n; i++)
	{
		cin >> s >> y;
		students[y - 1][s]++;
	}

	int answer = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			answer += students[i][j] / 2;

			if (students[i][j] % 2)
				answer++;
		}
	}
	cout << answer;
	return 0;
}