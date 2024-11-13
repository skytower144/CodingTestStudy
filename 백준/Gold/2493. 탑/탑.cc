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

	vector<int> towers(n);
	vector<int> stack;
	vector<int> answers(n, 0);

	for (int i = 0; i < n; i++)
		cin >> towers[i];

	for (int i = 0; i < n; i++)
	{
		int towerHeight = towers[i];

		while (!stack.empty() && towers[stack.back()] < towerHeight)
			stack.pop_back();

		int receivingTower = stack.empty() ? 0 : stack.back() + 1;
		answers[i] = receivingTower;
		stack.push_back(i);
	}
	for (int i = 0; i < n; i++)
		cout << answers[i] << " ";

	return 0;
}