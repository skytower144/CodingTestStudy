#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<int, int>> towers(n);
	vector<pair<int, int>> stack;
	vector<int> answers(n, 0);

	for (int i = 0; i < n; i++)
	{
		int towerHeight;
		cin >> towerHeight;

		towers[i] = { towerHeight, i };
	}

	for (int i = 0; i < n; i++)
	{
		int towerHeight = towers[i].first;

		while (!stack.empty() && stack.back().first < towerHeight)
			stack.pop_back();

		int receivingTower = stack.empty() ? 0 : stack.back().second + 1;
		answers[i] = receivingTower;
		stack.push_back({ towerHeight, i });
	}
	for (int i = 0; i < n; i++)
		cout << answers[i] << " ";

	return 0;
}