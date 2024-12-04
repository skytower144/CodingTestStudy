#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<pair<int, int>> people;

		for (int i = 0; i < n; i++)
		{
			int resume, interview;
			cin >> resume >> interview;

			people.push_back({ resume, interview });
		}

		sort(people.begin(), people.end());
		int ct = people.size();

		vector<pair<int, int>> stack;
		stack.push_back(people[0]);

		for (int i = 1; i < ct; i++)
		{
			if (stack.back().second < people[i].second)
				continue;

			stack.push_back(people[i]);
		}

		cout << stack.size() << '\n';
	}
	
	return 0;
}