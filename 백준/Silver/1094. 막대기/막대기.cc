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

	int x;
	cin >> x;

	vector<int> stack;
	stack.push_back(64);

	int sum = 64;

	while (!stack.empty())
	{
		if (sum == x)
			break;

		int popped = stack.back();
		stack.pop_back();

		stack.push_back(popped / 2);
		stack.push_back(popped / 2);

		if (sum - popped / 2 >= x)
		{
			stack.pop_back();
			sum -= popped / 2;
		}
	}
	cout << stack.size();
	return 0;
}